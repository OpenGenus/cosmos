// Given an array, find the noble integer in it.An integer x is said to be noble
// in arr[] if the number of integers > x is equal to x
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// O(n log n)
int noble_integer(std::vector<int> a) {
   std::sort(a.begin(), a.end());
   for (int i = 0; i < a.size(); ++i) {
      if (a[i] == a[i + 1])
         continue;
      // If arr[i] equals the number of elements after arr[i], it is a noble
      // Integer. Condition to check: (A[i] == length-i-1).
      if (a[i] == a.size() - i - 1)
         return a[i];
   }
   return -1;
}

int main() {
   int n;
   std::cout << "Enter the size of the array : ";
   std::cin >> n;
   std::vector<int> a(n);
   std::cout << "Enter the elements of the array : \n";
   for (int i = 0; i < n; ++i)
      std::cin >> a[i];
   int result = noble_integer(a);
   if (result != -1)
      std::cout << "Noble integer is : " << result << "\n";
   else
      std::cout << "No Noble integer present in array !"
                << "\n";
   return 0;
}

/*
Sample Input-Output
Enter the size of the array : 9
Enter the elements of the array :
7 3 16 10 12 12 3 3 5
Noble integer is : 5
*/