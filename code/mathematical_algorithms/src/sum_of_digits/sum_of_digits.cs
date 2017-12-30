//Part of Cosmos by OpenGenus Foundation
using System;

class MainClass {
  public static int sumDigits(long n) {
      long sum = 0;
      while (n > 0) {
          sum += n % 10;
          n = n / 10;
      }
      return Convert.ToInt32(sum);
  }
  public static void Main(String[] args){
    Console.WriteLine("Enter number to be summed");

 		long num = Convert.ToInt64(Console.ReadLine());
    int sum = sumDigits(num);

    Console.WriteLine(string.Format("Sum of digits of {0} is {1}", num, sum) );

  }
}
