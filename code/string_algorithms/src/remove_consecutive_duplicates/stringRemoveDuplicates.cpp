#include <iostream>
#include <string>
std::string stringRemoveDuplicates(std::string s)
{
    std::string s1;
    s1 += s[0];
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1])
            s1 += s[i];
    }
    s = s1;
    return s;
}
int main()
{
    std::string s;
    std::cin >> s;
    std::string s1 = stringRemoveDuplicates(s);
    std::cout << s1 << "\n";
}
