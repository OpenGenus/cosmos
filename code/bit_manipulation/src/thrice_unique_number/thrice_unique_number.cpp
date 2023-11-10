/*
 *
 * Part of Cosmos by OpenGenus Foundation
 * Find unique number in an array where every element occours thrice except one.Find that unique Number
 *
 */
#include <iostream>
using namespace std;
int n;
int a[104] = {1, 1, 1, 3, 3, 2, 3};
int f()
{
    int count[65] = {0};
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int temp = a[i];
        while (temp)
        {
            count[j] += (temp & 1);
            j++;
            temp = temp >> 1;
        }
    }
    int p = 1, ans = 0;
    for (int i = 0; i <= 64; i++)
    {
        count[i] %= 3;
        ans += (count[i] * p);
        p = p << 1;
    }
    return ans;
}
int main()
{
    n = sizeof(a) / sizeof(a[0]);
    cout << f();
    return 0;
}
