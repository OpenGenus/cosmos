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
        int n;
        std::cin >> n;
        int a;
        int cnt_ps = 0, cnt_nt = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a;
            if (a < 0)
                cnt_nt++;
            else cnt_ps++;
        }

        if (cnt_nt == 0)
            cnt_nt = cnt_ps;

        else if (cnt_ps == 10)
            cnt_ps = cnt_nt;

        std::cout << std::max(cnt_ps, cnt_nt) << " " << std::min(cnt_ps, cnt_nt) << "\n";
    }

    return 0;
}
