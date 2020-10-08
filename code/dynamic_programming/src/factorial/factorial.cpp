#include <iostream>
using namespace std;
int factorial(int n)
{
  //base case
  if (n == 0 || n == 1)
  {
    return 1;
  }
  // recursive call
  return (n * factorial(n - 1));
}
int main()
{
  int n;
  cout << "Enter a number";
  //Taking input
  cin >> n;
  //printing output
  cout << "Factorial of n :" << factorial(n) << endl;
}
