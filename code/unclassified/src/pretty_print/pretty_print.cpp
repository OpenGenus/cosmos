// Print concentric rectangular pattern in a 2d matrix.
/*
Input: A = 4.
Output:

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> prettyPrint(int n) {
    std::vector<std::vector<int>> result;
    for (int i = n; i > 0; i--) {
        std::vector<int> temp;
        int num = n;
        if (i != n) {

            for (int k = 0; k < (2 * n - 1 - (2 * i - 1)) / 2; k++) {
                temp.push_back(num);
                num--;
            }
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            temp.push_back(i);
        }
        num = num + 1;
        if (i != n) {
            for (int k = 0; k < (2 * n - 1 - (2 * i - 1)) / 2; k++) {
                temp.push_back(num);
                num++;
            }
        }

        result.push_back(temp);
        temp.clear();
    }

    std::vector<std::vector<int>> res;
    res = result;
    for (int i = res.size() - 2; i >= 0; i--)
        result.push_back(res[i]);
    return result;
}

int main() {
    int n;
    std::cout << "Enter the number : ";
    std::cin >> n;
    std::vector<std::vector<int>> result = prettyPrint(n);
    std::cout << "The matrix is : \n";
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}
