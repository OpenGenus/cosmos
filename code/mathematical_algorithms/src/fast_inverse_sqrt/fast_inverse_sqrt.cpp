// AUTHOR:      Mitchell Haugen
// GITHUB:      https://github.com/haugenmitch
// DATE:        October 9, 2017
// SOURCE:      https://stackoverflow.com/questions/1349542/john-carmacks-unusual-fast-inverse-square-root-quake-iii User: Rushyo
// DESCRIPTION: This algorithm use bit manipulation to calculate the inverse square root much faster than could be done if calculated in the proper way. It has surprising levels of accuracy that is sufficient for graphical applications.

#include <iostream>
// Part of Cosmos by OpenGenus Foundation

double fastInverseSqrt(double x)
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x;              // get bits for floating value
    i = 0x5f375a86 - (i >> 1);      // gives initial guess y0
    x = *(float*)&i;                // convert bits back to float
    x = x * (1.5f - xhalf * x * x); // Newton step, repeating increases accuracy
    return x;
}

int main()
{
    double input;
    std::cin >> input;

    std::cout << fastInverseSqrt(input) << std::endl;

    return 0;
}
