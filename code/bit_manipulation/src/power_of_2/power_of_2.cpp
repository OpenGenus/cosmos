/* Part of Cosmos by OpenGenus Foundation */
/* Created by Shubham Prasad Singh on 12/10/2017 */

/* Check if a number is a power of 2 */
#include <iostream>
using namespace std;
typedef long long ll;

/*
 *  If a power of two number is subtracted by 1
 *  then all the unset bits after the set bit become set,
 *  and the set bit become unset
 *  
 *  For Example : 4(power of 2) --> 100
 *                4-1 --> 3 --> 011       
 * 
 *  So,if a number n is a power of 2 then
 *  (n&(n-1)) = 0
 *  
 *  For Example: 4 & 3 = 0  
 *               and 4 is a power of 2
 *
 *  The expression (n & (n-1)) will not work when n=0
 *  To handle this case , the expression is modified to
 *  (n & (n&(n-1)))
 */
bool isPowerOf2(ll n)
{
    return n && (!(n & (n - 1)));
} 
int main()
{
    ll n;
    cout << "Enter a number\n";
    cin >> n;
    if (isPowerOf2(n))
        cout << "Is a power of 2" << endl;
    else
        cout << "Not a power of 2" << endl;
    return 0;
}
