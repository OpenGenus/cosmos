//
//  main.cpp
//  Canny Edge Detector
//

#include <iostream>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "canny.h"


int main()
{
    std::string filePath = "lena.jpg"; //Filepath of input image
    canny cny(filePath);

    return 0;
}
