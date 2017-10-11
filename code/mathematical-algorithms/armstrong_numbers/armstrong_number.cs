using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * Armstrong number is a number that is equal to the sum of cubes of its digits.
 * For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
 *
 * */
namespace armstrong
{

    class Program
    {
        static void Main(string[] args)
        {
            // variable declaration
            int number = 407;    // number
            int sum = 0;  // sum of digits
            int dup = number;  // duplicate for traversing
            int digit;  // holding each digit

            // applying algorithm
            while(dup!=0) // while will run until and unless digits are being processed
            {
                digit = dup % 10; //last digit
                sum += digit * digit * digit;  // cube of current digit
                dup /= 10;  // removing last digit
            }

            if (sum == number)
            {
                Console.Write(number.ToString() + " is an armstrong number");
            }
            else
            {
                Console.Write(number.ToString() + " is not an armstrong number");
            }
            Console.ReadKey(); // pauses the program
        }
    }
}
