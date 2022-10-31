#include<bits/stdc++.h>
int maximumWealth(vector<vector<int>>& accounts) {
        int max=0;
        int total=0;
        for(int i=0;i<accounts.size();i++)
        {
            total=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                total+=accounts[i][j];
            }
            if(total>max)
            {
                max=total;
            }
        }
        return max;
    }

