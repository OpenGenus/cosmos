#include <iostream>
#include <vector>

int nthNewmanConwayNumber(int number)
{
    std::vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    for(size_t i = 3; i <= number; ++i)
        arr.push_back(arr[arr[i - 1]] + arr[i - arr[i - 1]]);
    return arr[number];
}

int main()
{
    int number;
    std::cout << "Enter number:\n";
    std::cin >> number;
    std::cout << nthNewmanConwayNumber(number) << "\n"; 
}