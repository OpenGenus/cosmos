#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <string>

int main ()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string n;
        int d;
        std::cin >> n >> d;

        std::list<char>ans;
        std::stack<char>st;

        for (int i = 0; i < n.size(); ++i)
        {
            if (n[i] - '0' < d)
            {
                while (!st.empty() && st.top() > n[i])
                    st.pop();
                st.push(n[i]);
            }
        }

        while (!st.empty())
        {
            ans.push_front(st.top());
            st.pop();
        }

        int sz = n.size() - ans.size();

        for (int i = 0; i < sz; ++i)
        {
            ans.push_back(char(d + '0'));
        }

        for (auto i : ans)
        {
            std::cout << i;
        }

        std::cout << "\n";
    }

    return 0;
}
