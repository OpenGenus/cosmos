#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r) 
{
	int x = a[l];
    int m1 = l;
	int m2 = r;
	int i = l;
    while(i <= m2){
		if (a[i] < x) {
			swap(a[i], a[m1]);
			m1++;
			i++;
		}
		else if (a[i] > x) {
			swap(a[i], a[m2]);
			m2--;
		}
		else
			i++;
    }
	vector<int> m(2);
	m[0]=m1;
	m[1]=m2;
    return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) 
{
  if (l >= r) 
    return;


  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() 
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cout << a[i] << ' ';
  }
}
