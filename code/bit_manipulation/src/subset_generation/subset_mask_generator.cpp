#include <iostream>

typedef unsigned long long ll;

//Loops over all subsets of the bits in to_mask. Except to_mask itself
//For test input (111)
//110
//101
//100
//010
//001
//000

void generate_masks(ll to_mask)
{
    for (int mask = to_mask; mask;)
    {
        --mask &= to_mask;
        std::cout << mask << std::endl;
    }
}

int main()
{
    generate_masks(7);
}
