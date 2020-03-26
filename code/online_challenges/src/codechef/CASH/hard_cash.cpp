#include <iostream>

using namespace std;
int main() 
{
  int t;
  cin >> t;
  while (t--) {
    int n, k, x, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) 
    {
      cin >> x;
      sum += x;
    }
    sum %= k;
    cout << sum << "\n";
  }
}
