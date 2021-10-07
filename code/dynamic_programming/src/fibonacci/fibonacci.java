//
//What is Fibonacci series?
//Ans: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 
// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

// Constraints:
// 0 <= n <= 30

//Let's a Ficonacci series
//1, 1, 2, 3, 5, 8, 13.......

//Here suppose Input:  n = 5
//so, we have to find the nth term of fibonacci series
//In this case when n = 5, the series will be:
//1, 1, 2, 3, 5
//So, the nth term will be : 5
//Hence our output: 5


//So, this Problem can be solved by Dp approch:
//Below are my code:
//Top down 
//and Bottom up manner

//Top Down Approach!
class Solution {
 
    public static void main(String args[]){
     int n = 5;
     // Alternative you can use
     //Scanner sc = new Scanner(System.in);
     //int n = sc.nextInt();
     //So, in this case 1st you have to import :
     //import java.util.Scanner;
     int result = fib(n);
     System.out.println(result);
    }

    public static int fib(int n) {
        if (n < 2)      //This is a base case, as we know when n = 1 then the output will be 1
            return n;
        int[] dp = new int[n + 1];
        return fibHelp(n, dp);
    }

    static int fibHelp(int n, int[] dp) {
        if (n < 2)
            return n;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = fibHelp(n - 1, dp) + fibHelp(n - 2, dp);
    }
}

// Bottom Up Approach!
class Solution {
 
 public static void main(String args[]){
     int n = 5;
     // Alternative you can use
     //Scanner sc = new Scanner(System.in);
     //int n = sc.nextInt();
     //So, in this case 1st you have to import :
     //import java.util.Scanner;
     int result = fib(n);
     System.out.println(result);
    }

    public static int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int dp[] = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}

// Another one
class Solution {
  public static void main(String args[]){
     int n = 5;
     // Alternative you can use
     //Scanner sc = new Scanner(System.in);
     //int n = sc.nextInt();
     //So, in this case 1st you have to import :
     //import java.util.Scanner;
     int result = fib(n);
     System.out.println(result);
    }

    public static int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int i = 0, j = 1, num = 0;
        while (n-- > 1) {
            num = i + j;
            i = j;
            j = num;
        }
        return num;
    }
}
