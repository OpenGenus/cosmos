#include <iostream>
class BinomialCoefficient
{
public:
    BinomialCoefficient(unsigned int n, unsigned int k) : n(n), k(k) { }

    unsigned int recursiveBinomialCoefficientMethod(int n, int k);
private:
    unsigned int n, k;
};
unsigned int BinomialCoefficient :: recursiveBinomialCoefficientMethod(int n, int k)
{
    if(k == n or k == 0)
        return 1;

    return (recursiveBinomialCoefficientMethod(n - 1, k - 1) + recursiveBinomialCoefficientMethod(n - 1, k));
}
int main()
{
    unsigned int valueOfN, valueOfK;
    std::cout << "\nEnter the value of n : ";
    std::cin >> valueOfN;
    std::cout << "\nEnter the value of k : ";
    std::cin >> valueOfK;
    BinomialCoefficient aBinoCoeff(valueOfN, valueOfK);
    std::cout << "Value of C(" << valueOfN << ", " << valueOfK << ") : " << aBinoCoeff.recursiveBinomialCoefficientMethod(valueOfN, valueOfK);
}
