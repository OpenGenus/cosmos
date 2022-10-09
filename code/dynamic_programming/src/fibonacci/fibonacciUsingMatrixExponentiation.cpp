#include<bits/stdc++.h>
using namespace std;

void multiply(vector<vector<int>> &a, vector<vector<int>> &b)                        // Constant time
{
    int size = a.size();
    vector<vector<int>> ans(size, vector<int>(size, 0));

    int a00 = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    int a01 = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    int a10 = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    int a11 = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = a00;
    a[0][1] = a01;
    a[1][0] = a10;
    a[1][1] = a11;
    
}

void exponentiate(vector<vector<int>> &matrix, vector<vector<int>> &res, int n)                  // Logarithmic time
{
    if(n<=1)
    return;

    exponentiate(matrix, res, n/2);
    multiply(res,res);

    if(n%2 !=0)
    multiply(res,matrix);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix = {{1,1}, {1,0}};
    vector<vector<int>> result = {{1,1}, {1,0}};

    exponentiate(matrix, result, n-1);

    if(n==1)
    cout << 0;
    else
    cout <<  result[0][1];
    
}