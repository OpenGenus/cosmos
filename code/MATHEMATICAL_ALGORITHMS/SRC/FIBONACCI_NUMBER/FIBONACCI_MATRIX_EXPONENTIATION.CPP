#include <iostream>
#include <cstring>
using namespace std;
long long fib(long long n)
{
    long long fib[2][2] = {{1, 1}, {1, 0}}, ret[2][2] = {{1, 0}, {0, 1}},
              temp[2][2] = {{0, 0}, {0, 0}};
    int i, j, k;
// Part of Cosmos by OpenGenus Foundation
    while (n > 0)
    {
        if (n & 1)
        {
            memset(temp, 0, sizeof temp);
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    for (k = 0; k < 2; k++)
                        temp[i][j] += (ret[i][k] * fib[k][j]);
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    ret[i][j] = temp[i][j];
        }
        memset(temp, 0, sizeof temp);
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                for (k = 0; k < 2; k++)
                    temp[i][j] += (fib[i][k] * fib[k][j]);

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                fib[i][j] = temp[i][j];

        n /= 2;
    }
    return ret[0][1];


}
int main()
{
    //test case : Print 50th fibonacci number
    cout << fib(50);
}
