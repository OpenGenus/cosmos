#include<iostream>
class CarmichaelNumber
{
public:
    CarmichaelNumber(unsigned int number_) : number_(number_){}
    unsigned int calculateGCD(unsigned int num1, unsigned int num2);
    unsigned int calculatePower(unsigned int base, unsigned int exponent, unsigned int MOD);
    bool calculateCarmichaelNumber();
private:
    unsigned int number_;
};
unsigned int CarmichaelNumber::calculateGCD(unsigned int num1, unsigned int num2)
{
    //Euclidean algorithm
    if (num1 == 0)
        return num2;
    return calculateGCD(num2 % num1, num1);
}
unsigned int CarmichaelNumber::calculatePower(unsigned int base, unsigned int exponent, unsigned int MOD)
{
    if (exponent == 0)
        return 1;
    unsigned int ans = calculatePower(base, exponent / 2, MOD) % MOD;
    ans = (ans * ans) % MOD;
    if (exponent % 2 == 1)
        ans = (ans * base) % MOD;
    return ans;
}
bool CarmichaelNumber::calculateCarmichaelNumber()
{
    for (int i = 2; i < number_; i++)
    {
        // If i found to be relatively prime to n then
        if (calculateGCD(i, number_) == 1 and calculatePower(i, number_ - 1, number_) != 1)
           return false;
    }
    return true;
}
int main()
{
    unsigned int valueOfN;
    std::cout << "\nEnter the Number to check whether it is Carmichael Number : ";
    std::cin >> valueOfN;
    CarmichaelNumber aCarmichaelNumber(valueOfN);
    bool result = aCarmichaelNumber.calculateCarmichaelNumber();
    if (result)
    {
        std::cout << "\nNumber " << valueOfN << " is a Carmichael Number.\n";
    } else
    {
        std::cout << "\nNumber " << valueOfN << " is not a Carmichael Number.\n";
    }
    return 0;
}
