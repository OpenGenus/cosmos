#include <iostream>
#include <vector>

using namespace std;
// Part of Cosmos by OpenGenus Foundation

typedef vector<int> vi;
typedef vector<vi> vvi;

// construct triangle with rows 0...n
// pascal[i][j] = 0 iff i < j
vvi pascal_triangle(int n)
{
    vvi pascal(n + 1, vi(n + 1));
    for (int i = 0; i <= n; ++i)
    {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; ++j)
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
    return pascal;
}

int main()
{
    int n;
    scanf("%d", &n);
    vvi pascal = pascal_triangle(n);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            printf("%2d%c", pascal[i][j], " \n"[j == i]);
    return 0;
}
