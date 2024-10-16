#include <iostream>
class NewmanConwaySequence
{
public:
    NewmanConwaySequence(unsigned int n) : n(n) {}
    
    unsigned int calculateNewmanConwaySequenceTermRecur(unsigned int n);
    
private:
    unsigned int n;
};
unsigned int NewmanConwaySequence::calculateNewmanConwaySequenceTermRecur(unsigned int n)
{
    if(n == 1 or n == 2)
        return 1;
    else
        return calculateNewmanConwaySequenceTermRecur(calculateNewmanConwaySequenceTermRecur(n - 1)) + calculateNewmanConwaySequenceTermRecur(n - calculateNewmanConwaySequenceTermRecur(n - 1));
}
int main()
{
    unsigned int nValue;
    std::cout << "\nEnter the Index of Newman Conway Sequence : ";
    std::cin >> nValue;
    NewmanConwaySequence aNewmanConwaySequenceObj(nValue);
    std::cout << "\nValue of term at " << nValue << " indexed in Newman Conway Sequence : " << aNewmanConwaySequenceObj.calculateNewmanConwaySequenceTermRecur(nValue);
}
