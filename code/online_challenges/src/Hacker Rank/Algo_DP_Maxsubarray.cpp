#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
        int t;             //t is the number of test case
        cin >> t;
        while(t--)
        {
            int n;             //n is the size of input array
            int sum,ans,ans1;
            sum = ans = ans1 = 0;

            int flag = 0;

            cin >> n;
            vector <int> arr(n);

            for(int i = 0; i < n; i++)
                {
                    cin >> arr[i];
                    if(arr[i] >= 0)
                    
                    flag++;
                }

            if (flag == 0)
                {
                    sort (arr.begin(), arr.end());
                    
                    cout << arr[n-1] << " " << arr[n-1] <<"\n";
                    continue;
                }

            int sum,ans,ans1;
            sum = ans = ans1 = 0;

            for(int i = 0; i < n; i++)
                {
                    if((sum + arr[i]) > 0)
                        sum = sum + arr[i];
                    else
                        sum = 0;
                    if(arr[i] >= 0)
                        ans1 = ans1 + arr[i];

                    ans = max(ans,sum);
                }

        cout << ans << " " << ans1 <<endl;
    }

    return 0;
}
