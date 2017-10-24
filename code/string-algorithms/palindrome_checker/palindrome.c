#include <stdbool.h>
#include <stdio.h>

/*
 * Part of Cosmos by OpenGenus Foundation
*/

bool isPalindromeIterative(char *input, int length) {
    int start = 0, end = length - 1;
    while (start < end) {
        if (input[start++] != input[end--]) {
            return false;
        }
    }
    return true;
}

bool isPalindromeRecursive(char *input, int length) {
    if (length <= 1) {
        return true;
    }
    else if (input[0] != input[length - 1]) {
        return false;
    }
    else {
        return isPalindromeRecursive(input + 1, length - 2);
    }
}

int main(void) {
    printf("Is hello a palindrome (iterative): %d\n", isPalindromeIterative("hello", 5));
    printf("Is racecar a palindrome (iterative): %d\n", isPalindromeIterative("racecar", 7));
    printf("Is aba a palindrome (iterative): %d\n", isPalindromeIterative("aba", 3));
    printf("Is hello a palindrome (recursive): %d\n", isPalindromeRecursive("hello", 5));
    printf("Is racecar a palindrome (recursive): %d\n", isPalindromeRecursive("racecar", 7));
    printf("Is aba a palindrome (recursive): %d\n", isPalindromeRecursive("aba", 3));
    return 0;
}