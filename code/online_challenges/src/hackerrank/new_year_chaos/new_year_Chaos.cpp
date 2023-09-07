#include <iostream>

int q[1000007], pos[1000007];

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        int ans = 0;
        bool valid = true;
        std::cin >> n;
        for (int q_i = 1; q_i <= n; ++q_i)
        {
            std::cin >> q[q_i];
            pos[q[q_i]] = q_i;
        }

        for (int i = n; i >= 1 && valid; --i)
        {
            int x = pos[i];
            if (abs(x - i) > 2)
                valid = false;
            if (valid)
            {
                while (x != i)
                {
                    std::swap(q[x], q[x + 1]);
                    std::swap(pos[q[x]], pos[q[x + 1]]);
                    ++x;
                    ++ans;
                }
            }
        }

        if (!valid)
            std::cout << "Too chaotic\n";
        else
            std::cout << "\n"
                      << ans;
    }
    return 0;
}