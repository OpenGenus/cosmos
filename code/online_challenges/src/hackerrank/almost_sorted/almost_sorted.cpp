#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    std::vector <int> b(n);
    for(int i; i < n; i++)
        {
          std::cin >> a[i];
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
          std::cout << "yes";
          return 0;
        }
     else if(p == 2)
        {
          std::cout << "yes" << "\n";
          std::cout << "swap " << s + 1 << " " << l + 1;
          return 0;
    }


    {
        for(int i = l; i > s; i--)
        {
            if(a[i] > a[i-1])
            {
                std::cout << "no";
                return 0;
            }
        }

        std::cout << "yes" << "\n";
        std::cout << "reverse " << s + 1 << " " << l + 1;
    }





    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
