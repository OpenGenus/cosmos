// Find maximum and minimum of an array using minimum number of comparisons
#include <cstdlib>
#include <iostream>
#include <vector>

struct minMax {
    int min;
    int max;
};

struct minMax tournamentMethod(std::vector<int> a, int beg, int end) {
    struct minMax min_max;
    if (beg == end) {
        min_max.min = a[beg];
        min_max.max = a[beg];
        return min_max;
    } else if (end == beg + 1) {
        if (a[beg] < a[end]) {
            min_max.min = a[beg];
            min_max.max = a[end];
        } else {
            min_max.min = a[end];
            min_max.max = a[beg];
        }
        return min_max;
    }

    int mid = (beg + end) / 2;
    struct minMax min_max_left = tournamentMethod(a, beg, mid);
    struct minMax min_max_right = tournamentMethod(a, mid + 1, end);
    if (min_max_left.min < min_max_right.min) {
        min_max.min = min_max_left.min;
    } else
        min_max.min = min_max_right.min;
    if (min_max_left.max > min_max_right.max)
        min_max.max = min_max_left.max;
    else
        min_max.max = min_max_right.max;
    return min_max;
}

int main() {
    int n;
    std::cout << "Enter the size of the array :  ";
    std::cin >> n;
    std::cout << "Enter the values of the array : \n";
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    struct minMax min_max = tournamentMethod(a, 0, n - 1);
    std::cout << "Minimum and maximum elements of the array :  " << min_max.min
              << " " << min_max.max << "\n";
    return 0;
}

/*Sample Input-Output
Enter the size of the array :  6
Enter the values of the array :
12 32 11 9 4 -4 6 8
Minimum and maximum elements of the array :  -4 32
*/
