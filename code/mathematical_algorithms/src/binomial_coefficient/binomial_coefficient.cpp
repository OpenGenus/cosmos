#include <iostream>
using namespace std;

//Calculation C(n, r) modulo any number (prime or composite) using pascal triangle
//Pre-computation : O(n^2)
const int MAX = 1e3 + 3;
const int MOD = 1e9 + 7;

int ncr[MAX][MAX];

void pascal()
{
    for (int i = 0; i < MAX; ++i)
    {
        ncr[i][0] = ncr[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            if (ncr[i][j] >= MOD)
                ncr[i][j] -= MOD;
        }
    }
}

int main()
{
    pascal();
    cout << "Binomial Coefficient of (10, 5) is " << ncr[10][5] << "\n";
    return 0;
}
