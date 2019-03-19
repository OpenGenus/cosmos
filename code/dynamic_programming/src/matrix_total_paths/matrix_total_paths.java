import java.util.Scanner;

public class MatrixTotalPaths {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int mat[][] = new int[n][m];
		for(int i = 0;i<n;i++) 
			for(int j = 0;j<m;j++)
				mat[i][j] = s.nextInt();
		int dp[][] = new int[n][m];
		for(int i = 0;i<n;i++) {
			if(mat[i][0] == 0)dp[i][0] = 1;
			else break;
		}
		for(int i = 0;i<m;i++) {
			if(mat[0][i] == 0) dp[0][i] = 1;
			else break;
		}
		for(int i = 1;i<n;i++) {
			for(int j = 1;j<m;j++) {
				if(mat[i][j]!=1) dp[i][j]+=dp[i-1][j]+dp[i][j-1];
			}
		}
		System.out.println(dp[n-1][m-1]);
	}

}