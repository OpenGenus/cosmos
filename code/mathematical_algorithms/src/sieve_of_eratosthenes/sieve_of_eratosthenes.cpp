#include <iostream>
#include <vector>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
            // Update all multiples of p
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// Driver Program to test above function
int main()
{
    int n;
    cout << "Enter the number";
    cin >> n;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    cout << "\n";
    return 0;
}
