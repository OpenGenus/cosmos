#include <iostream>
#include <cmath>
using namespace std;

double log_factorial(int n)
{
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += log(i);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << log_factorial(n) << endl;

    return 0;
}
