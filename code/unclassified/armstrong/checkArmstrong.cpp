#include <bits/stdc++.h>
using namespace std;
int power(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2 == 0)
        return power(x, y/2) * power(x, y/2);
    return x*power(x, y/2)*power(x, y/2);
}
int count(int x)
{
    int n = 0;
    while(x != 0) {
        n++;
        x = x/10;
    }
    return n;
}
bool isArmstrong(int x)
{
    int n = count(x);
    int temp = x;
    int sum = 0;
    while(temp != 0)
    {
        int r = temp % 10;
        sum += power(r, n);
        temp /= 10;
    }
    if(sum == x) {
        return true;
    }
    return false;
}
int main() {
    int x;
    cin >> x;
    cout << isArmstrong(x) << endl;
    return 0;
}