#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
vector<int> v;
void first_negative_element_of_size_k(int arr[], int n, int k)
{
  // first generate the window
  int i = 0, j = 0;
  
  list<int> l;

  while (j < n)
  {
    // calculations
    if (arr[j] < 0)
    {
      l.push_back(arr[j]);
    }
    // making window
    if (j - i + 1 < k)
      j++;
    // keep the window constant
    if (j - i + 1 == k)
    {
     
      int ans = l.front();
      v.push_back(ans);
      l.pop_front();
      i++;
      j++;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[100];
  fi(0, n) cin >> arr[i];
  first_negative_element_of_size_k(arr, n, 3);
  fi(0, v.size()) cout << v[i] << " ";
  return 0;
}
