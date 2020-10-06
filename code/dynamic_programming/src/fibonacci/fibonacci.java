import java.util.*;

class Fibonacci { 
  
    static int fib(int n) 
    {
        int f[] = new int[n + 2];
  
        // 0th and 1st number of the series are 0 and 1 
        f[0] = 0; 
        f[1] = 1; 
  
        for (int i = 2; i <= n; i++) {
            // Add the previous 2 numbers in the series and store it
            f[i] = f[i - 1] + f[i - 2]; 
        } 

        for(int i=0;i<n+2;i++){
            System.out.print(f[i] + " ");
        }

    } 
  
    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter value of N: ")
        int n = sc.nextInt();
        fib(n);

    } 
} 