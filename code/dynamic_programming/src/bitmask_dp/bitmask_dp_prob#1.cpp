/* Part of Cosmos by OpenGenus Foundation */
/* Problem Statement: 
   
   There are k types ties, uniquely identified by id from 1 to k. n ppl are 
   invited to a party. Each of them have a collection of ties. To look unique,
   they decide that none of them will wear same type of tie. Count the number 
   of ways this is possible.

   Constraints: 
   1<=k<=100
   1<=n<=10
*/

#include <iostream>
#include <vector>

using namespace std;

long long mod = 1e9 + 7;
vector<int>tieList[105]; //stores list of ppl having tie with id i 
vector<vector<long long> >dp(1030,vector<long long>(15,-1));
int total;

//mask = set of ppl, curTie = current tie-id 
long long countWays(int mask, int curTie){
    if(total == mask)//found a way to assign unique ties to different ppl
        return 1;

    if(curTie > 100)//if tie id exceeds the highest available tie-id
        return 0;
    
    //if the query is already processed
    if(dp[mask][curTie]!=-1)
        return dp[mask][curTie];
    
    long long notTake = countWays(mask,curTie+1)%mod; //number of ways to not take the curTie 
    long long take;
    //trying all possible ways to take the curTie
    for(auto p : tieList[curTie]){
        if(mask & (1<<p)) //if p is already wearing a tie, he cannot wear the curTie
            continue;
        take+=countWays(mask|(1<<p), curTie+1); 
        take%=mod;
    }
    long long totWays = (take + notTake)%mod;
    return dp[mask][curTie] = totWays;
}

void solve(int n){
    total = (1<<n) - 1;
    int x,m;
    for(int i=0;i<n;i++){
        cin>>m; //number of types of ties available with i-th person
        for(int j=0;j<m;j++){
            cin>>x; //tie id
            tieList[x].push_back(i);
        }
    }
    long long ans = countWays(0, 1); 
    cout<<ans<<"\n";
}

int main(){
    int n; cin>>n;
    solve(n);
    return 0;
}
