import java.util.Scanner;
// Part of Cosmos by OpenGenus Foundation
public class count_trailing_zeroes_factorial {
    public static int trailingZeroes(int n){
        int count = 0;

        for(int i=5;n/i>=1;i*=5)
            count += n/i;

        return count;
    }
    public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);

	    System.out.print("Enter n >> ");
	    int n = sc.nextInt();

	    System.out.println("Number of trailing zeroes in " + n + "! : " + trailingZeroes(n));
    }
}
