// Program to check whether a number is square_free or not
import java.util.Scanner;
class square_free_number{

	static boolean isSquareFree(int n) {

		if(n%2==0)
			n=n/2;
		if(n%2==0)
			return false;
		for(int i=3; i<=Math.sqrt(n);i=i+2) {

            if (n % i == 0) {
                n = n / i;
                if (n % i == 0)
                    return false;
            }
        }
     
        return true;
    }
     
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        n = sc.nextInt();
        if (isSquareFree(n))
            System.out.println(n + " is square free number");
        else
            System.out.println(n + " is not a square free number");
    }
}
 