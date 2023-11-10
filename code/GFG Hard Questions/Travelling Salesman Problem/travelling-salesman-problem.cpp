//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define setofCities setOfCities
class Solution {
public:
int fun(int &ans,int n,int last,int i,int value,vector<vector<int>> &cost,vector<bool> &visited,int cnt,vector<vector<int>> &dp){
    // if(m.find({visited,i})!=m.end()) return m[{visited,i}];
    if(dp[last][i]!=-1) return dp[last][i];
    int a=INT_MAX;
    for(int j=0;j<n;j++){
        if(i!=j&&visited[j]==false){
            visited[j]=true;
            int temp=last;
            temp=(last|(1<<i));
            a=min(a,fun(ans,n,temp,j,value+cost[i][j],cost,visited,cnt+1,dp)+cost[i][j]);
            visited[j]=false;
        }
    }
    if(cnt==n){
        return cost[i][0];
    }
    return dp[last][i]=a;
}

int tsp(vector<vector<int> > &dist, int setOfCities, int city, int n,vector<vector<int>> &dp) {

//base case

if(setofCities == (1<<n) -1){ //return the cost from the city to the original
return dist[city][0];

} if(dp[setofCities] [city] !=-1){return dp[setofCities] [city]; } 

//otherwise try all possible options
int ans = INT_MAX;

for(int choice=0; choice<n; choice++){ //need to check if city is visited or not 
if((setofCities & (1<<choice))==0){
int subProb = dist [city] [choice] + tsp (dist, setOfCities |(1<<choice), choice,n,dp);
ans = min(ans, subProb);
}
}
dp [setofCities] [city] =ans;
return ans; 

}

int total_cost(vector<vector<int>>cost){
    // Code here
    int ans=INT_MAX;
    int n=cost.size();
    int num=(1<<(n+1))-1;
    vector<vector<int>> dp(num+1,vector<int> (n,-1));
    return  tsp (cost, 1, 0,n,dp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends