// Iterative ternary search algorithm
#include <iostream>

using namespace std;
int ternarySearchIterative(int input[], int l, int r, int value) {
    int mid1, mid2;

    while (1) {
        mid1 = l + (r-l)/3;
        mid2 = r - (r-l)/3;

        if (l > r)
            return -1;

        if (input[mid1] == value)
            return mid1;

        if (input[mid2] == value)
            return mid2;

        if (value < input[mid1])
            r = mid1 - 1;
        else if (value > input[mid2])
            l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
}

int main() {
    int input[] = {1, 2, 3, 4, 5, 6};
    cout << ternarySearchIterative(input, 0, 5, 4) << endl;
    return 0;
}
