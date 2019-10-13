import java.io.*;

class Fibonacci {
  static int f[] = new int[100];

  int fib(int n) {
    if(n <= 1) return f[n];
    else if(f[n] != 0) return f[n];
    else {
      f[n] =  fib(n - 1) + fib(n - 2);
      return f[n];
    }
  }

  public static void main() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Enter the number");
    int n = Integer.parseInt(br.readLine());
    f[0] = 0;
    f[1] = 1;
    Fibonacci obj = new Fibonacci();
    System.out.println("The nth fibonacci number is : " + obj.fib(n - 1));
  }
}
