//
//  canny.h
//  Canny Edge Detector
//

#ifndef _CANNY_
#define _CANNY_
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>



class canny {
private:
    cv::Mat img; //Original Image
    cv::Mat grayscaled; // Grayscale
    cv::Mat gFiltered; // Gradient
    cv::Mat sFiltered; //Sobel Filtered
    cv::Mat angles; //Angle Map
    cv::Mat non; // Non-maxima supp.
    cv::Mat thres; //Double threshold and final
public:

    canny(std::string); //Constructor
	cv::Mat toGrayScale();
	std::vector<std::vector<double> > createFilter(int, int, double); //Creates a gaussian filter
	cv::Mat useFilter(cv::Mat, std::vector<std::vector<double> >); //Use some filter
    cv::Mat sobel(); //Sobel filtering
    cv::Mat nonMaxSupp(); //Non-maxima supp.
    cv::Mat threshold(cv::Mat, int, int); //Double threshold and finalize picture
};

#endif
