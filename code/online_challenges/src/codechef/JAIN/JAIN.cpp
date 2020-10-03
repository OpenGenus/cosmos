#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <utility>

std::map<char,int>g_mp;

void build ()
{
    g_mp.insert(std::make_pair('a',16));
    g_mp.insert(std::make_pair('e',8));
    g_mp.insert(std::make_pair('i',4));
    g_mp.insert(std::make_pair('o',2));
    g_mp.insert(std::make_pair('u',1));
}

int main()
{
    build();

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::string a[n];
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];

        std::vector<short>value;
        std::set<short>s;
        std::vector<long long>count(33,0);

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for(int j = 0; j < a[i].size(); ++j)
            {
                x = x | g_mp[a[i][j]];
            }
            if (s.find(x) == s.end())
            {   
                value.push_back(x);
                count[x] = 1;
                s.insert(x);
            }
            else
            {
                count[x]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < value.size(); ++i)
        {
            for (int j = i + 1; j < value.size(); ++j)
                if ((value[i] | value[j]) == 31)
                    ans = ans + (count[value[i]] * count[value[j]]);
        }

        ans = ans + ((count[31] * (count[31] - 1)) / 2);
        std::cout << ans << "\n";
    }

    return 0;
}
