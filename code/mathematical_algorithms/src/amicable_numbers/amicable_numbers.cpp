// Part of Cosmos by OpenGenus Foundation

//Program to Calculate Amicable Numbers under 10000 and find sum of them

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int i = 1, s1 = 0, s2 = 0, sum = 0;

    for (k = 1; k <= 10000; k++)
    {
        n = k;
        while (i < n)
        {
            if (n % i == 0)
                s1 = s1 + i;
            i++;
        }
        i = 1;
        if (s1 == n)
            continue;
        while (i < s1)
        {
            if (s1 % i == 0)
                s2 = s2 + i;
            i++;
        }
        if (n == s2)
        {
            cout << n << endl;
            sum += n;
        }

        s1 = 0;
        s2 = 0;
    }
    cout << "\nSum of Amicable numbers under 10000 is : " << sum;
}
