/* Part of Cosmos by OpenGenus Foundation
 * Problem: to find the n-th ugly number.
 * Output: n-th ugly number.
 */
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int ugly_number(unsigned int input)
{
    unsigned int uglyNumbers[input];  //To store the ugly numbers
    unsigned int indexForNextMultipleOf2 = 0;
    unsigned int indexForNextMultipleOf3 = 0;
    unsigned int indexForNextMultipleOf5 = 0;
    unsigned int nextMultipleOf2 = 2;
    unsigned int nextMultipleOf3 = 3;
    unsigned int nextMultipleOf5 = 5;
    unsigned int nextUglyNumber = 1;
	
    uglyNumbers[0] = 1;  //Assignes first ugly number as 1
	
	//loops through until the intened input to get the ugly number
    for(unsigned int i = 1; i < input; i++)
    {		
        nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));

        uglyNumbers[i] = nextUglyNumber;

		//If the ugly number is same as any of the multiples, 
		//icrements the index for that multiple and updates the next multiple
        if(nextUglyNumber == nextMultipleOf2)
        {
            indexForNextMultipleOf2 += 1;
            nextMultipleOf2 = uglyNumbers[indexForNextMultipleOf2]*2;
        }
        if(nextUglyNumber == nextMultipleOf3)
        {
            indexForNextMultipleOf3 += 1;
            nextMultipleOf3 = uglyNumbers[indexForNextMultipleOf3]*3;
        }
        if(nextUglyNumber == nextMultipleOf5)
        {
            indexForNextMultipleOf5 += 1;
            nextMultipleOf5 = uglyNumbers[indexForNextMultipleOf5]*5;
        }
    }
	
   
    return nextUglyNumber;  //returns the nth ugly number
}

int main()
{
    unsigned int n = 15;
    cout << n << "th ugly number is: " << ugly_number(n) << endl;
}