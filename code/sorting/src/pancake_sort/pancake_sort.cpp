#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void pancakeSort(std::vector<T>& container)
{
    for (int size = container.size(); size > 1; --size) 
    {
        // Find position of max element
        int maxPos = std::max_element(container.begin(), container.begin() + size) - container.begin(); 

        // Reverse the vector from begin to maxPos (max element becomes first element)
        std::reverse(container.begin(), container.begin() + maxPos + 1);

        // Reverse the vector from begin to size (max element to correct position)
        std::reverse(container.begin(), container.begin() + size);
    }
}

template <typename T>
void printVector(std::vector<T> v) 
{
    for (auto i : v) 
	    std::cout << i << " ";
        
    std::cout << std::endl;
}

int main() 
{
    // Sample vector of ints
    std::vector<int> v1 = {72, 23, 9, 31, 6, 8};
    // Sort vector using pancake sort
    pancakeSort(v1);
    // Print sorted vector
    printVector(v1);

    // Sample vector of doubles
    std::vector<double> v2 = {9.82, 7.36, 13.87, 2.28, 6.15, 45.56};
    // Sort vector using pancake sort
    pancakeSort(v2);
    // Print sorted vector
    printVector(v2);

    // Sample vector of floats
    std::vector<float> v3 = {74.25, 13.32, 25.71, 36.82, 10.11, 47.00};
    // Sort vector using pancake sort
    pancakeSort(v3);
    // Print sorted vector
    printVector(v3);

    return 0;
}
