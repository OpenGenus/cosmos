#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
  int a=1, b=1, c;
  int i, j, k;
  double d, e;

  for (i=1; i<=500; i++)
  {
     a += 1;
     for (j=1; j<=500; j++)
     {
        b += 1;
     for (k=1; k<=500; k++)
     {
        e = ((a*a) + (b*b));
        d = sqrt(e);
        c = int(d);
        if ((c == d) && (c <=500))
           cout << "a = " << a << "\t\t b = " << b << "\t\t c = " << c << endl;
	}
     }
  }

  return 0;
}
