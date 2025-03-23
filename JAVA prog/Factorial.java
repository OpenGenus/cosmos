import java.util.Scanner;

public class Factorial {
    private  static final Scanner sc = new Scanner(System.in);

    public static int Factorial(int n) {
        int fact = 1;
        for(int i=n; i>1; i--)
            fact = fact*i;
        return fact;
    }
    public static void main(String[] args) {
        int n1 = sc.nextInt();
        int f = Factorial(n1);
        System.out.println(f);
    }
}
