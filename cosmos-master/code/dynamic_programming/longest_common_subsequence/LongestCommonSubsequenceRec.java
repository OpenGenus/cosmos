// Part of Cosmos by OpenGenus Foundation
class LongestCommonSubsequenceRec {
  int lcs( char[] X, char[] Y, int m, int n) {
    if (m == 0 || n == 0) {	// base case
		return 0;
    }
    if (X[m-1] == Y[n-1]) {	// if common element is found increase lcs length by 1
		return 1 + lcs(X, Y, m-1, n-1);
    } else {	// recursively move back on one string at a time
    	return Math.max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }
  }
 
  public static void main(String[] args) {
    LongestCommonSubsequenceRec lcs = new LongestCommonSubsequenceRec();
    String s1 = "AAGTCGGTAB";
    String s2 = "AGXTGXAYTBC";
 
    char[] X=s1.toCharArray();
    char[] Y=s2.toCharArray();
    int m = X.length;
    int n = Y.length;
 
    System.out.println("Length of LCS is" + " " + lcs.lcs( X, Y, m, n ));
  }
 
}
