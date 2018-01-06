/* Part of Cosmos by OpenGenus Foundation */

#ifndef SUBSET_SUM_TEST
#define SUBSET_SUM_TEST

#include <iostream>
#include <list>
#include <cassert>
#include "../../src/subset_sum/subset_sum.cpp"

int
main()
{
    using namespace std;

    int vz[0];
    int v[] = {1, 2, 15, 8, 5};
    list<int> l{1, 2, 15, 8, 5};

    assert(isSubsetSum(vz, vz, 0));
    assert(isSubsetSum(v, v + sizeof(v) / sizeof(v[0]), 13));
    assert(isSubsetSum(l.begin(), l.end(), 13));
    assert(isSubsetSum(vz, vz, 13) == false);
    assert(isSubsetSum(v, v + sizeof(v) / sizeof(v[0]), 4) == false);
    assert(isSubsetSum(l.begin(), l.end(), 4) == false);

    return 0;
}

#endif // SUBSET_SUM_TEST
