// dynamic programming | edit distance | Java
// Part of Cosmos by OpenGenus Foundation

import java.util.Scanner;

public class edit_distance {
    public static int edit_DP(String s,String t){
        int l1 = s.length();
        int l2 = t.length();
        
        int dp[][] = new int[l1+1][l2+1];

        for(int i=0; i<=l2; i++)
            dp[0][i] = i;

        for(int i=0; i<=l1; i++)
            dp[i][0] = i;

        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s.charAt(l1-i) == t.charAt(l2-j))
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + Math.min( dp[i-1][j-1] , Math.min (dp[i-1][j] , dp[i][j-1]) );
            }
        }
        return dp[l1][l2];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter first string >> ");
        String a = sc.next();

        System.out.print("Enter second string >> ");
        String b = sc.next();
        
        System.out.println("Edit Distance : " + edit_DP(a,b));
    }
}
