#include <iostream>
#include <vector>
#include <stdexcept>

namespace dynamic
{

/*
 * Error to indicate invalid input
 */
const std::invalid_argument errCatalan("can't have a negative n-th catalan number");

/*
 * NthCatalanNumber returns the n-th Catalan Number
 * Complexity: O(n^2)
 */
long long
nthCatalanNumber(int n)
{
    if (n < 0)
    {
        // doesn't accept negative number
        throw errCatalan;
    }

    std::vector<long long> catalanNumberList;
    catalanNumberList.push_back(1); // first value is 1

    for (int i = 1; i <= n; i++)
    {
        catalanNumberList.push_back(0); // append 0 and calculate

        for (int j = 0; j < i; j++)
        {
            catalanNumberList[i] += catalanNumberList[j] *
                                     catalanNumberList[i - j - 1];
        }
    }

    return catalanNumberList[n];
}

} // namespace dynamic

int
main()
{
    try
    {
        int n = 5;
        std::cout << "5th Catalan number is: "
                  << dynamic::nthCatalanNumber(n)
                  << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
