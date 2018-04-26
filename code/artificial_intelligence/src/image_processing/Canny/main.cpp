//
//  main.cpp
//  Canny Edge Detector
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "canny.h"

using namespace cv;
using namespace std;

int main()
{
    cv::String filePath = "lena.jpg"; //Filepath of input image
    canny cny(filePath);
        
    return 0;
}

