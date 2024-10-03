#include <cmath>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    int r, c;
    int l = s.size();
    r = floor(sqrt(l));
    c = ceil(sqrt(l));

    for (int i = 0; i < c; ++i) {
        for (int j = i; j < l; j = j + c)
            std::cout << s[j];

        std::cout << "\n";
    }
}
