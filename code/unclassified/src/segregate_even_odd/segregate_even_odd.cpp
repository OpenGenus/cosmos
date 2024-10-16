// Segregate all even numbers to left and odd numbers to right of the array
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

void even_odd(std::vector<int> a) {
    int i = 0;
    int j = a.size() - 1;
    while (i < j) {
        while (a[i] % 2 == 0 && i < j)
            i++;
        while (a[j] % 2 != 0 && i < j)
            j--;
        if (i < j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    std::cout << "After segregation : \n";
    for (int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
}

int main() {
    int n;
    std::cout << "Enter the number of elements in array :  ";
    std::cin >> n;
    std::vector<int> a(n);
    std::cout << "Enter the values of the elements :  ";
    for (int i = 0; i < a.size(); ++i) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    even_odd(a);
    return 0;
}

/* Sample Input-Output
Enter the number of elements in array :  8
Enter the values of the elements :  12 33 5 8 9 15 6 20
After segregation :
12 20 6 8 9 15 5 33
*/
