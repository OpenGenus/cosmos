#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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

int main(int argc, char* argv[])
{
// Default parameters
    std::vector<std::string> img_names;
    double scale = 1;
    std::string features_type = "orb";    //"surf" or "orb" features type
    float match_conf = 0.3f;
    float conf_thresh = 1.f;
    std::string adjuster_method = "ray";    //"reproj" or "ray" adjuster method
    bool do_wave_correct = true;
    cv::detail::WaveCorrectKind wave_correct_type = cv::detail::WAVE_CORRECT_HORIZ;
    std::string warp_type = "spherical";
    int expos_comp_type = cv::detail::ExposureCompensator::GAIN_BLOCKS;
    std::string seam_find_type = "gc_color";

    float blend_strength = 5;
    int blend_type = cv::detail::Blender::MULTI_BAND;
    std::string result_name = "img/panorama_result.jpg";
    double start_time = cv::getTickCount();
    // 1-Input images
    if (argc > 1)
        for (int i = 1; i < argc; i++)
            img_names.push_back(argv[i]);
    else
    {
        img_names.push_back("./panorama1.jpg");
        img_names.push_back("./panorama2.jpg");
    }
    // Check if have enough images
    int num_images = static_cast<int>(img_names.size());
    if (num_images < 2)
    {
        std::cout << "Need more images" << std::endl; return -1;
    }
    // 2- Resize images and find features steps
    std::cout << "Finding features..." << std::endl;
    double t = cv::getTickCount();
    cv::Ptr<cv::detail::FeaturesFinder> finder;
    if (features_type == "surf")
        finder = cv::makePtr<cv::detail::SurfFeaturesFinder>();
    else if (features_type == "orb")
        finder = cv::makePtr<cv::detail::OrbFeaturesFinder>();
    else
    {
        std::cout << "Unknown 2D features type: '" << features_type << std::endl; return -1;
    }

    cv::Mat full_img, img;
    std::vector<cv::detail::ImageFeatures> features(num_images);
    std::vector<cv::Mat> images(num_images);

    std::vector<cv::Size> full_img_sizes(num_images);
    for (int i = 0; i < num_images; ++i)
    {
        full_img = cv::imread(img_names[i]);
        full_img_sizes[i] = full_img.size();
        if (full_img.empty())
        {
            std::cout << "Can't open image " << img_names[i] << std::endl; return -1;
        }
        resize(full_img, img, cv::Size(), scale, scale);
        images[i] = img.clone();
        (*finder)(img, features[i]);
        features[i].img_idx = i;
        std::cout << "Features in image #" << i + 1 << " are : " << features[i].keypoints.size() <<
            std::endl;
    }
    finder->collectGarbage();
    full_img.release();
    img.release();
    std::cout << "Finding features, time: " <<
    ((cv::getTickCount() - t) / cv::getTickFrequency()) << " sec" << std::endl;
    // 3- cv::Match features
    std::cout << "Pairwise matching" << std::endl;
    t = cv::getTickCount();
    std::vector<cv::detail::MatchesInfo> pairwise_matches;
    BestOf2Nearestcv::Matcher matcher(false, match_conf);
    matcher(features, pairwise_matches);
    matcher.collectGarbage();
    std::cout << "Pairwise matching, time: " <<
    ((cv::getTickCount() - t) / cv::getTickFrequency()) << " sec" << std::endl;
    // 4- Select images and matches subset to build panorama
    std::vector<int> indices = leaveBiggestComponent(features, pairwise_matches, conf_thresh);
    std::vector<cv::Mat> img_subset;
    std::vector<std::string> img_names_subset;
    std::vector<cv::Size> full_img_sizes_subset;

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
    std::cout << "0\n";
    std::vector<CameraParams> cameras;
    estimator(features, pairwise_matches, cameras);
    // // if (!estimator(features, pairwise_matches, cameras))
    // //       {std::cout <<"Homography estimation failed." << std::endl; return -1; }
    std::cout << "1\n";
    for (size_t i = 0; i < cameras.size(); ++i)
    {
        cv::Mat R;
        std::cout << "2\n";
        cameras[i].R.convertTo(R, CV_32F);
        cameras[i].R = R;
        std::cout << "Initial intrinsic #" << indices[i] + 1 << ":\n" << cameras[i].K() <<
            std::endl;
    }
    // 5- Refine camera parameters globally
    cv::Ptr<BundleAdjusterBase> adjuster;
    if (adjuster_method == "reproj")
        // "reproj" method
        adjuster = cv::makePtr<BundleAdjusterReproj>();
    else     // "ray" method
        adjuster = cv::makePtr<BundleAdjusterRay>();
    adjuster->setConfThresh(conf_thresh);
    if (!(*adjuster)(features, pairwise_matches, cameras))
    {
        std::cout << "Camera parameters adjusting failed." << std::endl; return -1;
    }
    // Find median focal length
    std::vector<double> focals;


    for (size_t i = 0; i < cameras.size(); ++i)
    {
        std::cout << "Camera #" << indices[i] + 1 << ":\n" << cameras[i].K() << std::endl;
        focals.push_back(cameras[i].focal);
    }
    sort(focals.begin(), focals.end());
    float warped_image_scale;
    if (focals.size() % 2 == 1)
        warped_image_scale = static_cast<float>(focals[focals.size() / 2]);
    else
        warped_image_scale =
            static_cast<float>(focals[focals.size() / 2 - 1] + focals[focals.size() / 2]) * 0.5f;
    // 6- Wave correlation (optional)
    if (do_wave_correct)
    {
        std::vector<cv::Mat> rmats;
        for (size_t i = 0; i < cameras.size(); ++i)
            rmats.push_back(cameras[i].R.clone());
        waveCorrect(rmats, wave_correct_type);
        for (size_t i = 0; i < cameras.size(); ++i)
            cameras[i].R = rmats[i];
    }
    // 7- Warp images
    std::cout << "Warping images (auxiliary)... " << std::endl;
    t = cv::getTickCount();
    std::vector<Point> corners(num_images);
    std::vector<Ucv::Mat> masks_warped(num_images);
    std::vector<Ucv::Mat> images_warped(num_images);
    std::vector<cv::Size> sizes(num_images);
    std::vector<Ucv::Mat> masks(num_images);
    // Prepare images masks
    for (int i = 0; i < num_images; ++i)
    {
        masks[i].create(images[i].size(), CV_8U);
        masks[i].setTo(cv::Scalar::all(255));
    }
    // Map projections
    cv::Ptr<WarperCreator> warper_creator;
    if (warp_type == "rectilinear")
        warper_creator = cv::makePtr<cv::CompressedRectilinearWarper>(2.0f, 1.0f);
    else if (warp_type == "cylindrical")
        warper_creator = cv::makePtr<cv::CylindricalWarper>();
    else if (warp_type == "spherical")
        warper_creator = cv::makePtr<cv::SphericalWarper>();
    else if (warp_type == "stereographic")
        warper_creator = cv::makePtr<cv::StereographicWarper>();
    else if (warp_type == "panini")
        warper_creator = cv::makePtr<cv::PaniniWarper>(2.0f, 1.0f);

    if (!warper_creator)
    {
        std::cout << "Can't create the following warper" << warp_type << std::endl; return 1;
    }
    cv::Ptr<RotationWarper> warper =
        warper_creator->create(static_cast<float>(warped_image_scale * scale));

    for (int i = 0; i < num_images; ++i)
    {
        cv::Mat_<float> K;
        cameras[i].K().convertTo(K, CV_32F);
        float swa = (float)scale;
        K(0, 0) *= swa; K(0, 2) *= swa;
        K(1, 1) *= swa; K(1, 2) *= swa;
        corners[i] = warper->warp(images[i], K, cameras[i].R, INTER_LINEAR, BORDER_REFLECT,
                                  images_warped[i]);

        sizes[i] = images_warped[i].size();
        warper->warp(masks[i], K, cameras[i].R, cv::INTER_NEAREST, cv::BORDER_CONSTANT,
                     masks_warped[i]);
    }
    std::vector<Ucv::Mat> images_warped_f(num_images);

    for (int i = 0; i < num_images; ++i)
        images_warped[i].convertTo(images_warped_f[i], CV_32F);

    std::cout << "Warping images, time: " << ((cv::getTickCount() - t) / cv::getTickFrequency()) <<
        " sec" << std::endl;
    // 8- Compensate exposure errors
    cv::Ptr<Ecv::detail::xposureCompensator> compensatcv::detail::or =
        ExposureCompensator::createDefault(expos_comp_type);
    compensator->feed(corners, images_warped, masks_warped);
    // 9- Find seam masks
    cv::Ptr<SeamFinder> seam_finder;
    if (seam_find_type == "no")
        seam_finder = cv::makePtr<NoSeamFinder>();
    else if (seam_find_type == "voronoi")
        seam_finder = cv::makePtr<VoronoiSeamFinder>();
    else if (seam_find_type == "gc_color")
        seam_finder = cv::makePtr<GraphCutSeamFinder>(GraphCutSeamFinderBase::COST_COLOR);
    else if (seam_find_type == "gc_colorgrad")
        seam_finder = cv::makePtr<GraphCutSeamFinder>(GraphCutSeamFinderBase::COST_COLOR_GRAD);
    else if (seam_find_type == "dp_color")
        seam_finder = cv::makePtr<DpSeamFinder>(DpSeamFinder::COLOR);
    else if (seam_find_type == "dp_colorgrad")
        seam_finder = cv::makePtr<DpSeamFinder>(DpSeamFinder::COLOR_GRAD);
    if (!seam_finder)
    {
        std::cout << "Can't create the following seam finder" << seam_find_type << std::endl;
        return 1;
    }


    seam_finder->find(images_warped_f, corners, masks_warped);
    // Release unused memory
    images.clear();
    images_warped.clear();
    images_warped_f.clear();
    masks.clear();
    // 10- Create a blender
    cv::Ptr<cv::detail::Blender> blender = cv::detail::Blender::createDefault(blend_type, false);
    cv::Size dst_sz = resultRoi(corners, sizes).size();
    float blend_width = sqrt(static_cast<float>(dst_sz.area())) * blend_strength / 100.f;

    if (blend_width < 1.f)
        blender = cv::detail::Blender::createDefault(cv::detail::Blender::NO, false);
    else if (blend_type == cv::detail::Blender::MULTI_BAND)
    {
        MultiBandcv::detail::Blender* mb =
            dynamic_cast<MultiBandcv::detail::Blender*>(blender.get());
        mb->setNumBands(static_cast<int>(ceil(log(blend_width) / log(2.)) - 1.));
        std::cout << "Multi-band blender, number of bands: " << mb->numBands() << std::endl;
    }
    else if (blend_type == cv::detail::Blender::FEATHER)
    {
        Feathercv::detail::Blender* fb = dynamic_cast<Feathercv::detail::Blender*>(blender.get());
        fb->setSharpness(1.f / blend_width);
        std::cout << "Feather blender, sharpness: " << fb->sharpness() << std::endl;
    }
    blender->prepare(corners, sizes);
    // 11- Compositing step
    std::cout << "Compositing..." << std::endl;
    t = cv::getTickCount();
    cv::Mat img_warped, img_warped_s;



    cv::Mat dilated_mask, seam_mask, mask, mask_warped;
    for (int img_idx = 0; img_idx < num_images; ++img_idx)
    {
        std::cout << "Compositing image #" << indices[img_idx] + 1 << std::endl;
        // 11.1- Read image and resize it if necessary
        full_img = cv::imread(img_names[img_idx]);
        if (abs(scale - 1) > 1e-1)
            resize(full_img, img, cv::Size(), scale, scale);
        else
            img = full_img;
        full_img.release();
        cv::Size img_size = img.size();
        cv::Mat K;
        cameras[img_idx].K().convertTo(K, CV_32F);
        // 11.2- Warp the current image
        warper->warp(img, K, cameras[img_idx].R, INTER_LINEAR, BORDER_REFLECT, img_warped);
        // Warp the current image mask
        mask.create(img_size, CV_8U);
        mask.setTo(cv::Scalar::all(255));
        warper->warp(mask, K, cameras[img_idx].R, cv::INTER_NEAREST, cv::BORDER_CONSTANT,
                     mask_warped);
        // 11.3- Compensate exposure error step
        compensator->apply(img_idx, corners[img_idx], img_warped, mask_warped);
        img_warped.convertTo(img_warped_s, CV_16S);
        img_warped.release();
        img.release();
        mask.release();
        dilate(masks_warped[img_idx], dilated_mask, cv::Mat());
        resize(dilated_mask, seam_mask, mask_warped.size());


        mask_warped = seam_mask & mask_warped;
        // 11.4- Blending images step
        blender->feed(img_warped_s, mask_warped, corners[img_idx]);
    }
    cv::Mat result, result_mask;
    blender->blend(result, result_mask);
    std::cout << "Compositing, time: " << ((cv::getTickCount() - t) / cv::getTickFrequency()) <<
        " sec" << std::endl;
    imwrite(result_name, result);
    // imshow(result_name,result);
    // waitKey(8000);
    std::cout << "Finished, total time: " <<
    ((cv::getTickCount() - start_time) / cv::getTickFrequency()) << " sec" << std::endl;
    return 0;
}
