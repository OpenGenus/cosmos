// Find maximum and minimum of an array using minimum number of comparisons
#include <cstdlib>
#include <iostream>
#include <vector>

//Structure is used to return two values from minMax() 
struct minMax {
    int min;
    int max;
};

struct minMax tournamentMethod(std::vector<int> a, int beg, int end) {
    struct minMax min_max;
    //If there is only one element
    if (beg == end) {            
        min_max.min = a[beg];
        min_max.max = a[beg];
        return min_max;
    }
    //If there are two elements
    else if (end == beg + 1) {    
        if (a[beg] < a[end]) {
            min_max.min = a[beg];
            min_max.max = a[end];
        } else {
            min_max.min = a[end];
            min_max.max = a[beg];
        }
        return min_max;
    }
    //If there are more than 2 elements
    int mid = (beg + end) / 2;     
    struct minMax min_max_left = tournamentMethod(a, beg, mid);
    struct minMax min_max_right = tournamentMethod(a, mid + 1, end);

    //Compare minimums of two parts
    if (min_max_left.min < min_max_right.min) {   
        min_max.min = min_max_left.min;
    } else
        min_max.min = min_max_right.min;
    
    //Compare maximums of two parts
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
