#include <bits/stdc++.h>
using namespace std;

struct point 
{
    float w, x, y, z; // w, x, y and z are the values of the dataset
    float distance; // distance will store the distance of dataset point from the unknown test point
    int op; // op will store the class of the point
};

int main() 
{
    int i, j, n, k;
    struct point p;
    struct point temp;
    cout << "Number of data points: ";
    cin >> n;
    struct point arr[n];
    cout << "\nEnter the dataset values: \n";
    cout << "w\tx\ty\tz\top\n";

    // Taking dataset
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].w >> arr[i].x >> arr[i].y >> arr[i].z >> arr[i].op;
    }

    cout << "\nw\tx\ty\tz\top\n";

    for (i = 0; i < n; i++) 
    {
        cout << fixed << setprecision(2) << arr[i].w << '\t' << arr[i].x << '\t' << arr[i].y << '\t' << arr[i].z << '\t' << arr[i].op << '\n';
    }

    cout << "\nEnter the feature values of the unknown point: \nw\tx\ty\tz\n";
    cin >> p.w >> p.x >> p.y >> p.z;

    // Measuring the Euclidean distance
    for (i = 0; i < n; i++) 
    {
        arr[i].distance = sqrt(((arr[i].w - p.w) * (arr[i].w - p.w)) + ((arr[i].x - p.x) * (arr[i].x - p.x)) + ((arr[i].y - p.y) * (arr[i].y - p.y)) + ((arr[i].z - p.z) * (arr[i].z - p.z)));
    }

    // Sorting the training data with respect to distance
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++) 
        {
            if (arr[j].distance > arr[j + 1].distance)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nw\tx\ty\tz\top\tdistance\n";
    for (i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << arr[i].w << '\t' << arr[i].x << '\t' << arr[i].y << '\t' << arr[i].z << '\t' << arr[i].op << '\t' << arr[i].distance << '\n';
    }

    // Taking the K nearest neighbors
    cout << "\nNumber of nearest neighbors(k): ";
    cin >> k;

    int freq[1000] = {0};
    int index = 0, maxfreq = 0;

    // Creating frequency array of the class of k nearest neighbors
    for (int i = 0; i < k; i++)
    {
        freq[arr[i].op]++;
    }

    // Finding the most frequent occurring class
    for (int i = 0; i < 1000; i++) 
    {
        if(freq[i] > maxfreq) 
        {
            maxfreq = freq[i];
            index = i;
        }
    }

    cout << "The class of unknown point is " << index;
    return 0;
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
