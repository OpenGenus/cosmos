#include <iostream>
#include <algorithm>

int main ()
{
    int n,q;
    std::cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin>>a[i];
    }

    int x = 0;
    int xors[n] = {0};
    for (int i = 0; i < n; ++i)
    {
        x = x ^ a[i];
        xors[i] = x;
    }

    while (q--)
    {
        int k;
        std::cin >> k;

        int idx = k % (n + 1);

        if (idx > 0)
            std::cout << xors[idx - 1] << "\n";
        else std::cout << "0\n";
    }

    return 0;
}
