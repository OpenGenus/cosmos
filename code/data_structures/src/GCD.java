public class GCD {
    public static void main(String[] args) {
        int a = 5;
        int b = 10;
        int ans = gcd(a,b);
        System.out.println("GCD of Two number is : " + ans);
    }

    static int gcd(int a, int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
}
