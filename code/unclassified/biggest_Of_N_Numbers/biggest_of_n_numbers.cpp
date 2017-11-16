// compile with c++11 standard

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  // initialising amd constructing vector array
  vector<int> vec = {10,5,20,15,-1};

  // sorting the vector
  sort(vec.begin(), vec.end());

  // printing the last element
  cout<<"biggest number is : "<<vec[vec.size() - 1]
  return 0;
}
