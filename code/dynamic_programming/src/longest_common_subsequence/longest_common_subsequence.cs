using System; 

class LongestCommonSubsequence
{ 
    static int lcs(char[] x, char[] y, int x_len, int y_len) 
    { 
        int [,]dp = new int[x_len + 1, y_len + 1]; 

        for (int i = 0; i <= x_len; i++) 
        { 
            for (int j = 0; j <= y_len; j++) 
            { 
                if (i == 0 || j == 0) 
                    dp[i, j] = 0; 
                else if (x[i - 1] == y[j - 1]) 
                    dp[i, j] = dp[i - 1, j - 1] + 1; 
                else
                    dp[i, j] = max(dp[i - 1, j], dp[i, j - 1]); 
            } 
        }

        return dp[x_len, y_len]; 
    } 

    static int max(int a, int b) 
    { 
        return (a > b)? a : b; 
    } 

    public static void Main() 
    { 
        String s1 = "AGGTAB"; 
        String s2 = "GXTXAYB"; 

        char[] a = s1.ToCharArray(); 
        char[] b = s2.ToCharArray(); 
        int a_len = a.Length; 
        int b_len = b.Length; 

        Console.Write("Length of LCS : " + lcs(a, b, a_len, b_len)); 
    } 
} 
