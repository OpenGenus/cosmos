/* Part of Cosmos by OpenGenus Foundation */

#ifndef SUBSET_SUM_TEST
#define SUBSET_SUM_TEST

#include <iostream>
#include "subset_sum.cpp"

using namespace std;
int
main()
{
    int v[] = {1, 2, 15, 8, 5};

    cout << (isSubsetSum(v, v + sizeof(v) / sizeof(v[0]), 13) ? "possible" : "impossible") << "\n";
    cout << (isSubsetSum(v, v + sizeof(v) / sizeof(v[0]), 4) ? "possible" : "impossible") << "\n";

    return 0;
}

#endif // SUBSET_SUM_TEST
