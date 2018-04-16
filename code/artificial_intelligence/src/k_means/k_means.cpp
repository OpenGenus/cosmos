/*
 *  Kmeans written in C++ for use on Images.
 *  Requires several data structures from the user context
 *
 *  The Image is represented by ByteImage
 *  A point datastructure must exist with values, x, y, I (value from 0 to 255)
 *
 *  main not included. pulled out of a larger project. Please add one, refine out ByteImage should be simple. :)
 *
 */
#include <iostream> // Used for debugging & learning code
#include <algorithm> // Use for sorting
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>

#define PI 4 * atan(1.0)

// Point structure
struct point
{
    int x;
    int y;
    int I;
    int radx;
    int rady;
    int area;
    double avg;
    double r;
};

// Kmeans with weight option
template<typename ByteImage, typename byte>
double kmeans(ByteImage& bimg, const int K, double weight)
{

    // Create k random points (centers)
    point * centers = new point[K];

    // Totals for updating
    point * totals = new point[K];

    // Initialize k points
    for (int k = 0; k < K; k++)
    {
        // Initiate centers
        centers[k].x = rand() % bimg.nr;
        centers[k].y = rand() % bimg.nc;
        centers[k].I = rand() % 256;

        // Initiate sumation for average
        totals[k].x = 0;
        totals[k].y = 0;
        totals[k].I = 0;
        totals[k].area = 0;
    }
    // Create label map
    byte * label = new byte[bimg.nr * bimg.nc];
    double shortestDistance, presentDistance;
    double error = bimg.nr * bimg.nr + bimg.nc * bimg.nc + 255 * 255, old_error;

    // Weights maybe? Set these to one for original kmeans.
    double wi = 1, wj = 1;     //255.0*255/(double)bimg.nr/bimg.nr, wj = 255.0*255/(double)bimg.nc/bimg.nc;
    int closestK = 0;

    do {

        // Update previous error
        old_error = error;
        error = 0;
        // A. For each point in space, find distance to each center, assign to min center (map colors)
        for (int i = 0; i < bimg.nr; i++)
            for (int j = 0; j < bimg.nc; j++)
            {
                // Initialize shortestDistance to max possible.
                shortestDistance = sqrt(bimg.nr * bimg.nr + bimg.nc * bimg.nc + 255 * 255);
                // Check distance to each center
                for (int k = 0; k < K; k++)
                {
                    // Calculate the distance
                    presentDistance = sqrt((double)wi * (centers[k].x - i) * (centers[k].x - i) +
                                           (double)wj * (centers[k].y - j) * (centers[k].y - j) +
                                           (double)weight *
                                           (centers[k].I - bimg.image[i * bimg.nc + j]) *
                                           (centers[k].I - bimg.image[i * bimg.nc + j]));

                    // Update shortest distance
                    if (presentDistance < shortestDistance)
                    {
                        shortestDistance = presentDistance;
                        closestK = k;
                        label[i * bimg.nc + j] = (255.0 / K) * k;
                    }
                }

                // Update error
                error += shortestDistance;

                // Update totals to compute new centroid
                totals[closestK].x += i;
                totals[closestK].y += j;
                totals[closestK].I += bimg.image[i * bimg.nc + j];
                totals[closestK].area += 1;
            }
        error = error / bimg.nr / bimg.nc;
        // Update centers
        for (int k = 0; k < K; k++)
        {
            // Compute new centers
            if (totals[k].area > 0)
            {
                centers[k].x = totals[k].x / totals[k].area;
                centers[k].y = totals[k].y / totals[k].area;
                centers[k].I = totals[k].I / totals[k].area;
            }

            // Reset totals
            totals[k].x = 0;
            totals[k].y = 0;
            totals[k].I = 0;
            totals[k].area = 0;
        }

        // B. Repeat A until centers do not move
    } while (error != old_error);

    // Extra credit code to find and "average" distance between the nodes, which must be less than user input
    std::cout << "K=" << K << std::endl;

    // Make label image
    bimg.image = label;
    delete [] totals;
    delete [] centers;

    std::cout << shortestDistance << std::endl;
    return shortestDistance;
}
