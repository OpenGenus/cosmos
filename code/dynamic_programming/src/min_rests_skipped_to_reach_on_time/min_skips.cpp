// Part of Cosmos by OpenGenus Foundation 

#include<bits/stdc++.h>

int minSkips(vector<int>& dist, int speed, int reachTime) 
{
    /* 
    dist: array containing lengths of roads
    speed: the constant speed of travel
    reachTime: the time before/at which you have to reach the office.
    You start at time=0.
    */

    int n = dist.size();
    double time[n];
    
    // Find times taken to cover the roads.
    for(int i=0; i<n ; i++)
    {
        time[i] = dist[i]*1.0/speed;
    }
    
    
    // Make a dp table where dp[i][j]=minimum time to cover i roads using j skips
    double dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    /*
    Note that, while taking ceiling and floor of floats and doubles, we can get precision errors due to inability of 
    computers to represent floating point numbers precisely in memory. This is why we subtract a very small number 
    eps (epsilon) while taking ceiling of float. Eg. ceil(1.0000000001)=2 which is unintended in our case.
    */
    double eps = 0.00000001;
    
    // The dp table is going to be a lower triangular matrix as the number
    // of skips cannot exceed the number of roads.
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<=i;j++)
        {
            
            // cover road 0 with 0 skips
            if(i == 0 && j == 0) 
                dp[i][j]=time[i];

            // no sop is skipped
            else if (j == 0) 
                dp[i][0] = ceil(dp[i-1][0]- eps)+time[i];

            // all the stops are skipped
            else if (i == j) 
                dp[i][j] = dp[i-1][j-1]+time[i];

            // we've used j skips to cover i roads 
            else 
                dp[i][j] = min( ceil (dp[i-1][j] - eps), dp[i-1][j-1]) + time[i];
        } 
    }
      
    // check the minimum number of skips required to reach on time 
    for(int j=0;j<n;j++)
    {
        if( dp[n-1][j] <= reachTime ) 
            return j;
    }
    
    // we cannot reach on time even if we skip all stops.
    return -1;
}
