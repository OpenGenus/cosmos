#include <iostream>
#include <vector>

int nthNewmanConwayNumber(int number)
{
    std::vector<int> arr {0, 1, 1};
    for(std::size_t i = 3; i <= number; ++i)
        arr.push_back(arr[arr[i - 1]] + arr[i - arr[i - 1]]);
    return arr[number];
}

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << nthNewmanConwayNumber(number) << "\n"; 
}