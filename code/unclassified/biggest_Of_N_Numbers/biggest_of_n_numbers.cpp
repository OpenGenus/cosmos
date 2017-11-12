// compile with c++11 standard

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int biggest_of_n(vector<int> v)
{
  // sorting vector
  sort(v.begin(), v.end());

  // returning last element of vector
  return v[v.size() - 1];
}

int main()
{
  // initialising amd constructing vector array
  vector<int> vec = {10,5,20,15,-1};

  // ivoking biggest_of_n function
  cout<<"biggest number is : "<<biggest_of_n(vec);
  return 0;
}
