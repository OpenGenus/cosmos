/* 
 * C++ Program to Find Factorial of a Number using Dynamic Programming 
 */
#include <iostream>
#define ll long long
using namespace std;
 
ll result[50] = {0};
/* 
 * Find Factorial of a Number using Dynamic Programming 
 */
ll Factorial(int n)
{
    if (n >= 0) 
    {
        result[0] = 1;
        for (int i = 1; i <= n; ++i) 
        {
            result[i] = i * result[i - 1];
        }
        return result[n];
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<Factorial(n)<<endl;
    return 0;
}
