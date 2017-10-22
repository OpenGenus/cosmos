import java.util.Scanner;
// Part of Cosmos by OpenGenus Foundation
public class Main {

    /// Holds 3 long integers
    static class Trint {
        final long first, second, third;
        Trint (long first, long second, long third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    // Returns values x, y and d for which a*x + b*y = d, where d is GCD(a, b)
    private static Trint extendedEuclid(long a, long b) {
        if (b == 0) {
            return new Trint(1, 0, a);
        }
        /// calculate result for b, a%b
        Trint result = extendedEuclid(b, a%b);
        return new Trint(result.second,
                result.first - (a / b) * result.second,
                result.third);
    }

    // Returns the modular inverse (for which number * inverse % mod == 1)
    public static long modularInverse(long number, long mod) {
        if (number < 1 || number >= mod)
            throw new RuntimeException("Number should lie between 1 and mod (" + mod + ")");
        Trint result = extendedEuclid(number, mod);
        long inverse = result.first, gcd = result.third;
        if (gcd != 1)
            throw new RuntimeException(String.format("The number (%d) and mod (%d3) are not coprime", number, mod));
        /// Ensure inverse lies between 0 and mod
        if (inverse < 0)
            inverse += ((long)Math.ceil(Math.abs((double)inverse) / mod)) * mod;
        return inverse;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number: ");
        long number = input.nextLong();
        System.out.println("Enter the modulo: ");
        long mod = input.nextLong();

        long inverse = modularInverse(number, mod);
        System.out.println("The inverse is " + inverse);

        if (number * inverse % mod != 1)
            System.out.println("Something went wrong");
    }
}
