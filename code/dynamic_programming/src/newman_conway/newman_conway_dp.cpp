#include <iostream>
class NewmanConwaySequence
{
public:
    NewmanConwaySequence(unsigned int n) : n(n) {}

    void calculateNewmanConwaySequenceTermDP(bool flag);

private:
    unsigned int n;
};
void NewmanConwaySequence::calculateNewmanConwaySequenceTermDP(bool flag)
{
    if(flag == true)
    {
        unsigned int ncs[n + 1];
        ncs[0] = 0;
        ncs[1] = 1;
        ncs[2] = 1;

        for (int i = 3; i <= n; i++)
            ncs[i] = ncs[ncs[i - 1]] + ncs[i - ncs[i - 1]];
        std::cout << "\nNewman Conway Sequence with " << n << " elements : ";
        for(int i = 1; i <= n; i++)
            std::cout << ncs[i] << " ";
    }
    else
    {
        unsigned int ncs[n + 1];
        ncs[0] = 0;
        ncs[1] = 1;
        ncs[2] = 1;

        for (int i = 3; i <= n; i++)
            ncs[i] = ncs[ncs[i - 1]] + ncs[i - ncs[i - 1]];

        std::cout << "\nNewman Conway Sequence term at " << n << " indexed : ";
        std::cout << ncs[n];
    }
}

int main()
{
    unsigned int nValue, value;
    bool flag;
    std::cout << "\nEnter the Index of Newman Conway Sequence : ";
    std::cin >> nValue;
    NewmanConwaySequence aNewmanConwaySequenceoj(nValue);
    std::cout << "\nEnter the non-zero to generate the Newman Conway Sequence or zero to generate particular term in Newman Conway Sequence : ";
    std::cin >> value;
    if(value)
        flag = true;
    else
        flag = false;

    if(flag == true)
        aNewmanConwaySequenceoj.calculateNewmanConwaySequenceTermDP(true);
    else
        aNewmanConwaySequenceoj.calculateNewmanConwaySequenceTermDP(false);
}
