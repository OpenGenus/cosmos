// This is a new dynamic programming problem. I have published a research paper
// about this problem under the guidance of Professor Rao Li (University of
// South Carolina, Aiken) along with my friend. The paper has been accepted by
// the Journal of Mathematics and Informatics.The problem is a variation of the
// standard longest common subsequence problem. It says that--> "Suppose there
// are two strings, X and Y. Now we need to find the longest string, which is a
// subsequence of X and a substring of Y."

// Link of the paper--> http://www.researchmathsci.org/JMIart/JMI-v25-8.pdf


#include <iostream>
#include <vector>

class LCSubseqSubstr {
public:
    static std::string LCSS(const std::string& X, const std::string& Y, int m, int n, std::vector<std::vector<int>>& W) {
        int maxLength = 0;    // keeps the max length of LCSS
        int lastIndexOnY = n; // keeps the last index of LCSS in Y
        W = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    W[i][j] = W[i - 1][j - 1] + 1;
                } else {
                    W[i][j] = W[i - 1][j];
                }
                if (W[i][j] > maxLength) {
                    maxLength = W[i][j];
                    lastIndexOnY = j;
                }
            }
        }
        return Y.substr(lastIndexOnY - maxLength, maxLength);
    }
};

int main() {
    std::string X, Y;
    std::cout << "Input the first string: ";
    std::getline(std::cin, X);

    std::cout << "Input the second string: ";
    std::getline(std::cin, Y);

    int m = X.length(), n = Y.length();
    std::vector<std::vector<int>> W1(m + 1, std::vector<int>(n + 1, 0));

    std::cout << "The longest string which is a subsequence of " << X
              << " and a substring of " << Y << " is " << LCSubseqSubstr::LCSS(X, Y, m, n, W1) << std::endl;

    std::cout << "The length of the longest string which is a subsequence of " << X
              << " and a substring of " << Y << " is " << LCSubseqSubstr::LCSS(X, Y, m, n, W1).length() << std::endl;

    return 0;
}
