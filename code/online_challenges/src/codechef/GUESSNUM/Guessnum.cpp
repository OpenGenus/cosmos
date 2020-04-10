#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int T;
    std::cin >> T;
    while (T--) {

        long long int A, M;
        std::cin >> A >> M;
        int ans = 0;

        // vector vec will store all the values of N for given A and M
        vector<long long int> vec;

        for (long long int i = 1; i * i <= M; ++i) {
            // finding the divisors of M
            if (M % i == 0) {
                // f1 and f2 are divisors of M
                long long int f1 = i, f2 = M / i;
                long long int d = f1;
                if ((M - d) % A == 0) {
                    long long int N = (M - d) / A;
                    if (N % d == 0) {
                        // pushing the required value of N in vec
                        vec.push_back(N);
                    }
                }
                if (f1 == f2) {
                    continue;
                }
                d = f2;
                if ((M - d) % A == 0) {
                    long long int N = (M - d) / A;
                    if (N % d == 0) {
                        // pushing the required value of N in vec
                        vec.push_back(N);
                    }
                }
            }
        }
        // sorting the vector vec
        sort(vec.begin(), vec.end());

        // printing the final answer
        std::cout << vec.size() - 1 << "\n";
        for (int i = 1; i <= vec.size() - 1; ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

/* Test case
    Input
    3
    3 35
    5 50
    4 65

    Output
    1
    10
    0

    3
    13 15 16
*/
