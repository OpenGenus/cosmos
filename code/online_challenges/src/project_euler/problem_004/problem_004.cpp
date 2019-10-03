#include <iostream>
#include <string>

int main()
{
    int l = 0;

    for (int i = 100; i <= 999; ++i)
        for (int j = 100; j <= 999; ++j)
        {
            int c = i * j;
            std::string cS = std::to_string(c);

            if ((cS == std::string{ cS.rbegin(), cS.rend() }) && (c > l))
                l = c;
        }

    std::cout << l << "\n";
}
