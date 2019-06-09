/* Part of Cosmos by OpenGenus Foundation */

#ifndef UNBOUNDED_KNAPSACK_TEST
#define UNBOUNDED_KNAPSACK_TEST

#include <iostream>
#include <cassert>
#include "../../src/unbounded_knapsack/unbounded_knapsack.cpp"

int main()
{
    using namespace std;

    int W = 200;
    int val[] = {10, 40, 50};
    int wt[] = {5, 20, 35};
    int n = sizeof(val) / sizeof(val[0]);

    assert(unboundedKnapsack(W, n, val, wt) == 400);
}

#endif