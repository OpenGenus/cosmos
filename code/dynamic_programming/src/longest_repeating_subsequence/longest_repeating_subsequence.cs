using System; 

class LongestRepeatingSubsequence 
{ 
    static int longestRepeatingSubsequence(string str) 
    { 
        int n = str.Length; 
        int [,]dp = new int[n + 1,n + 1]; 

        for (int i = 1; i <= n; i++) 
        { 
            for (int j = 1; j <= n; j++) 
            { 
                if (str[i - 1] == str[j - 1] && i != j) 
                    dp[i, j] = 1 + dp[i - 1, j - 1];		 
                else
                    dp[i, j] = Math.Max(dp[i,j - 1], dp[i - 1,j]); 
            } 
        } 
        
        return dp[n,n]; 
    } 

    public static void Main () 
    { 
        string str = "aabb"; 
        Console.Write("Length of LRS : " + longestRepeatingSubsequence(str)); 
    } 
} 
