/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>

int main() {
    std::cin.tie(NULL);
    int dp[100005][3];
    int a[3]={1,2,4};
    for (int  i= 0; i < 3; i++) 
        dp[0][i] = 1; 
    int x,y;
    for(int i=1;i<100005;i++) 
    { 
        for(int j=0;j<3;j++) 
        {
            x = ((i-a[j])>=0) ? dp[(i-a[j])][j] : 0; 
            y = (j >= 1) ? dp[i][j - 1] : 0; 
            dp[i][j] = x + y; 
        } 
    } 
    int t;
    std::cin>>t;
    while(t--)
    {
        int p,d;
        std::cin>>p>>d;
        int n=p-d;
        std::cout<<dp[n][2]<<std::endl;
    }
    return 0;
}

