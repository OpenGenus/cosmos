#include <cstdlib>
#include <iostream>
#include <vector>
// Add 1 to number
/*
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the
list.
*/
/*
Here we are calculating the number of trailing zeroes to the left that we need
to exclude while printing the output For example : if the input is 0,0,1,2,3,4
=> The output should be 1,2,3,5 and NOT 0,0,1,2,3,5 So, here we are finding the
number of continuos 0's in the input that we need to exclude in the output
*/

std::vector<int> plusOne(std::vector<int> &A) {
    std::vector<int> A1(A.size());
    A1 = A;
    int c = 0, ind = 0;
    if (A[0] == 0) {
        c = 1;
        while (1) {
            if (A[ind] + A[ind + 1] == 0) {
                c++;
                ind++;
            } else
                break;
        }
    }
    // cout<<" C is : " <<c<<"\n";
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] < 9) {
            A[i]++;
            if (A1[0] == 0 && A.size() > 1)
                return std::vector<int>(A.begin() + c, A.end());
            else
                return A;
        }
        A[i] = 0;
    }
    std::vector<int> result(A.size() + 1);
    result[0] = 1;
    return result;
}

int main() {
    int n;
    std::cout << "Enter the size of the array : ";
    std::cin >> n;
    std::vector<int> A(n);
    std::cout << "Enter the elements of the array :\n";
    for (int i = 0; i < n; ++i)
        std::cin >> A[i];
    std::cout << "Sum is : ";
    std::vector<int> result = plusOne(A);
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";
    return 0;
}

/* Sample Input - Output:
Enter the size of the array : 10
Enter the elements of the array :
0 0 4 5 2 0 9 7 1 2
Sum is : 4 5 2 0 9 7 1 3

Enter the size of the array : 6
Enter the elements of the array :
0 0 1 6 5 2
Sum is : 1 6 5 3
*/
