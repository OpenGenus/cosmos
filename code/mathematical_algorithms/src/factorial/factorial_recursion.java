/*  Part of Cosmos by OpenGenus Foundation */
import java.util.Scanner;
import java.math.BigInteger;
//This Code depicts to calculate Factorial of a number in java using BigInteger Class Using Tail Recursion.
class Factorial{
    // A Recursive Method calculating Factorial of a given number.
    static BigInteger factorial(int n){
        //Base Case 
        if(n<=1){
            return BigInteger.ONE;
        }
        //Recursive Case
        BigInteger fact = factorial(n-1);
        return fact.multiply(BigInteger.valueOf(n));
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();//Reading the Input
        BigInteger fact = factorial(n);//Calling the factorial method
        System.out.println("Factorial of n is "+fact);//Printing the result
    }
}