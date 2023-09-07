#include <iostream>

int solveMeFirst(int a, int b) {
  int c;
  c = a + b;
  return c;
}

int main() {
  int num1, num2;
  int sum;
  std::cin >> num1 >> num2;
  sum = solveMeFirst(num1, num2);
  std::cout << sum;
  return 0;
}
