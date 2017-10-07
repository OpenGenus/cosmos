#include <bits/stdc++.h>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int gcd(int i, int j)
{
        while(j != 0) {
                int x = i;
                i = j;
                j = x % j;
        }
        return i;
}

bool isCoPrime(int i, int j)
{
        return gcd(i,j) == 1;
}

int main()
{
        int i,j;
        cout << "Enter two numbers : ";
        scanf("%d %d", &i, &j);
        cout << isCoPrime(i,j) << endl;
        return 0;
}
