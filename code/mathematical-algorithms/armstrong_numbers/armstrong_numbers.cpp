#include <iostream>
using namespace std;
int main()
{
  int origNum, num, rem, sum = 0;
  cout << "Enter a positive  integer: ";
  cin >> origNum;
  num = origNum;
  while(num != 0)
  {
      rem = num % 10;
      sum += rem * rem * rem;
      num /= 10;
  }
  if(sum == origNum)
    cout << origNum << " is an Armstrong number.";
  else
    cout << origNum << " is not an Armstrong number.";
  return 0;
}
