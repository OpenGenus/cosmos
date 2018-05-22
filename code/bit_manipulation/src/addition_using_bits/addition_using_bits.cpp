#include <iostream>

// Part of Cosmos by OpenGenus Foundation
int bitwiseAddition(int n, int m)
{
    while (m != 0)
    {
        int carry = n & m;  // Variable carry keeps track of bits that carry over
        n = n ^ m;          // This adds up the individual bits
        m = carry << 1;     // Shift carry over bits so they can be added
    }
    return n;
}

int bitwiseAdditionRecursive(int n, int m)
{
    if (m == 0)
        return n;
    else
    {
        int carry = n & m;
        return bitwiseAdditionRecursive(n ^ m, carry << 1);
    }
}
