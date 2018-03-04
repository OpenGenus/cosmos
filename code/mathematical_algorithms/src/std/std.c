#include <stdio.h>
#include <math.h>


// calculate the mean of a given array having n elements
double
__mean(double arr[], size_t n)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    double mean = sum / n;
    return (mean);
}

// calculate the standard deviation of a given array having n elements
double 
std(double arr[], size_t n)
{
    double mean = __mean(arr, n);
    double std = 0;
    for (size_t i = 0; i < n; i++) {
        std = std + (arr[i] - mean) * (arr[i] - mean);
    }
    return (sqrt(std / n));
}

int 
main()
{
    double arr[] = { 12, 65, 91, 52, 18, 72 };
    printf("%lf", std(arr, sizeof(arr) / sizeof(arr[0]))); // 28.41

    return (0);
}
