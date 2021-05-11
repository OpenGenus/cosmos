#include <iostream>
#include <vector>
// using namespace std;

/* This program is the bubble sort implementation
in C++ using recursion*/

void bubbleSort(std::vector<int>& v, int n)
{
    // Base Case
    if (n == 1)
        return;
    // sorting in a pass
    for (int i = 0; i < n - 1; i++){
        //comparing the elements and swapping accordingly
        if (v[i] > v[i + 1]){
            std::swap(v[i], v[i + 1]);
        }   
    }
    // recursive call for the next pass
    bubbleSort(v, n - 1);
}

int main()
{
    int n; // number of elements to be sorted
    std::cout << "Enter the number of element:" << '\n';
    std::cin >> n;
    std::vector<int> v; // vector of all the elements to be sorted
    std::cout << "Enter elements:" << '\n';
    for (int i = 0; i < n; i++)
    { // input all the elements
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    bubbleSort(v, n); // calling the sort function

    std::cout << "Sorted Elements:" << '\n'; // showing output of the sorted vector
    for (int element : v){
        std::cout << element << " ";
    }
    std::cout << '\n';
    return 0;
}
