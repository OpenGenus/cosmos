#include<iostream>

int factorial(int num) {
    if (num == 0 || num == 1) {
        return num;
    }
    return (num * factorial(num - 1));
} 

int main() {
    int num;
    while (true) {
        std::cin >> num;
        std::cout << "> " << factorial(num) << '\n';
    }
    return 0;
}
