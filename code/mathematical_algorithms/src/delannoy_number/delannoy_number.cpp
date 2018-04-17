#include <iostream>
// Part of Cosmos by OpenGenus Foundation
int DelannoyGenerator(int n, int m)
{
    int d = 1;
    if ((n == 0) || (m == 0))
        d = 1;
    else
        d = DelannoyGenerator(n - 1, m) + DelannoyGenerator(n, m - 1) + DelannoyGenerator(n - 1,
                                                                                          m - 1);

    return d;
}

int main()
{
    int m, n, result = 0;

    std::cout << "Provide the 'n' value: ";
    std::cin >> n;
    std::cout << std::endl;

    std::cout << "Provide the 'm' value: ";
    std::cin >> m;
    std::cout << std::endl;

    result = DelannoyGenerator(n, m);

    std::cout << "The delannoy number is: " << result << std::endl;
}
