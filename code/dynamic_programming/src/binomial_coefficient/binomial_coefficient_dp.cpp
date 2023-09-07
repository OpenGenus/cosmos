#include <iostream>
class BinomialCoefficient
{
public:
    BinomialCoefficient(unsigned int n, unsigned int k) : n(n), k(k) { }

    unsigned int DPBinomialCoefficientMethod(int n, int k);

private:
    unsigned int n, k;
};
unsigned int BinomialCoefficient :: DPBinomialCoefficientMethod(int n, int k)
{
    unsigned int nCr[k + 1];
    for (int l = 0; l < k + 1; ++l)
        nCr[l] = 0;
    nCr[0] = 1;
    for (int p = 1; p <= n; p++)
    {
        for (int q = std::min(p, k); q > 0; q--)
            nCr[q] = nCr[q] + nCr[q - 1];
    }
    return nCr[k];
}
int main()
{
    unsigned int valueOfN, valueOfK;
    std::cout << "\nEnter the value of n : ";
    std::cin >> valueOfN;
    std::cout << "\nEnter the value of k : ";
    std::cin >> valueOfK;
    BinomialCoefficient aBinoCoeff(valueOfN, valueOfK);
    std::cout << "Value of C(" << valueOfN << ", " << valueOfK << ") : " << aBinoCoeff.DPBinomialCoefficientMethod(valueOfN, valueOfK);
}
