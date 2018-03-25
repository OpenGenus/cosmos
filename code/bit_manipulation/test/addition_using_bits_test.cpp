#include <assert.h>
#include "./../src/addition_using_bits/addition_using_bits.cpp"

// Part of Cosmos by OpenGenus Foundation
int main()
{
    // Testing bitwiseAddition function
    assert(bitwiseAddition(10, 5) == (10 + 5));
    assert(bitwiseAddition(5, 10) == (5 + 10));
    assert(bitwiseAddition(0, 1) == (0 + 1));
    assert(bitwiseAddition(2, 0) == (2 + 0));
    assert(bitwiseAddition(-27, 3) == (-27 + 3));
    assert(bitwiseAddition(27, -3) == (27 + -3));
    assert(bitwiseAddition(-1, -1) == (-1 + -1));

    // Testing bitwiseAdditionRecursive function
    assert(bitwiseAdditionRecursive(2, 3) == (2 + 3));
    assert(bitwiseAdditionRecursive(3, 2) == (3 + 2));
    assert(bitwiseAdditionRecursive(1, 0) == (1 + 0));
    assert(bitwiseAdditionRecursive(0, 3) == (0 + 3));
    assert(bitwiseAdditionRecursive(25, -50) == (25 + -50));
    assert(bitwiseAdditionRecursive(-25, 50) == (-25 + 50));
    assert(bitwiseAdditionRecursive(-5, -10) == (-5 + -10));
    std::cout << "Testing Complete" << "\n";
}
