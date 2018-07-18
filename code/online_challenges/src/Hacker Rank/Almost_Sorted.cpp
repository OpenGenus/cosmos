#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i; i < n; i++)
        {
          cin >> a[i];
          b[i] = a[i];
        }
    sort(b.begin(), b.end());
    int p = 0;
    int s,l;
    s = l = 0;
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        if(b[i] != a[i])
            {
              p++;
              if(t == 0)
                {
                  s = i;
                  t++;
                }
              else
                 l=i;
            }
    }

    if(p == 0)
        {
          cout << "yes";
          return 0;
        }
     else if(p == 2)
        {
          cout << "yes" << "\n";
          cout << "swap " << s + 1 << " " << l + 1;
          return 0;
    }


    {
        for(int i = l; i > s; i--)
        {
            if(a[i] > a[i-1])
            {
                cout << "no";
                return 0;
            }
        }

        cout << "yes" << "\n";
        cout << "reverse " << s + 1 << " " << l + 1;
    }





    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
