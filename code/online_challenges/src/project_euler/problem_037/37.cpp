#include <iostream>
#include <cmath>
using namespace std;

/*
 * Sieve function finds all the primes upto n-1 using Sieve of Erasthosene method.
 * Time Complexity = O(n logn)
 */

void sieve(long long n, bool prime[]) 
{
   prime[0] = prime[1] = false;

   for (int i = 2; i < n; i++) 
       prime[i] = true;

   for (int i = 2; i * i <= n; i++) 
       if (prime[i] == true) 
           for (int j = 2; j * i < n; j++) 
               prime[i * j] = false;
}

/*
 * check_prime checks if a number is prime.
 * Time complexity O(sqrt(n))
 */

bool check_prime(long long num) 
{
   if (num == 2 || num == 3)
       return true;

   if (num == 1 || num == 0)
       return false;
    
   for (int i = 3; i * i <= num; i += 2) 
       if (num % i == 0)
           return false;

   return true;
}

/*
 * check_right checks if number is right truncatable prime number.
 *    Time Complexity O(n logn)
 */

bool check_right(long long num) 
{
   if (check_prime(num) == false)
       return false;

   bool isprime[num + 1];
    
   sieve(num + 1, isprime);
    
   for (int i = num; i > 0; i /= 10) 
       if (isprime[i] == false)
           return false;

   return true;
}

// countdigits counts number of digits in a number.

int countdigits(long long number) 
{
   int count = 0;
    
   for (int i = number; i > 0; i /= 10)
       ++count;
    
   return count;
}

/*
 * check_left checks if a number is left truncatable prime number
 *    Time Complexity O(n logn)
 */

bool check_left(long long num) 
{
   if (check_prime(num) == false) 
       return false;
    
   int cou = countdigits(num);
   bool isprime[num + 1];
    
   sieve(num + 1, isprime);
    
   for (int i = num; i > 0; i--) 
   {
       int mod = pow(10, i);
       
       if (isprime[num % mod] == false) 
           return false;
   }

   return true;
}

/*
 * check_two_way_truncatable checks if a number is right 
 * as well as left truncatable.
 */

bool check_two_way_truncatable(long long num) 
{
   return check_left(num) && check_right(num);
}

int main() 
{
   int counter = 0, count = 0;
   long long sum = 0, num = 11;
   
   while (counter != 11) 
   {  
       if (check_two_way_truncatable(num) == true) 
       {
            counter++;
            sum += num;
            cout << counter << "\t" << num << endl; 
       }
       num += 2;
   }

   cout << "Sum of 11 truncatable primes is " << sum;
}