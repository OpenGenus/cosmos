//Code Copyright: Manish Kumar, E&C, IIT Roorkee
// Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;


vector<int> Prime; //contains prime numbers uptop segMax
void segmentedSieve()
{
    #define segMax 1000000 //till point you want to find Primes. Preferebly pow(10,x)
    #define rootSegMax 1000 //root of segMax
    bool prime[rootSegMax];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= rootSegMax; i++)
        if (prime[i])
            for (int j = i * i; j < rootSegMax; j += i)
                prime[j] = false;

    for (int i = 2; i < rootSegMax; i++)
        if (prime[i])
            Prime.push_back(i);

    int low = rootSegMax;
    // ^^ lower end of current block we are finding primes for
    int high = 2 * rootSegMax;
    // ^^ higher end of current block we are finding primes for
    int tempMax = Prime.size();
    // ^^All non prime numbers will be multiples of these numbers only
    while (low < segMax)
    {
        memset(prime, true, sizeof(prime));
        for (int i = 0; i < tempMax; i++)
        {
            int start = Prime[i] * ceil(1.0 * low / Prime[i]);
            for (int j = start; j < high; j += Prime[i])
                prime[j - low] = false;
        }
        for (int i = 0; i < rootSegMax; i++)
            if (prime[i])
                Prime.push_back( i + low );

        low += rootSegMax;
        high += rootSegMax;
    }
}

int main()
{
    segmentedSieve(); //run it to find primes..
    //Now Prime contains all the prime numbers upto segMax defined in function
    for (size_t i = 0; i < Prime.size(); i++)
        cout << Prime[i] << " ";
    //^^ Prints all the prime numbers

    return 0;
}
