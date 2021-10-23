// Factorial program using recursion

#include<iostream>

int factorial(int num) {
    /*
        Returns the factorial of a number.
        For a number 'num', its factorial is defined as 1 x 2 x 3...... x num
        i.e., the multiplication of numbers from 1 to num.
    */
    if (num == 0 || num == 1) {
        return num;
    }
    return (num * factorial(num - 1));
} 

/* Driver code for the above factorial program */
int main() {
    int num;
    while (true) {
        std::cin >> num;
        std::cout << "> " << factorial(num) << '\n';
    }
    return 0;
}