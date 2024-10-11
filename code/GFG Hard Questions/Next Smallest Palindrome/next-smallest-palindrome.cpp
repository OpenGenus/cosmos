//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int> v(n,0),ans,temp(n,0);
	    int count=0;
	    for(int i=0;i<n;i++){
            if(num[i]==9)
            count++;
	    }
	    
	    if(count==n){
            ans.push_back(1);
	        for(int i=0;i<n-1;i++){
	            ans.push_back(0);
	        }
	        ans.push_back(1);
	        return ans;
	    }
	    if(n==1) return {num[0]+1};
	    int flag=0;
	    for(int i=0;i<n/2;i++){
	        
	        
	        
	         v[n-1-i]=v[i]=num[i];
	        
	        
	    }
	    
	    if(n%2!=0){
	        int i=n/2;
	            if(num[i]<9){
	                v[i]=num[i]+1;
	            }
	            else{
	                int j=i-1;
	                while(num[j]==9){
	                    v[j]=0;
	                    v[n-1-j]=0;
	                    j--;
	                }
	                
	                v[j]=num[j]+1;
	                v[n-1-j]=v[j];
	                v[i]=0;
	            }
	        }
	        else{
	            int i=n/2;
	            i=i-1;
	            if(num[i]<9){
	                v[i]=num[i]+1;
	                v[i+1]=v[i];
	                // cout<<"***"<<endl;
	            }
	            else{
	                int j=i-1;
	                while(num[j]==9){
	                    v[j]=0;
	                    v[n-1-j]=0;
	                    j--;
	                }
	                
	                v[j]=num[j]+1;
	                v[n-1-j]=v[j];
	               // v[i]=0;
	                
	                v[i-1]=num[i-1]+1;
	                v[n-1-(i-1)]=v[i-1];
	                v[i+1]=v[i]=0;
	            }
	        }
	       //   return v;
	     for(int i=0;i<n/2;i++){
	       
	         temp[n-1-i]=num[i];
	         temp[i]=num[i];
	    }
	     if(n%2!=0){
	        int i=n/2;
	            
	                temp[i]=num[i];
	            
	        }
	        else{
	            int i=n/2;
	            i=i-1;
	            if(num[i]<9){
	               // temp[i]=num[i]+1;
	                temp[i+1]=temp[i]=num[i];
	                // cout<<"***"<<endl;
	            }
	            else{
	               // temp[i-1]=num[i-1]+1;
	               // temp[n-1-(i-1)]=temp[i-1];
	                temp[i+1]=temp[i]=num[i];
	            }
	        }
	    count=0;
	    flag=0;
	    int fs=0;
	    for(int i=0;i<n;i++){
	        if(num[i]>temp[i]) {
	         fs=1;   
	        }
	        if(num[i]<temp[i]&&fs==0){
	            flag=1;
	            break;
	        }
	        if(num[i]==temp[i])
	        count++;
	    }
	    if(count==n)
	    flag=0;
	    
	    if(flag==1) return temp;
	    
	   // cout<<num[i]<<" ";
	   // cout<<endl;
	    return v;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends