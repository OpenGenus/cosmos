using System;

namespace SmallestNumber
{
    public class Program
    {
        private static int smallestNumber(int n)
        {
            int min = n % 10;
            n /= 10;
            
            while(n != 0)
            {
                if(n % 10 < min)
                {
                    min = n % 10;
                }
                n /= 10;
            }
            return min;
        }
        
        public static void Main()
        {
            Console.Write("enter a number : ");
            int number;
            Int32.TryParse(Console.ReadLine(), out number);
            
            Console.WriteLine(smallestNumber(number));
        }
    }

}
