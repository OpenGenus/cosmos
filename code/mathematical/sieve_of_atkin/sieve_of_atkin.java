/**
 ** Java Program to implement Sieve Of Atkin Prime generation
 **/
 
import java.util.Scanner;
 
/** Class SieveOfAtkin **/
public class  SieveOfAtkin
{
    /** Function to calculate all primes less than n **/
    private boolean[] calcPrimes(int limit)
    {
        /** initialize the sieve **/
        boolean[] prime = new boolean[limit + 1];
        prime[2] = true;
        prime[3] = true;
        int root = (int) Math.ceil(Math.sqrt(limit));
 
        /** put in candidate primes: 
           integers which have an odd number of
           representations by certain quadratic forms **/
        for (int x = 1; x < root; x++)
        {
            for (int y = 1; y < root; y++)
            {
                int n = 4 * x * x + y * y;
                if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                    prime[n] = !prime[n];
                n = 3 * x * x + y * y;
                if (n <= limit && n % 12 == 7)
                    prime[n] = !prime[n];
                n = 3 * x * x - y * y;
                if ((x > y) && (n <= limit) && (n % 12 == 11))
                    prime[n] = !prime[n];
            }
        }
        /** eliminate composites by sieving, omit multiples of its square **/
        for (int i = 5; i <= root; i++)
            if (prime[i])
                for (int j = i * i; j < limit; j += i * i)
                    prime[j] = false;
 
        return prime;
    }
    /** Function to get all primes **/
    public void getPrimes(int N)
    {
        boolean[] primes = calcPrimes(N);
        display(primes);
    }
    /** Function to display all primes **/
    public void display(boolean[] primes)
    {
        System.out.print("\nPrimes = ");
        for (int i = 2; i < primes.length; i++)
            if (primes[i])
                System.out.print(i +" ");
        System.out.println();
    }
    /** Main function **/
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Sieve Of Atkin Prime Algorithm Test\n");
        /** Make an object of SieveOfAtkin class **/
         SieveOfAtkin soa = new  SieveOfAtkin();
        /** Accept n **/
        System.out.println("Enter number to find all primes less than the number\n");
        int n = scan.nextInt();
        soa.getPrimes(n);        
    }
}
