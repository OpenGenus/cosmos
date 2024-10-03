/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cassert>
#include <functional>
#include <iomanip>
#include <cmath>

template<typename T, std::size_t S>
class SparseTable
{
public:
    /*!
     * \brief Builds a sparse table from a set of static data. It is the user responsibility to delete any allocated memory
     * \param data The static data
     * \param f The function to be applied on the ranges
     * \param defaultValue The default value for the function (e.g. INFINITY for Range Minimum Queries)
     */
    SparseTable(const T* const data, const std::function<T(T, T)>& f, T defaultValue) : f_{f}, data_{data}, defaultValue_{defaultValue} 
    { 
        initializeSparseTable();
    }

    /*!
     * \returns The number of elements in the set of static data
     */
    constexpr std::size_t size() const { return S; }

    /*!
     * \brief Queries the range [l, r] in 0(1) time
     * It can only be used if the function is idempotent(e.g. Range Minimum Queries)
     * \param l The starting index of the range to be queried
     * \param r The end index of the range to be queried
     * \returns The result of the function f applied to the range [l, r]
     */
    const T queryRangeIdempotent(int l, int r) 
    {
        assert(l >= 0 && r < S);

        if (l > r)
            return defaultValue_;
        
        std::size_t length = r - l + 1;
        return f_(sparseTable_[logs_[length]][l], sparseTable_[logs_[length]][r - (1 << logs_[length]) + 1]);
    }

    /*!
     * \brief Queries the range [l, r] in O(log(n)) time
     * It can be used for any function(e.g. Range Sum Queries)
     * \param l The starting index of the range to be queried
     * \param r The end index of the range to be queried
     * \returns The result of the function f applied to the range [l, r]
     */
    const T queryRange(int l, int r) 
    {
        assert(l >= 0 && r < S);

        T ans = defaultValue_;
        while (l < r) 
        {
            ans = f_(ans, sparseTable_[logs_[r - l + 1]][l]);
            l += (1 << logs_[r - l + 1]);
        }
        return ans;
    }

private:
    T sparseTable_ [((int)std::log2(S)) + 1][S];
    const T* const data_;
    const std::function<T(T, T)> f_;
    T defaultValue_;
    int logs_ [S + 1];

    /*
     * Computes and stores log2(i) for all i from 1 to S
     */
    void precomputeLogs() 
    {
        logs_[1] = 0;

        for (int i = 2; i <= S; i++) 
            logs_[i] = logs_[i / 2] + 1;
        
    }

    /*
     * Creates a sparse table from a set of static data
     * This precomputation takes O(nlog(n)) time
     */
    void initializeSparseTable() 
    {

        precomputeLogs();

        for (int i = 0; i <= logs_[S] + 1; i++) 
        {
            for (int j = 0; j + (1 << i) <= S; j++) 
            {
                if (i == 0)
                    sparseTable_[i][j] = data_[j];
                else
                    sparseTable_[i][j] = f_(sparseTable_[i-1][j], sparseTable_[i-1][j + (1 << (i - 1))]);
            }
        }
    }
};


int main() 
{
    // Sparse table for range sum queries with integers
    {
        int data [] = { 4, 4, 6, 7, 8, 10, 22, 33, 5, 7 };
        std::function<int(int, int)> f = [](int a, int b) { return a + b; };
        SparseTable<int, 10> st(data, f, 0);

        std::cout << st.queryRange(3, 6) << std::endl;
        std::cout << st.queryRange(6, 9) << std::endl;
        std::cout << st.queryRange(0, 9) << std::endl;
    }

    // Sparse table for range minimum queries with doubles
    {

        double data [] = { 3.4, 5.6, 2.3, 9.4, 4.2 };
        std::function<double(double, double)> f = [](double a, double b) { return std::min(a, b); };
        SparseTable<double, 5> st(data, f, 10e8);

        std::setprecision(4);

        std::cout << st.queryRangeIdempotent(0, 3) << std::endl;
        std::cout << st.queryRangeIdempotent(3, 4) << std::endl;
        std::cout << st.queryRangeIdempotent(0, 4) << std::endl;

    }

    return 0;
}
