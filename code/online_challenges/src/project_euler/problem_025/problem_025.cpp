#include <iostream>
#include <vector>

int main()
{
    std::vector<int> prevFibonacci, currFibonacci;
    prevFibonacci.reserve(1000);
    currFibonacci.reserve(1000);
    int count = 2;
    prevFibonacci.push_back(1);
    currFibonacci.push_back(1);

    while (currFibonacci.size() < 1000)
    {
        std::vector<int> temp;
        int carry = 0;
        ++count;

        for (size_t i = 0; i < prevFibonacci.size(); ++i)
        {
            temp.push_back((currFibonacci[i] + prevFibonacci[i] + carry) % 10);
            carry = (currFibonacci[i] + prevFibonacci[i] + carry) / 10;
        }

        for (size_t i = prevFibonacci.size(); i < currFibonacci.size(); i++)
        {
            temp.push_back((currFibonacci[i] + carry) % 10);
            carry = (currFibonacci[i] + carry) / 10;
        }

        if (carry)
            temp.push_back(carry);

        prevFibonacci = currFibonacci;
        currFibonacci = temp;

    }
    std:: cout << count << "\n";
    return 0;
}
