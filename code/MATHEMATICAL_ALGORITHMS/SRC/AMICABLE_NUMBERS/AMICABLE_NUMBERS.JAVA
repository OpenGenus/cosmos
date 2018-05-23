import java.util.Set;
import java.util.TreeSet;

public class Amicable_numbers {
   public static void main(String[] args) {
      System.out.println("The sum of amicable numbers less than 1000 is " + getAmicableSum(10000));
   }

   // returns the sum of all divisors less than n
   public static int getDivisorSum(int n) {
      Set<Integer> divisors = new TreeSet<Integer>();
      int root = (int) Math.ceil(Math.sqrt(n));
      for (int i = 1; i < root + 1; i++) {
         if ((double) n % i == 0 && i < n) {
            divisors.add(i);
            if (n / i < n) {
               divisors.add(n / i);
            }
         }
      }
      int divisorSum = 0;
      for (int i : divisors) {
         divisorSum += i;
      }
      return divisorSum;
   }
   
   // returns the sum of all amicable numbers less than max
   private static int getAmicableSum(int max) {
      int sum = 0;
      for (int i = 1; i < max; i++) {
         int a = getDivisorSum(i);
         int b = getDivisorSum(a);
         if (i == b && a != b) {
            sum += i;
         }
      }
      return sum;
   }
}
