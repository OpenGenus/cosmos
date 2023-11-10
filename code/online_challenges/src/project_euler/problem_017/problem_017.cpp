#include <bits/stdc++.h>
using namespace std;

int num_letters_func(int n)
{
    int num_letters[91];
    num_letters[1] = 3;
    num_letters[2] = 3;
    num_letters[3] = 5;
    num_letters[4] = 4;
    num_letters[5] = 4;
    num_letters[6] = 3;
    num_letters[7] = 5;
    num_letters[8] = 5;
    num_letters[9] = 4;
    num_letters[10] = 3;
    num_letters[11] = 6;
    num_letters[12] = 6;
    num_letters[13] = 8;
    num_letters[14] = 8;
    num_letters[15] = 7;
    num_letters[16] = 7;
    num_letters[17] = 9;
    num_letters[18] = 8;
    num_letters[19] = 8;
    num_letters[20] = 6; 
    num_letters[30] = 6;
    num_letters[40] = 5;
    num_letters[50] = 5;
    num_letters[60] = 5;
    num_letters[70] = 7;
    num_letters[80] = 6;
    num_letters[90] = 6;
    if(n <= 19)
    {
        return num_letters[n];
    }
    else if(n <= 99)
    {
        int first = n / 10, second = n % 10;
        int ret = num_letters[first * 10];
        if(second != 0)
        {
            ret += num_letters[second];
        }
        return ret;
    }
    else if(n <= 999)
    {
        int first = n / 100;
        int ret = num_letters[first] + 7;
        if(n % 100 == 0)
        {
            return ret;
        }
        else 
        {
            return ret + 3 + num_letters_func(n % 100);
        }
    }
    else
    {
        // if n = 1000
        return 11;
    }
}

int main()
{
    int n = 1000;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += num_letters_func(i);
    }
    cout << ans;
}
