#include <string>
#include <iostream>
#include <cassert>

std::string strAdd(std::string s, std::string r)
{
    int re = 0;
    std::string sum;

    // precondition for empty strings
    assert(s.length() > 0 && r.length() > 0);

    if (r.length() < s.length())
        r.insert(r.begin(), s.length() - r.length(), '0');
    else if (r.length() > s.length())
        s.insert(s.begin(), r.length() - s.length(), '0');
    for (int i = s.length() - 1; i >= 0; --i)
    {
        int a = (int(s[i] + r[i]) + re - 96);
        sum.insert(sum.begin(), char(a % 10 + 48));
        re = a / 10;
    }
    if (re != 0)
        sum.insert(sum.begin(), char(re + 48));
    return sum;
}

int main()
{
    std::string s;
    std::string c;
    std::cout << "Enter Number One" << "\n";
    std::cin >> s;
    std::cout << "Enter Number Two" << "\n";
    std::cin >> c;
    std::cout << "Addition Result: " << strAdd(s, c) << "\n";
    return 0;
}
