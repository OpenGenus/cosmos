#include <bits/stdc++.h>
using namespace std;
long long int string_end_with_zero[100000],string_end_with_one[100000];
long long int no_of_string(long long int n)
{
    string_end_with_zero[0] = string_end_with_one[0] = 1;
    for (long long int i = 1; i < n; i++)
    {
        string_end_with_zero[i] = string_end_with_zero[i-1] + string_end_with_one[i-1];
        string_end_with_one[i] = string_end_with_zero[i-1];
    }
}
int main()
{
        long long int n;
        cin >> n;
        no_of_string(n);
        cout << string_end_with_zero[n-1]+string_end_with_one[n-1] << endl;
        return 0;
}

