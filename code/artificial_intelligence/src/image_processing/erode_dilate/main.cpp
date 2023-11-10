#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "highgui.h"
#include <stdlib.h>
#include <stdio.h>

/// Global variables
cv::Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

/** Function Headers */
void Erosion( int, void* );
void Dilation( int, void* );

/** @function main */
int main( int argc, char** argv )
{
    /// Load an image
    src = cv::imread( argv[1] );

    if (!src.data)
        return -1;
    /// Create windows
    cv::namedWindow( "Erosion Demo", CV_WINDOW_AUTOSIZE );
    cv::namedWindow( "Dilation Demo", CV_WINDOW_AUTOSIZE );
    cvMoveWindow( "Dilation Demo", src.cols, 0 );

    /// Create Erosion Trackbar
    cv::createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
                        &erosion_elem, max_elem,
                        Erosion );

    cv::createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
                        &erosion_size, max_kernel_size,
                        Erosion );

    /// Create Dilation Trackbar
    cv::createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
                        &dilation_elem, max_elem,
                        Dilation );

    cv::createTrackbar( "Kernel size:\n 2n +1", "Dilation Demo",
                        &dilation_size, max_kernel_size,
                        Dilation );

    /// Default start
    Erosion( 0, 0 );
    Dilation( 0, 0 );

    cv::waitKey(0);
    return 0;
}

/**  @function Erosion  */
void Erosion( int, void* )
{
    int erosion_type;
    if (erosion_elem == 0)
        erosion_type = cv::MORPH_RECT;
    else if (erosion_elem == 1)
        erosion_type = cv::MORPH_CROSS;
    else if (erosion_elem == 2)
        erosion_type = cv::MORPH_ELLIPSE;
    cv::Mat element = cv::getStructuringElement( erosion_type,
                                                 cv::Size( 2 * erosion_size + 1,
                                                           2 * erosion_size + 1 ),
                                                 cv::Point( erosion_size, erosion_size ) );

    /// Apply the erosion operation
    cv::erode( src, erosion_dst, element );
    cv::imshow( "Erosion Demo", erosion_dst );
}

/** @function Dilation */
void Dilation( int, void* )
{
    int dilation_type;
    if (dilation_elem == 0)
        dilation_type = cv::MORPH_RECT;
    else if (dilation_elem == 1)
        dilation_type = cv::MORPH_CROSS;
    else if (dilation_elem == 2)
        dilation_type = cv::MORPH_ELLIPSE;
    cv::Mat element = cv::getStructuringElement( dilation_type,
                                                 cv::Size( 2 * dilation_size + 1,
                                                           2 * dilation_size + 1 ),
                                                 cv::Point( dilation_size, dilation_size ) );
    /// Apply the dilation operation
    cv::dilate( src, dilation_dst, element );
    cv::imshow( "Dilation Demo", dilation_dst );
}
