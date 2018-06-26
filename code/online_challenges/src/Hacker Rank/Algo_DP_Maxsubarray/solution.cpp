#include<bits/stdc++.h>
using namespace std;

int main() 
    {  //t is the number of test case
        int t;
        cin>>t;
        while(t--){
            //n is the size of array
            int n;
            cin>>n;
            //arr is vector of size n
            vector <int> arr(n);
            //This Algo is Kaden algorithm 
            //Also known as Minimum Sum Subarray
            int flag=0;
            for(int i=0;i<n;i++){
                cin>>arr[i];
                if(arr[i]>=0)
                flag++;
            }
            if(flag==0){
            sort(arr.begin(),arr.end());
            cout<<arr[n-1]<<" "<<arr[n-1]<<endl;
            continue;
            }
        
            int sum,ans,ans1;
            sum=ans=ans1=0;
            for(int i=0;i<n;i++){
                if(sum+arr[i]>0)
                    sum=sum+arr[i];
                else
                    sum=0;
                if(arr[i]>=0)
                    ans1=ans1+arr[i];
                
                ans=max(ans,sum);
        }
        
        cout<<ans<<" "<<ans1<<endl;
    }  
    return 0;
}
