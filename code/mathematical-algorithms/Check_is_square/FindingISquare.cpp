#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
bool IsSquare(lld number)
{
  lld min = 1;
  lld max = number;
  lld mid = min + (max - min)/2;
  if (number == 0 || number == 1)
  return true;
  while (min<max) {

    if (mid*mid > number)
    {
      max = mid -1;
      mid = min + (max - min)/2;
    }
    else if (mid*mid < number)
    {
      min = mid + 1;
      mid = min + (max - min)/2;

    }
    else
        return true;

  }
  return false;
}

int main() {

  int t;
  cout << "Enter the Number of testcases:" << '\n';
  cin >> t;
  lld number;
  while (t--)
  {
    cin >> number;
    bool result = IsSquare(number);
    if (result)
    {
      cout << "Square number" << '\n';
    }
    else
    {
      cout << "Not a Square number" << '\n';
    }
  }
  return 0;
}
