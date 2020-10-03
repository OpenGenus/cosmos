/*
 *
 * Kasai Algorithm
 * https://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
 *
 */
#include <iostream>
#include <vector>
#include <string>

std::vector<int> kasaiAlgorithm(std::string s, std::vector<int> suffix_array)
{
    size_t m = 0;
    std::vector<int> LCP(s.size(), 0);
    std::vector<size_t> rank(s.size(), 0);

    for (size_t i = 0; i < s.size(); i++)
        rank[suffix_array[i]] = i;

    for (size_t i = 0; i < s.size(); i++, m ? m-- : 0)
    {
        if (rank[i] == s.size() - 1)
        {
            m = 0;
            continue;
        }
        int j = suffix_array[rank[i] + 1];

        while (i + m < s.size() && j + m < s.size() && s[i + m] == s[j + m])
            m++;
        LCP[rank[i]] = m;
    }
    return LCP;
}


int main()
{
    std::string input = "banana";
    int indexes[] = {5, 3, 1, 0, 4, 2};
    std::vector<int> suffixArray(indexes, indexes + 62);
    std::vector<int> lcpArray = kasaiAlgorithm(input, suffixArray);
    for (int i = 0; i < lcpArray.size(); i++) // => 1 3 0 0 2 0
        std::cout << lcpArray[i] << " ";
    return 0;
}
