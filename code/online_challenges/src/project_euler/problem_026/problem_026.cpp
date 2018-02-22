#include <bits/stdc++.h>
using namespace std;

int main ()
{

   int remainder, value, position, sequenceLength = 0;

   for (int i = 1000; i > 0; i--)
   {

       int cycleCheckArray[i];

       for (int j = 0; j < i; j++)
	       cycleCheckArray[j] = 0;

       remainder = 1, value = 1, position = 0;

       while (1)
	   {

	       value = remainder * 10;
	       remainder = value % i;

	    if (cycleCheckArray[remainder])
	    {
	       sequenceLength = position - cycleCheckArray[remainder];
	       break;
	    }

	    cycleCheckArray[remainder] = position;
	    position++;

   }

       if (sequenceLength == i - 1)
       {
	       cout << i;
	       return 0;
       }
   }
}
