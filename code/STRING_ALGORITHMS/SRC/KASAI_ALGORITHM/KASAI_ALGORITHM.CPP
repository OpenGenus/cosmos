/*
 *
 * Kasai Algorithm
 *
 */
#include <vector>
#include <string>

std::vector<int> kasaiAlgorithm(std::string s, std::vector<int> suffix_array)
{
    using namespace std;
    size_t m = 0;
    vector<int> LCP(s.size(), 0);
    vector<size_t> rank(s.size(), 0);

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
