#include <iostream>
#include <math.h>
using namespace std;

float func(float x)
{
    return log(x);
}

float simpsons_(float ll, float ul, int n)
{
    float h = (ul - ll) / n;

    float x[10], fx[10];

    for (int i = 0; i <= n; ++i) {
        x[i] = ll + i * h;
        fx[i] = func(x[i]);
    }

    float res = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == 0 || i == n)
            res += fx[i];
        else if (i % 2 != 0)
            res += 4 * fx[i];
        else
            res += 2 * fx[i];
    }
    res = res * (h / 3);
    return res;
}

int main()
{
    float lower_limit = 4;
    float upper_limit = 5.2;
    int n = 6;
    cout << simpsons(lower_limit, upper_limit, n);
    return 0;
}
