//Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <cmath>
using namespace std;

// Function to find nth magic numebr
int nthMagicNo(int n)
{
    int pow = 1, answer = 0;

    // Go through every bit of n
    while (n)
    {
        pow = pow * 5;

        // If last bit of n is set
        if (n & 1)
            answer += pow;

        // proceed to next bit
        n >>= 1;  // or n = n/2
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    cout << "nth magic number is " << nthMagicNo(n) << endl;
    return 0;
}
