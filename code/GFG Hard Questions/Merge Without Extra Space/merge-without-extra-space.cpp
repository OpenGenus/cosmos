//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            if(n*1LL*m>1e7){
                vector<long long > v;
                for(int i=0;i<n;i++){
                    v.push_back(arr1[i]);
                }
                for(int i=0;i<m;i++){
                    v.push_back(arr2[i]);
                }
                sort(v.begin(),v.end());
                for(int i=0;i<n;i++){
                    arr1[i]=v[i];
                }
                for(int i=0;i<m;i++){
                    arr2[i]=v[i+n];
                }
                return;
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(arr1[j]>arr2[i]){
                        swap(arr1[j],arr2[i]);
                    }
                }
            }
            sort(arr2,arr2+m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends