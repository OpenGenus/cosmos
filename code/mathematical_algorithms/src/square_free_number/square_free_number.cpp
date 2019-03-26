//Program to check whether a number is square_free or not
#include <iostream>
#include <cmath>

bool isSquareFree(int n)
{

    if (n % 2 == 0)
        n /= 2;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= std::sqrt(n); i += 2)
        if (n % i == 0)
        {
            n /= i;
            if (n % i == 0)
                return false;
        }
    return true;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (isSquareFree(n))
        std::cout << n << " is square free number";
    else
        std::cout << n << " is not a square free number";
    return 0;
}
