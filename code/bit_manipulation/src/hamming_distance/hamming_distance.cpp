/*
 *
 * Part of Cosmos by OpenGenus Foundation
 *
 * The Hamming distance between two integers is the number of positions
 * at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 */

int hammingDistance(int x, int y)
{
    int temp = x ^ y;
    int count = 0;
    //count the number of set bits in the xor of two numbers
    while (temp)
    {
        temp = temp & (temp - 1);
        count++;
    }
    return count;
}
