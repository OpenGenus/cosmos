#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a;
        int cnt_ps = 0, cnt_nt = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            if (a < 0)
                cnt_nt++;
            else cnt_ps++;
        }

        if (cnt_nt == 0)
            cnt_nt = cnt_ps;

        else if (cnt_ps == 10)
            cnt_ps = cnt_nt;

        cout << max(cnt_ps, cnt_nt) << " " << min(cnt_ps, cnt_nt) << "\n";
    }

    return 0;
}
