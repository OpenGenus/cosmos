// dynamic programming | binomial coefficient | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
#include <vector>

using namespace std;

/*
 *  Computes C(n,k) via dynamic programming
 *  C(n,k) = C(n-1, k-1) + C(n-1, k)
 *  Time complexity: O(n*k)
 *  Space complexity: O(k)
 */
long long binomialCoefficient(int n, int k)
{

    long long C[k + 1];
    for (int i = 0; i < k + 1; ++i)
        C[i] = 0;
    C[0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = min(i, k); j > 0; --j)
            C[j] = C[j] + C[j - 1];

    return C[k];
}

/*
 *  More efficient algorithm to compute binomial coefficient
 *  Time complexity: O(k)
 *  Space complexity: O(1)
 */
long long binomialCoefficient_2(int n, int k)
{

    long long answer = 1;

    k = min(k, n - k);

    for (int i = 1; i <= k; ++i, --n)
    {
        answer *= n;
        answer /= i;
    }

    return answer;
}

void test(vector< pair<int, int>>& testCases)
{

    for (auto test : testCases)
        cout << "C(" << test.first << "," << test.second << ") = "
             << binomialCoefficient(test.first, test.second) << " = "
             << binomialCoefficient_2(test.first, test.second) << '\n';
}

int main()
{

    vector< pair<int, int>> testCases = {
        {5, 2},
        {6, 6},
        {7, 5},
        {10, 6},
        {30, 15}
    };

    test(testCases);

    return 0;
}
