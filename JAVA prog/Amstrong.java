import java.util.Scanner;

public class Amstrong {
    private static final Scanner sc = new Scanner(System.in);

    public  static void isAmstrong(int n) {
        int d = 0;
        int sum = 0;
        int num = n;
        while(n!=0) {
            d = n%10;
            sum = sum + d*d*d;
            n = n/10;
        }

        if(sum == num)
            System.out.print("Amstrong");
        else
            System.out.print("Not Amstrong");
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        isAmstrong(n);
    }
}
