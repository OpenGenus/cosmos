#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
  int a=1, b=1, c;//Initialization of variables
  int i, j, k;
  double d, e;

  for (i=1; i<=500; i++)//for loop till N numbers
  {
     a += 1;//Increment condition
     for (j=1; j<=500; j++)//For loop till N numbers
     {
        b += 1;//Increment condition
     for (k=1; k<=500; k++)//For loop till N numbers
     {
        e = ((a*a) + (b*b));//Adding sum of square of two different variables
        d = sqrt(e);//Finding root
        c = int(d);//Type casting into Int
        if ((c == d) && (c <=500))//Condition check
           cout << "a = " << a << "\t\t b = " << b << "\t\t c = " << c << endl;//Print condition
	}
     }
  }

  return 0;
}
