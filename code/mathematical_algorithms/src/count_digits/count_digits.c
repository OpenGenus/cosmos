#include<stdio.h>   //Pre-defined Libraries
// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)

int countDigits(unsigned long n)  //Function to count no of digits
{
    if(n == 0) { // Primary Condition checking
      return (1);
    }
    int count = 0;  //Initializing
     while(n != 0) { //While loop till not equal to 0
      count++;
	n /= 10;
     }
       return (count);
  }

int main()    //Main function
{
   unsigned long n;   
   printf("\nEnter a number\n"); //Print condition	
   scanf("%lu", &n); //Taking input from user
   printf("\nThe number of digits is --> %d\n", countDigits(n)); //Print condition
   return (0); //return statement
}
