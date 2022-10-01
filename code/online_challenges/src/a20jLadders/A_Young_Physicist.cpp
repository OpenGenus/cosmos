#include<iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i];
            sum += arr[i];
        }
    }
    if(sum == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}

//REAL SOLUTION
#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z, xsum(0), ysum(0), zsum(0);
    cin >> n;

    while (n--)
    {
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }

    if (xsum == 0 && ysum == 0 && zsum == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}