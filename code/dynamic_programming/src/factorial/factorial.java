/* Part of Cosmos by OpenGenus Foundation */

/**
 * Implements factorial using recursion
 */
public class Factorial {

    private static int factorial(int num) {
        if (num == 0) {
            return 1;
        } else {
            return (num * factorial(num - 1));
        }
    }

    public static void main(String[] args) {
        int number = 5;
        int result;
        result = factorial(number);
        System.out.printf("The factorial of %d is %d", number, result);
    }
    
}
