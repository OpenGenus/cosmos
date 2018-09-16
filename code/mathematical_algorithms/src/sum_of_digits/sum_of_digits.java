// Part of Cosmos by OpenGenus Foundation
public class SumOfDigits {
    public static int sumDigits(long n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
}
