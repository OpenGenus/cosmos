#include<iostream> 
using namespace std; 
  
// function to find factorial of given number 

unsigned int factorial(unsigned int n) 
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1; 
    }
} 
