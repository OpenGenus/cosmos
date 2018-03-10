#include <iostream>
#include <vector>

int factorial (int n) 
{  
    int fact =  1;
    for(std::size_t i = 1; i <= n; i++)
    	fact *= i;
    return fact;
}

int main()
{
    std::vector<int> factorials(10);
    constexpr int maxDigitFactorial = 2540162;
    for(int i = 0;i < 10; ++i)
        factorials[i] = factorial(i);
    int num = 3, sum = 0;
    while (num < maxDigitFactorial)
    {
        int temp = 0;
        for(std::size_t i = num; i > 0; i /= 10)
            temp += factorials[i % 10];
        if(temp == num)
            sum += num;
        ++num;
    }
    std::cout << sum << "\n";
}
