import java.util.*;
class Babylonian{
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        double n = s.nextDouble();
        System.out.println("The square root of " + n + " is " + squareRoot(n));
    }

    /*Returns the square root of n*/
    public static double squareRoot(double n)
    {
      double x = n;
      double y = 1;
      double acc = 0.000001; /* acc decides the accuracy level*/
      while(x - y > acc)
      {
        x = (x + y)/2;
        y = n/x;
      }
      return x;
    }
}