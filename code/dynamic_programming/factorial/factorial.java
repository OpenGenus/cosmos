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
    
    private static int factorialDynamic(int num){
        int n= new int[num+1]
        n[0] = 1;    
        for(int i=1;i<=num;i++){
            n[i] = n[i-1]*i;
            
        }
        return n[num];
    }

    public static void main(String[] args) {
        int number = 5;
        int result;
        result = factorial(number);
        System.out.printf("The factorial of %d is %d", number, result);
        result = factorialDynamic(number);
        System.out.printf("The factorial using Dynamic Programming of %d is %d", number, result);
    }
    
}
