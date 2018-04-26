#include <iostream>
#include <string>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/stitching/detail/blenders.hpp>
#include <opencv2/stitching/detail/camera.hpp>
#include <opencv2/stitching/detail/exposure_compensate.hpp>
#include <opencv2/stitching/detail/matchers.hpp>
#include <opencv2/stitching/detail/motion_estimators.hpp>
#include <opencv2/stitching/detail/seam_finders.hpp>
#include <opencv2/stitching/detail/util.hpp>
#include <opencv2/stitching/detail/warpers.hpp>
#include <opencv2/stitching/warpers.hpp>

using namespace std;
using namespace cv;
using namespace cv::detail;
int main(int argc, char* argv[])
{
// Default parameters
	vector<String> img_names;
	double scale = 1;
	string features_type = "orb";//"surf" or "orb" features type
	float match_conf = 0.3f;
	float conf_thresh = 1.f;
	string adjuster_method = "ray";//"reproj" or "ray" adjuster method
	bool do_wave_correct = true;
	WaveCorrectKind wave_correct_type = WAVE_CORRECT_HORIZ;
	string warp_type = "spherical";
	int expos_comp_type = ExposureCompensator::GAIN_BLOCKS;
	string seam_find_type = "gc_color";

	float blend_strength = 5;
	int blend_type = Blender::MULTI_BAND;
	string result_name = "img/panorama_result.jpg";
	double start_time = getTickCount();
	// 1-Input images
	if(argc > 1)
	{
		for(int i=1; i < argc; i++)
			img_names.push_back(argv[i]);
	}
	else
	{
		img_names.push_back("./panorama1.jpg");
		img_names.push_back("./panorama2.jpg");
	}
	// Check if have enough images
	int num_images = static_cast<int>(img_names.size());
	if (num_images < 2) {cout << "Need more images" << endl; return -1; }
	// 2- Resize images and find features steps
	cout << "Finding features..." << endl;
	double t = getTickCount();
	Ptr<FeaturesFinder> finder;
	if (features_type == "surf")
		finder = makePtr<SurfFeaturesFinder>();
	else if (features_type == "orb")
		finder = makePtr<OrbFeaturesFinder>();
	else 
		{cout << "Unknown 2D features type: '" << features_type <<	endl; return -1; }
	
	Mat full_img, img;
	vector<ImageFeatures> features(num_images);
	vector<Mat> images(num_images);

	vector<Size> full_img_sizes(num_images);
	for (int i = 0; i < num_images; ++i)
	{
		full_img = imread(img_names[i]);
		full_img_sizes[i] = full_img.size();
		if (full_img.empty()) 
			{cout << "Can't open image " << img_names[i] << endl; return -1; }
		resize(full_img, img, Size(), scale, scale);
		images[i] = img.clone();
		(*finder)(img, features[i]);
		features[i].img_idx = i;
		cout << "Features in image #" << i+1 << " are : " <<features[i].keypoints.size() << endl;
	}
	finder->collectGarbage();
	full_img.release();
	img.release();
	cout << "Finding features, time: " << ((getTickCount() - t) /getTickFrequency()) << " sec" << endl;
	// 3- Match features
	cout << "Pairwise matching" << endl;
	t = getTickCount();
	vector<MatchesInfo> pairwise_matches;
	BestOf2NearestMatcher matcher(false, match_conf);
	matcher(features, pairwise_matches);
	matcher.collectGarbage();
	cout << "Pairwise matching, time: " << ((getTickCount() - t) /getTickFrequency()) << " sec" << endl;
	// 4- Select images and matches subset to build panorama
	vector<int> indices = leaveBiggestComponent(features, pairwise_matches, conf_thresh);
	vector<Mat> img_subset;
	vector<String> img_names_subset;
	vector<Size> full_img_sizes_subset;

	for (size_t i = 0; i < indices.size(); ++i)
	{
		img_names_subset.push_back(img_names[indices[i]]);
		img_subset.push_back(images[indices[i]]);
		full_img_sizes_subset.push_back(full_img_sizes[indices[i]]);
	}

	images = img_subset;
	img_names = img_names_subset;
	full_img_sizes = full_img_sizes_subset;
	// Estimate camera parameters rough
	HomographyBasedEstimator estimator;
	cout<<"0\n";
	vector<CameraParams> cameras;
	estimator(features, pairwise_matches, cameras);
	// // if (!estimator(features, pairwise_matches, cameras))
	// // 	{cout <<"Homography estimation failed." << endl; return -1; }
	cout<<"1\n";
	for (size_t i = 0; i < cameras.size(); ++i)
	{
		Mat R;
		cout<<"2\n";
		cameras[i].R.convertTo(R, CV_32F);
		cameras[i].R = R;
		cout << "Initial intrinsic #" << indices[i]+1 << ":\n" <<cameras[i].K() << endl;
	}
	// 5- Refine camera parameters globally
	Ptr<BundleAdjusterBase> adjuster;
	if (adjuster_method == "reproj")
	// "reproj" method
	adjuster = makePtr<BundleAdjusterReproj>();
	else // "ray" method
	adjuster = makePtr<BundleAdjusterRay>();
	adjuster->setConfThresh(conf_thresh);
	if (!(*adjuster)(features, pairwise_matches, cameras)) 
		{cout <<"Camera parameters adjusting failed." << endl; return -1; }
	// Find median focal length
	vector<double> focals;


	for (size_t i = 0; i < cameras.size(); ++i)
	{
		cout << "Camera #" << indices[i]+1 << ":\n" << cameras[i].K()<< endl;
		focals.push_back(cameras[i].focal);
	}
	sort(focals.begin(), focals.end());
	float warped_image_scale;
	if (focals.size() % 2 == 1)
		warped_image_scale = static_cast<float>(focals[focals.size() /2]);
	else
		warped_image_scale = static_cast<float>(focals[focals.size() /2 - 1] + focals[focals.size() / 2]) * 0.5f;
	// 6- Wave correlation (optional)
	if (do_wave_correct)
	{
		vector<Mat> rmats;
		for (size_t i = 0; i < cameras.size(); ++i)
			rmats.push_back(cameras[i].R.clone());
		waveCorrect(rmats, wave_correct_type);
		for (size_t i = 0; i < cameras.size(); ++i)
			cameras[i].R = rmats[i];
	}
	// 7- Warp images
	cout << "Warping images (auxiliary)... " << endl;
	t = getTickCount();
	vector<Point> corners(num_images);
	vector<UMat> masks_warped(num_images);
	vector<UMat> images_warped(num_images);
	vector<Size> sizes(num_images);
	vector<UMat> masks(num_images);
	// Prepare images masks
	for (int i = 0; i < num_images; ++i)
	{
		masks[i].create(images[i].size(), CV_8U);
		masks[i].setTo(Scalar::all(255));
	}
	// Map projections
	Ptr<WarperCreator> warper_creator;
	if (warp_type == "rectilinear")
		warper_creator = makePtr<cv::CompressedRectilinearWarper>(2.0f, 1.0f);
	else if (warp_type == "cylindrical")
		warper_creator = makePtr<cv::CylindricalWarper>();
	else if (warp_type == "spherical")
		warper_creator = makePtr<cv::SphericalWarper>();
	else if (warp_type == "stereographic")
		warper_creator = makePtr<cv::StereographicWarper>();
	else if (warp_type == "panini")
		warper_creator = makePtr<cv::PaniniWarper>(2.0f, 1.0f);

	if (!warper_creator)
	{ 
			cout << "Can't create the following warper" << warp_type << endl; return 1;
	}
	Ptr<RotationWarper> warper = warper_creator->create(static_cast<float>(warped_image_scale * scale));

	for (int i = 0; i < num_images; ++i)
	{
		Mat_<float> K;
		cameras[i].K().convertTo(K, CV_32F);
		float swa = (float)scale;
		K(0,0) *= swa; K(0,2) *= swa;
		K(1,1) *= swa; K(1,2) *= swa;
		corners[i] = warper->warp(images[i], K, cameras[i].R, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);

		sizes[i] = images_warped[i].size();
		warper->warp(masks[i], K, cameras[i].R, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);
	}
	vector<UMat> images_warped_f(num_images);

	for (int i = 0; i < num_images; ++i)
		images_warped[i].convertTo(images_warped_f[i], CV_32F);
	
	cout << "Warping images, time: " << ((getTickCount() - t) /	getTickFrequency()) << " sec" << endl;
	// 8- Compensate exposure errors
	Ptr<ExposureCompensator> compensator = ExposureCompensator::createDefault(expos_comp_type);
	compensator->feed(corners, images_warped, masks_warped);
	// 9- Find seam masks
	Ptr<SeamFinder> seam_finder;
	if (seam_find_type == "no")
		seam_finder = makePtr<NoSeamFinder>();
	else if (seam_find_type == "voronoi")
		seam_finder = makePtr<VoronoiSeamFinder>();
	else if (seam_find_type == "gc_color")
		seam_finder = makePtr<GraphCutSeamFinder>(GraphCutSeamFinderBase::COST_COLOR);
	else if (seam_find_type == "gc_colorgrad")
		seam_finder = makePtr<GraphCutSeamFinder>(GraphCutSeamFinderBase::COST_COLOR_GRAD);
	else if (seam_find_type == "dp_color")
		seam_finder = makePtr<DpSeamFinder>(DpSeamFinder::COLOR);
	else if (seam_find_type == "dp_colorgrad")
		seam_finder = makePtr<DpSeamFinder>(DpSeamFinder::COLOR_GRAD);
	if (!seam_finder)
	{
		cout << "Can't create the following seam finder" << seam_find_type << endl; 
		return 1; 
	}


	seam_finder->find(images_warped_f, corners, masks_warped);
	// Release unused memory
	images.clear();
	images_warped.clear();
	images_warped_f.clear();
	masks.clear();
	// 10- Create a blender
	Ptr<Blender> blender = Blender::createDefault(blend_type, false);
	Size dst_sz = resultRoi(corners, sizes).size();
	float blend_width = sqrt(static_cast<float>(dst_sz.area())) *blend_strength / 100.f;

	if (blend_width < 1.f)
		blender = Blender::createDefault(Blender::NO, false);
	else if (blend_type == Blender::MULTI_BAND)
	{
		MultiBandBlender* mb = dynamic_cast<MultiBandBlender*>(blender.get());
		mb->setNumBands(static_cast<int>(ceil(log(blend_width)/	log(2.)) - 1.));
		cout << "Multi-band blender, number of bands: " << mb->numBands() << endl;
	}
	else if (blend_type == Blender::FEATHER)
	{
		FeatherBlender* fb = dynamic_cast<FeatherBlender*>(blender.get());
		fb->setSharpness(1.f/blend_width);
		cout << "Feather blender, sharpness: " << fb->sharpness() <<	endl;
	}
	blender->prepare(corners, sizes);
	// 11- Compositing step
	cout << "Compositing..." << endl;
	t = getTickCount();
	Mat img_warped, img_warped_s;



	Mat dilated_mask, seam_mask, mask, mask_warped;
	for (int img_idx = 0; img_idx < num_images; ++img_idx)
	{
		cout << "Compositing image #" << indices[img_idx]+1	<< endl;
		// 11.1- Read image and resize it if necessary
		full_img = imread(img_names[img_idx]);
		if (abs(scale - 1) > 1e-1)
			resize(full_img, img, Size(), scale, scale);
		else
			img = full_img;
		full_img.release();
		Size img_size = img.size();
		Mat K;
		cameras[img_idx].K().convertTo(K, CV_32F);
		// 11.2- Warp the current image
		warper->warp(img, K, cameras[img_idx].R, INTER_LINEAR, BORDER_REFLECT,img_warped);
		// Warp the current image mask
		mask.create(img_size, CV_8U);
		mask.setTo(Scalar::all(255));
		warper->warp(mask, K, cameras[img_idx].R, INTER_NEAREST,BORDER_CONSTANT, mask_warped);
		// 11.3- Compensate exposure error step
		compensator->apply(img_idx, corners[img_idx], img_warped, mask_warped);
		img_warped.convertTo(img_warped_s, CV_16S);
		img_warped.release();
		img.release();
		mask.release();
		dilate(masks_warped[img_idx], dilated_mask, Mat());
		resize(dilated_mask, seam_mask, mask_warped.size());


		mask_warped = seam_mask & mask_warped;
		// 11.4- Blending images step
		blender->feed(img_warped_s, mask_warped, corners[img_idx]);
	}
	Mat result, result_mask;
	blender->blend(result, result_mask);
	cout << "Compositing, time: " << ((getTickCount() - t) /getTickFrequency()) << " sec" << endl;
	imwrite(result_name, result);
	// imshow(result_name,result);
	// waitKey(8000);
	cout << "Finished, total time: " << ((getTickCount() - start_time)/ getTickFrequency()) << " sec" << endl;
	return 0;
}