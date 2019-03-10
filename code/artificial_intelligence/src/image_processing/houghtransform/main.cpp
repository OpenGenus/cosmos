#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/types_c.h>
#include <math.h>
#include <stdlib.h>

#define WINDOW_NAME                     "Hough Transformation"
#define THETA_GRANULARITY               (4 * 100)
#define RHO_GRANULARITY                 1

IplImage                *img_read;
IplImage                *img_edges;
IplImage                *img_sine;
int                             *img_sine_arr;
int threshold;

CvSize img_attrib_dim;
CvSize img_attrib_sine;
int max_rho;

/*****************************************************************
* create and destroy gui items
*****************************************************************/
void create_gui()
{
    cvNamedWindow(WINDOW_NAME);

    max_rho = sqrt(
        img_attrib_dim.width * img_attrib_dim.width + img_attrib_dim.height *
        img_attrib_dim.height);

    printf("Image diagonal size (max rho): %d\n", max_rho);
    img_attrib_sine.width = THETA_GRANULARITY;
    img_attrib_sine.height = RHO_GRANULARITY * max_rho * 2;

    img_sine_arr = (int *)malloc(img_attrib_sine.width * img_attrib_sine.height * sizeof(int));
    img_edges = cvCreateImage(img_attrib_dim, IPL_DEPTH_8U, 1);
    img_sine = cvCreateImage(img_attrib_sine, IPL_DEPTH_8U, 1);
    cvZero(img_sine);
}

void destroy_gui()
{
    cvDestroyWindow(WINDOW_NAME);
    cvReleaseImage(&img_read);
    cvReleaseImage(&img_edges);
    cvReleaseImage(&img_sine);
}

/*****************************************************************
* display a message and wait for escape key to continue
*****************************************************************/
void disp_msg(const char *msg)
{
    printf("%s. Press escape to continue.\n", msg);
    char c;
    do
        c = cvWaitKey(500);
    while (27 != c);
}

/*****************************************************************
* main.
* 1. read image
* 2. detect edges
* 3. hough transform to detect lines
*****************************************************************/
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <image> <threshold>\n", argv[0]);
        return 1;
    }

    img_read = cvLoadImage(argv[1]);
    if (NULL == img_read)
    {
        printf("Error loading image %s\n", argv[1]);
        return -1;
    }
    img_attrib_dim = cvGetSize(img_read);
    threshold = atoi(argv[2]);

    create_gui();

    cvShowImage(WINDOW_NAME, img_read);
    printf("Original image size: %d x %d\n", img_attrib_dim.width, img_attrib_dim.height);
    disp_msg("This is the original image");

    // detect edges
    cvCvtColor(img_read, img_edges, CV_BGR2GRAY);
    cvLaplace(img_edges, img_edges, 3);
    cvThreshold(img_edges, img_edges, 200, 255, CV_THRESH_BINARY);
    cvShowImage(WINDOW_NAME, img_edges);
    disp_msg("This is the edge detected image");
    printf("working...\n");

    // for each pixel in the edge
    int max_dest = 0;
    int min_dest = INT_MAX;
    for (int y = 0; y < img_edges->height; y++)
    {
        uchar *row_ptr = (uchar*) (img_edges->imageData + y * img_edges->widthStep);
        for (int x = 0; x < img_edges->width; x++)
        {
            if (*(row_ptr + x) > 0)
                for (int theta_div = 0; theta_div < THETA_GRANULARITY; theta_div++)
                {
                    double theta = (CV_PI * theta_div / THETA_GRANULARITY) - (CV_PI / 2);
                    int rho = (int)round(cos(theta) * x + sin(theta) * y + max_rho);
                    int *dest = img_sine_arr + rho * img_attrib_sine.width + theta_div;
                    int d_val = *dest = *dest + 1;
                    if (d_val > max_dest)
                        max_dest = d_val;
                    if (d_val < min_dest)
                        min_dest = d_val;
                }
        }
    }

    // scale the intensity for contrast
    float div = ((float)max_dest) / 255;
    printf("max_dest: %d, min_dest: %d, scale: %f\n", max_dest, min_dest, div);
    for (int y = 0; y < img_sine->height; y++)
    {
        uchar *row_ptr = (uchar*) (img_sine->imageData + y * img_sine->widthStep);
        for (int x = 0; x < img_sine->width; x++)
        {
            int val = (*((img_sine_arr + y * img_attrib_sine.width) + x)) / div;
            if (val < 0)
                val = 0;
            *(row_ptr + x) = val;
        }
    }

    // find rho and theta at maximum positions (within the threshold)
    int possible_edge = round((float)max_dest / div) - threshold;
    printf("possible edges beyond %d\n", possible_edge);
    for (int y = 0; y < img_sine->height; y++)
    {
        uchar *row_ptr = (uchar*) (img_sine->imageData + y * img_sine->widthStep);
        for (int x = 0; x < img_sine->width; x++)
        {
            int val = *(row_ptr + x);
            if (possible_edge <= val)
            {
                float theta_rad = (CV_PI * x / THETA_GRANULARITY) - (CV_PI / 2);
                float theta_deg = theta_rad * 180 / CV_PI;
                printf("val: %d at rho %d, theta %f (%f degrees)\n", val, y - max_rho, theta_rad,
                       theta_deg);
            }
        }
    }

    // display the plotted intensity graph of the hough space
    cvShowImage(WINDOW_NAME, img_sine);
    disp_msg("this is the hough space image");

    destroy_gui();
    return 0;
}
