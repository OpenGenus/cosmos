#include <iostream>
#include <vector>

using namespace std;

// Part of Cosmos by OpenGenus Foundation
double getAverage(double num)
{
    static double sum = 0, n = 0;

    sum += num;
    return sum / ++n;
}

void streamAverage(vector<double> arr)
{
    double average = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        average = getAverage(arr[i]);
        cout << "Average of " << i + 1 << " numbers is " << average << endl;
    }
}

int main()
{
    vector<double> arr{10, 20, 30, 40, 50, 60};
    streamAverage(arr);

    return 0;
}
