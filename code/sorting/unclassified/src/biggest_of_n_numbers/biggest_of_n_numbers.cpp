// Part of cosmos from opengenus foundation

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr;
    std::cout << "Keep entering numbers (EOF to stop): ";
    for (int num; std::cin >> num;)
        arr.push_back(num);

    sort(arr.begin(), arr.end());

    std::cout << "biggest number : " << arr.back();
}
