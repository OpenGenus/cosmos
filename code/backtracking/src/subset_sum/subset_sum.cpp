/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <vector>

using namespace std;

/*
 *  Generate all possible subset sums
 *  of array v that sum up to targetSum
 */
vector< vector<int>> generateSubsetSums(int v[], size_t size, int targetSum)
{

    vector< vector<int>> solutions;

    for (int i = 0; i < (1 << size); ++i)
    {

        int currentSum = 0;
        for (size_t j = 0; j < size; ++j)
            if (i & (1 << j))
                currentSum += v[j];

        if (currentSum == targetSum)
        {
            vector<int> subsetSum;
            for (size_t j = 0; j < size; ++j)
                if (i & (1 << j))
                    subsetSum.push_back(v[j]);

            solutions.push_back(subsetSum);
        }
    }

    return solutions;
}

int main()
{

    int v[] = {5, 12, -3, 10, -2, 7, -1, 8, 11};
    int targetSum = 7;

    vector< vector<int>> subsetSums = generateSubsetSums(v, sizeof(v) / sizeof(v[0]), targetSum);

    cout << "Subset sums:\n";
    for (size_t i = 0; i < subsetSums.size(); ++i)
    {
        cout << subsetSums[i][0];
        for (size_t j = 1; j < subsetSums[i].size(); ++j)
            cout << ", " << subsetSums[i][j];
        cout << '\n';
    }

    return 0;
}
