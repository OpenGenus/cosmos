#include <cmath>
#include <iostream>
using namespace std;


int main()
{
    string s;
    cin >> s;

    int r, c;
    int  l = s.size();
    r = floor(sqrt(l));
    c = ceil(sqrt(l));

    for(int i=0;i<c;i++)
      {

          for(int j = i; j < l; j = j + c)
              cout << s[j];


          cout << " ";
      }
}
