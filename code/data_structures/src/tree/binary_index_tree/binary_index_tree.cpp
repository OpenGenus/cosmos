#include <iostream>
#include <vector>
  using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
 
  // Constructor for initialization of size 
  fenwick(int _n) : n(_n + 1) {
    fenw.resize(n);
  }
 
  // to modify , add or replace value at index x
  void modify(int x, T v) {
    while (x <= n) {
      fenw[x] += v;
      x += (x & -x);
    }
  }
 
  // To get sum of prefix ending at x
  T get(int x) {
    T v{};
    while (x > 0) {
      v += fenw[x];
      x -= (x & -x);
    }
    return v;
  }
};


int main(){
  vector <int> ar = {1 , 2 , 3 , 4 , 5};
  fenwick <int> F(5);
  for(int i = 0 ; i < (int) ar.size() ; ++i){
    F.modify(i + 1 ,ar[i]);
  }
  for(int i = 0 ; i < (int) ar.size() ; ++i){
    cout << F.get(i + 1) << ' ';
  }
  cout << '\n';
  return 0;
}
