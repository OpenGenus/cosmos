#include <bits/stdc++.h>
using namespace std;
float Babylonian(float n)
{  float s=n;//initial assumption is number itself
   float error = 0.000001; //this decides the accuracy of answer
   while( (s-n/s) > error )
   {
    s=(s+n/s)/2;
   }
  return s;
}
 
int main()
{
  int n = 60;
  cout<<"Square root of "<<n<<" is "<<Babylonian(n);
  return 0;
}

/*
Output :
Square root of 60 is 7.74597
*/
