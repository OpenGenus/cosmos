import java.util.Scanner;
/*
 *	Part of Cosmos by OpenGenus Foundation
*/
 class NQueen {

	public static int[][] array;
	
	public static boolean solveNQueen(int queens, int i){
		if(i == queens){
			return true;
		}
		
		for (int j =0; j <queens; j++) {
			if(isSafe(i, j, queens)) {
				array[i][j] = 1;
				if(solveNQueen(queens, i+1))				
					return true;
				array[i][j] = -1;
			}
		}
		return false;
	}
	
	public static boolean isSafe(int row, int column, int n){
		for(int i = 0; i < n; i++) {
			if(array[row][i] == 1)
				return false;
		}
	 
		for(int i = 0; i < n; i++) {
			if(array[i][column] == 1)
				return false;
		}
	 
		int copyRow = row, copyColumn = column;
		while(copyRow >= 0 && copyColumn >= 0) {
			if(array[copyRow][copyColumn] == 1)
				return false;
			copyRow--; 
			copyColumn--;
		}
	 
		copyRow = row; copyColumn = column;
		while(copyRow >= 0 && copyColumn <= n-1) {
			if(array[copyRow][copyColumn] == 1)
				return false;
			copyRow--; 
			copyColumn++;
		}
	 
		return true;
	}

	public static void initField(int queens) {
		array = new int[queens][queens];
		for (int i=0;i < queens ; i++) {
			for (int j = 0;j < queens ; j++)
				array[i][j] = 0;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Type in the number of queens: ");
		int queens = sc.nextInt();
		initField(queens);
		if(!solveNQueen(queens, 0))
			System.out.println("No combination possible!");
		else
			for (int k = 0; k < queens ;k++ ){
				for (int j = 0; j < queens ;j++ )
					System.out.print(array[k][j] > 0 ? "Q " : ". ");
				System.out.println();
			}
	}
}
