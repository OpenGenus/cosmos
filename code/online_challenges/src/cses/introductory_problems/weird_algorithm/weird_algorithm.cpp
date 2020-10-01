/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
using namespace std;

#define ll long long int

int main() 
{
    ll num;
    cin >> num;
    while (num != 1)
    {
        cout << num << " ";
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
    }
    cout << num << endl;
    
	return 0;
}