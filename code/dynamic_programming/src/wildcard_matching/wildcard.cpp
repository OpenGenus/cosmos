//Part of Cosmos by OpenGenus Foundation

bool isMatch(string s, string p) {
    
    /*
    s is the string
    p is the pattern containing '?' and '*' apart from normal characters.
    */  

    int m=s.length(), n=p.length();

    bool dp[m+1][n+1];

    // Initialise each cell of the dp table with false
    for(int i=0;i<m+1;i++) 
        for(int j=0;j<n+1;j++) 
            dp[i][j]=false;


    for(int i=0;i<m+1;i++) 
    {
        for(int j=0;j<n+1;j++) 
        {
            // When both string s and pattern p is empty.
            if (i==0 && j==0) 
                dp[i][j]=true;

            // When s is empty
            else if (i == 0)
            {
                dp[i][j]=(p[j-1]=='*' && dp[i][j-1]);
            }

            // When the pattern is empty
            else if (j == 0) 
                dp[i][j]=false;

            // When the characters p[j-1] matches character s[i-1] or when 
            // p[j-1] is a '?'. Both will consume 1 character of s.
            else if (p[j-1] == s[i-1] || p[j-1] == '?') 
                dp[i][j]=dp[i-1][j-1];

            // p[j-1]='*'
            // A '*' can consume 0 or multiple characters.
            else if (p[j-1]=='*') 
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            
            // If p[j-1] is any character other than those above.
            else 
                dp[i][j]=false;
        }
    }
    return dp[m][n];
    }
