/* Part of Cosmos by OpenGenus Foundation */

using System;

namespace CS
{
    public class GreatestDigitInNumber
    {

        static int GreatestDigit(int n)
        {
            int max = 0;
            while (n != 0)
            {
                if (max < n % 10) 
                    max = n % 10;
                n /= 10;
            }
            return max;
        }

        static void Main(string[] args)
        {
            var rand = new Random();

            for (int i = 0; i <= 10; i++) {
                int number = rand.Next(65535);
                int digit = GreatestDigit(number);
                Console.WriteLine("Number: " + number + " \tGreatest Digit: " + digit);
            }
        }
    }
}

