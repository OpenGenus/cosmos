#include <bits/stdc++.h>
using namespace std;
  
int isAbundant(int x) 
{ 
    int sum = 0;
    for(int i = 1; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            if((x / i) == i)
            {
                sum += i;
            }
            else
            {
                sum += i + (x / i);
            }
        }
    }
    sum -= x;
    if(sum > x) 
    {
        return true;
    }
    return false;
} 

int main()
{
    int max = 28123;
    vector<int> abundant;
    for(int i = 1; i <= max; i++)
    {
        if(isAbundant(i))
        {
            abundant.push_back(i);
        }
    }
    int isSumAbundant[max + 1] = {};
    for(int i = 0; i < abundant.size(); i++)
    {
        for(int j = i; j < abundant.size(); j++)
        {
            if(abundant[i] + abundant[j] <= max)
            {
                isSumAbundant[abundant[i] + abundant[j]] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= max; i++)
    {
        if(isSumAbundant[i] == 0)
        {
            ans += i;
        }
    }
    cout << ans;
}
