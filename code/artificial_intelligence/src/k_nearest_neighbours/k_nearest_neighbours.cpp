// Part of Cosmos by OpenGenus
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
    float w, x, y, z; // w, x, y and z are the values of the dataset
    float distance;   // distance will store the distance of dataset point from
                      // the unknown test point
    int op;           // op will store the class of the point
};

int main() {
    int n, k;
    Point p;
    std::cout << "Number of data points: ";
    std::cin >> n;
    std::vector<Point> vec;
    std::cout << "\nEnter the dataset values: \n";
    std::cout << "w\tx\ty\tz\top\n";

    // Taking dataset
    for (int i = 0; i < n; ++i) {
        float wCoordinate, xCoordinate, yCoordinate, zCoordinate;
        int opCoordinate;
        std::cin >> wCoordinate >> xCoordinate >> yCoordinate >> zCoordinate >>
            opCoordinate;
        vec.push_back(Point());
        vec[i].w = wCoordinate;
        vec[i].x = xCoordinate;
        vec[i].y = yCoordinate;
        vec[i].z = zCoordinate;
        vec[i].op = opCoordinate;
    }

    std::cout << "\nw\tx\ty\tz\top\n";

    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << vec[i].w << '\t'
                  << vec[i].x << '\t' << vec[i].y << '\t' << vec[i].z << '\t'
                  << vec[i].op << '\n';
    }

    std::cout
        << "\nEnter the feature values of the unknown point: \nw\tx\ty\tz\n";
    std::cin >> p.w >> p.x >> p.y >> p.z;

    float euclideanDistance(Point p, Point v);
    for (int i = 0; i < n; ++i) {
        vec[i].distance = euclideanDistance(p, vec[i]);
    }

    // Sorting the training data with respect to distance
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (vec[j].distance > vec[j + 1].distance) {
                Point temp;
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    std::cout << "\nw\tx\ty\tz\top\tdistance\n";
    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << vec[i].w << '\t'
                  << vec[i].x << '\t' << vec[i].y << '\t' << vec[i].z << '\t'
                  << vec[i].op << '\t' << vec[i].distance << '\n';
    }

    // Taking the K nearest neighbors
    std::cout << "\nNumber of nearest neighbors(k): ";
    std::cin >> k;

    int freq[1000] = {0};
    int index = 0, maxfreq = 0;

    // Creating frequency array of the class of k nearest neighbors
    for (int i = 0; i < k; ++i) {
        freq[vec[i].op]++;
    }

    // Finding the most frequent occurring class
    for (int i = 0; i < 1000; ++i) {
        if (freq[i] > maxfreq) {
            maxfreq = freq[i];
            index = i;
        }
    }

    std::cout << "The class of the unknown point is " << index;
    return 0;
}

// Measuring the Euclidean distance
float euclideanDistance(Point p, Point v) {
    float result;
    result = sqrt(((v.w - p.w) * (v.w - p.w)) + ((v.x - p.x) * (v.x - p.x)) +
                  ((v.y - p.y) * (v.y - p.y)) + ((v.z - p.z) * (v.z - p.z)));
    return result;
}

// Sample Output
/*
Number of data points: 5

Enter the dataset values:
w       x       y       z       op
1       2       3       4       5
10      20      30      40      50
5       2       40      7       10
40      30      100     28      3
20      57      98      46      8

w       x       y       z       op
1.00    2.00    3.00    4.00    5
10.00   20.00   30.00   40.00   50
5.00    2.00    40.00   7.00    10
40.00   30.00   100.00  28.00   3
20.00   57.00   98.00   46.00   8

Enter the feature values of the unknown point:
w       x       y       z
40      30      80      30

w       x       y       z       op      distance
40.00   30.00   100.00  28.00   3       20.10
20.00   57.00   98.00   46.00   8       41.34
10.00   20.00   30.00   40.00   50      60.00
5.00    2.00    40.00   7.00    10      64.33
1.00    2.00    3.00    4.00    5       94.39

Number of nearest neighbors(k): 3
The class of unknown point is 3
*/
