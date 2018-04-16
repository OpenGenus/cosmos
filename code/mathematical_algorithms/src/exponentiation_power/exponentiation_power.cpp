#include <ext/numeric>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;
int main()
{
    long long base, exp;
    cin >> base >> exp;
    cout << power(base, exp) << endl;
    return 0;
}
