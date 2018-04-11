#include <iostream>

int sumOfDigits(int number)
{
    int sum = 0;
    while(number != 0)
    {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

int main()
{
    int num;
    std::cout << "Enter number to be summed: ";
    std::cin >> num;
    std::cout << sumOfDigits(num) << std::endl;
}
