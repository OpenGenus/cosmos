class Solution{
		
	public:
	void func(vector<vector<int>> &A,vector<int> &arr,int i,int j){
	while(i<A.size() and j>=0){
	    arr.push_back(A[i++][j--]);
	}    
	}
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
	    vector<int>ans;
	    for(int i=0;i<n;i++){
	        func(A,ans,0,i);
	    }
	    for(int i=1;i<n;i++){
	        func(A,ans,i,n-1);
	    }
	    return ans;
		// Your code goes here
	}

}; 
