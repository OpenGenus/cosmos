#include <iostream>
#include <vector>
int factorial (int n) 
{
    if(n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    std::vector<int> factor(10);
    for(int i = 0; i < 10; ++i)
        factor[i] = factorial(i);
    int num = 3, temp, sum = 0;
    while (num < 2540162)
    {
        temp = 0;
        for(size_t i = num; i > 0; i /= 10)
            temp += factor[i % 10];
        if(temp == num)
            sum += num;
        ++num;
    }
    std::cout << sum << "\n";
    return 0;
}