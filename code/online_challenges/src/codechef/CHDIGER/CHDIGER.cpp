#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        int d;
        cin >> n >> d;

        list<char>ans;
        stack<char>st;

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
            cout << i;
        }

        cout << "\n";
    }

    return 0;
}
