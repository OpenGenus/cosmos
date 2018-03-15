#include <iostream>

// Part of Cosmos by OpenGenus Foundation
int bitwiseAddition(int n, int m)
{
    while (m != 0)
    {
        int i = n & m;  // Variable i keeps track of bits that carry over
        n = n ^ m;      // This adds up the individual bits
        m = i << 1;     // Shift carry over bits so they can be added 
    }
    return n;
}


int bitwiseAdditionRecursive(int n, int m)
{
    if (m == 0)
        return n;
    else
    {
        int i = n & m;
        return bitwiseAdditionRecursive(n ^ m, i << 1);
    }
}

int main()
{
    int n = 10;
    int m = 5;
    std::cout << bitwiseAddition(n, m) << "\n"; 
    std::cout << bitwiseAdditionRecursive(n, m) << "\n";
}
