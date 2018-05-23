// dynamic programming | boolean parenthesization | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
#include <cstring>

// Dynamic programming implementation of the boolean
// parenthesization problem using 'T' and 'F' as characters
// and '&', '|' and '^' as the operators
int boolean_parenthesization(char c[], char o[], int n)
{
    int t[n][n], f[n][n];

    for (int i = 0; i < n; ++i)
    {

        if (c[i] == 'T')
        {
            t[i][i] = 1;
            f[i][i] = 0;

        }
        else
        {
            t[i][i] = 0;
            f[i][i] = 1;
        }
    }

    for (int i = 1; i < n; ++i)
        for (int j = 0, k = i; k < n; ++j, ++k)
        {

            t[j][k] = 0;
            f[j][k] = 0;

            for (int a = 0; a < i; ++a)
            {
                int b = j + a;
                int d = t[j][b] + f[j][b];
                int e = t[b + 1][k] + f[b + 1][k];

                if (o[b] == '|')
                {
                    t[j][k] += d * e - f[j][b] * f[b + 1][k];
                    f[j][k] += f[j][b] * f[b + 1][k];
                }
                else if (o[b] == '&')
                {
                    t[j][k] += t[j][b] * t[b + 1][k];
                    f[j][k] += d * e - t[j][b] * t[b + 1][k];
                }
                else
                {
                    t[j][k] += f[j][b] * t[b + 1][k] + t[j][b] * f[b + 1][k];
                    f[j][k] += t[j][b] * t[b + 1][k] + f[j][b] * f[b + 1][k];
                }
            }
        }
    return t[0][n - 1];
}

int main()
{
    char c[] = "TFTTF";
    char s[] = "|&|^";
    int n = sizeof(c) - 1 / sizeof(c[0]);
    std::cout << boolean_parenthesization(c, s, n);
    return 0;
}
