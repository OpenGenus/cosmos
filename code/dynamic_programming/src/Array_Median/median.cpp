#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

float median(int n, vector<int> arr)
{
    if (n % 2 != 0)
        return (float)arr[n / 2];

    return ((float)(arr[(n - 1) / 2] + arr[n / 2]) / 2);
}

int main()
{
    int n;
    cout<<"Enter size of the Array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter "<<n<<" integers";
    for (int i = 0 ; i < n ; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    cout<<"Median= "<<median(n, arr);
    return 0;
}
