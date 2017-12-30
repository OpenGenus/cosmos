// Part of Cosmos by OpenGenus Foundation
class LongestCommonSubsequence {
  /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
  int lcs( char[] X, char[] Y, int m, int n ) {
    int L[][] = new int[m+1][n+1];
 
    //L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (int i=0; i<=m; i++) {
      for (int j=0; j<=n; j++) {
        if (i == 0 || j == 0) {
            L[i][j] = 0;
        } else if (X[i-1] == Y[j-1]) {	// if there is a match
            L[i][j] = L[i-1][j-1] + 1;	// increate lcs value by 1
        } else {				// else
            L[i][j] = Math.max(L[i-1][j], L[i][j-1]);	// choose max value till now
        }
      }
    }
  return L[m][n];
  }
 
  public static void main(String[] args) {
    LongestCommonSubsequence lcs = new LongestCommonSubsequence();
    String s1 = "AGGAGTCTAGCTAB";
    String s2 = "AGXGTTXAYBATCGAT";
 
    char[] X=s1.toCharArray();
    char[] Y=s2.toCharArray();
    int m = X.length;
    int n = Y.length;
 
    System.out.println("Length of LCS is" + " " + lcs.lcs( X, Y, m, n ) );
  }
}
 
