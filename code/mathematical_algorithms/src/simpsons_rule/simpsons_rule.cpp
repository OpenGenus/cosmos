#include <iostream>
#include <cmath>

float create(int x)
{
    return log(x);
}

int simpson(int x1, int x2)
{
    float h = (x2 - x1) / 6;
    int x[10];
    float y[10];
    for (int i = 0; i <= n; ++i) {
        x[i] = x1 + i * h;
        y[i] = create(x[i]);
    }

    float value = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == 0 || i == n)
            value += y[i];
        else if (i % 2 != 0)
            value += 4 * y[i];
        else
            value += 2 * y[i];
    }
    value *= h / 3;
    return value;
}

int main()
{
    cout << "Enter the lower limit";
    cin >> x1;
    cout << "Enter the upper limit";
    cin >> x2;
    cout << simpson(x1, x2)<< "\n";
}
