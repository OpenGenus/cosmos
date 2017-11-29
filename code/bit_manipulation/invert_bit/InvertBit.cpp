#include <iostream>
#include <bitset>

using namespace std;
//Part of Cosmos by OpenGenus Foundation
int invertBit(int n, int numBit)
{
    n ^= 1 << numBit;
    return n;
}

int main()
{
    int numeric, numberBit, res;
    cout << "Enter numeric: "<<endl;
    cin >> numeric;
    bitset<32> bs(numeric);
    cout << bs << '\n';
    cout << "Enter number bit: "<<endl;
    cin >> numberBit;
    res = invertBit(numeric, numberBit);
    bitset<32> bsRes(res);
    cout << res << endl;
    cout << bsRes << endl;
    return 0;
}
