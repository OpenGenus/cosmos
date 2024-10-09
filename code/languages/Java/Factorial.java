import java.util.Scanner;

class Factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number to find its factorial: ");
        int n = sc.nextInt();

        // Try to calculate the factorial of n, catch any exceptions that are thrown.
        try {
            System.out.println(n + "! = " + factorial(n));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        sc.close();
    }

    /**
     * This method recursively calculates the factorial of an integer. 
     * @param n An integer we are finding the factorial of.
     * @return The factorial of `n`.
     * @throws Exception If `n` is negative.
     */
    public static int factorial(int n) throws Exception {

        // Check that factorial is non-negative, throw an expection if not.
        if (n < 0) {
            throw new Exception("Factorial of negative number is not possible");
        } else if (n == 0 || n == 1) { // Base cases, no need to recurse further.
            return 1;
        } else { // Non-negative n and not at a base case, so multiply n by the factorial of n-1 and return it.
            return n * factorial(n - 1);
        }
    }
}