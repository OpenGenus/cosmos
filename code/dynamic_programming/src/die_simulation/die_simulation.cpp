// Part of OpenGenus cosmos

#define ll long long
const int mod = 1e9+7;

// Function to add in presence of modulus. We find the modded answer 
// as the number of sequences becomes exponential fairly quickly
ll addmod(ll a, ll b)
{ 
    return (a%mod + b%mod) % mod;
}

ll dieSimulator_util(int dex, vector<int>& maxroll, int noOfTimes, int prev, vector<vector<vector<ll> > >& dp, int n){

    // Simulations are 0 indexed ie. 0 to n-1. Hence return 1 when n is reached  
    if(dex==n) 
        return 1;

    // If for the dex'th simulation, the number of sequences has already been found, return it.
    if(dp[dex][noOfTimes][prev] != -1) 
        return dp[dex][noOfTimes][prev]%mod;

    // Initialise answer to 0.
    int ans=0;
    
    // Put all the digits in the dex'th simulation and for each of them,
    // move forward ie. do (dex+1)th simulation. 
    for(int i=0;i<6;i++)
    {
        // Check if the current digit is the same as previous one
        if(i == prev) 
        {   
            /*
             Check if the number of times it has occurred has become equal to the allowed number of times. If yes, then 
             don't put that digit, otherwise put that digit, add one to the noOfTimes it has occurred and move on.
             */ 
            if(noOfTimes < maxroll[i]) 
                ans = addmod(ans, dieSimulator_util(dex + 1, maxroll, noOfTimes + 1, prev, dp, n));
        }

        else 
        {
            ans = addmod(ans, dieSimulator_util(dex + 1, maxroll, 1, i, dp, n));
        }
    }

    // Record the answer
    dp[dex][noOfTimes][prev] = ans;

    return ans;
}   
int dieSimulator(int n, vector<int>& maxRolls) {

  
  
    // Loop over maxRolls array to find the maximum number of times a digit can be rolled. 
    int maxi = 0;
    for(int i=0;i<maxRolls.size();i++)
    {
        if(maxRolls[i] > maxi) 
            maxi = maxRolls[i];
    }
    
    /*
     Initialise a 3d DP table with -1 where the row denotes the ith roll simulation, the 
     column denotes the number of consecutive times the digit in depth has occurred and the 
     depth denotes the number of distinct digits.
    */ 
    vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(maxi+1, vector<ll>(7, -1)));
    
    /*
     For the first call, 
     current index = 0
     noOfTimes it has occurred = 0 
     no of simulation = 6
    */
    return dieSimulator_util(0, maxRolls, 0, 6, dp, n);
}
