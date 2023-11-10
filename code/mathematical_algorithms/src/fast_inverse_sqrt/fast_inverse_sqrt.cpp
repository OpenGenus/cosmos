// AUTHOR:      Mitchell Haugen
// GITHUB:      https://github.com/haugenmitch
// DATE:        October 9, 2017
// SOURCE:      https://stackoverflow.com/questions/1349542/john-carmacks-unusual-fast-inverse-square-root-quake-iii User: Rushyo
// DESCRIPTION: This algorithm use bit manipulation to calculate the inverse square root much faster than could be done if calculated in the proper way. It has surprising levels of accuracy that is sufficient for graphical applications.

#include <iostream>
#include <cstdint>
// Part of Cosmos by OpenGenus Foundation

double fastInverseSqrt(double x)
{
    float xhalf = 0.5f * x;
    std::int64_t i = *(std::int64_t*)&x;    // get bits for double value
    i = 0x5fe6eb50c7b537a9 - (i >> 1);      // gives initial guess y0
    x = *(double*)&i;                       // convert bits back to double
    x = x * (1.5 - (xhalf * x * x));        // Newton step, repeating increases accuracy
    return x;
}

int main()
{
    double input;
    std::cin >> input;

    std::cout << fastInverseSqrt(input) << std::endl;

    return 0;
}
