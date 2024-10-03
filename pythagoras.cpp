#include <iostream>
using namespace std;
int main ()
{
  int i, j, k;
  for (i=1; i<=10; i++)
  {
    for (j=1; j<=10; j++)
    {
      for (k=1; k<=10; k++)
      {
       if((i*i+j*j)==k*k)
       cout<<"i="<<i<<" j="<<j<<" k="<<k<<"\n";
	  }
    }
  }
return 0;
}
