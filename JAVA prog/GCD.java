import java.util.Scanner;

public class GCD {
    private  static final Scanner sc = new Scanner(System.in);

    public static int gcd(int a, int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

    public static int lcm(int a, int b) {
        return (a*b)/gcd(a,b);
    }
    public static void main(String[] args) {
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int g = gcd(n1,n2);
        int l = lcm(n1,n2);
        System.out.println(g);
        System.out.println(l);
    }
}
