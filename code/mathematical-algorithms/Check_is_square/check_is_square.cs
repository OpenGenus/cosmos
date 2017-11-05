// Part of Cosmos by OpenGenus Foundation 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace finding_is_square
{
    /// <summary>
    /// Class to check if number is a perfect square or not
    /// </summary>
    class is_square
    {
        /// <summary>
        /// an array to store numbers
        /// </summary>
        int[] numbers;
        /// <summary>
        /// constructor 
        /// </summary>
        /// <param name="number">numbers to be processed</param>
        public is_square(int[] number)
        {
            numbers = number;
        }
        /// <summary>
        /// method to check if perfect square or not
        /// </summary>
        public void check_sq()
        {
            foreach (int number in numbers) // traversing the whole integer array
            {
                if (Math.Sqrt(number).ToString().Contains("."))  // converting double to string to chk if it contains . or not
                    Console.WriteLine("number {0} is not a perfect square", number);
                else
                    Console.WriteLine("number {0} is a perfect square", number);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // making an array of numbers to check
            int[] numbers = { 56, 90, 100, 80, 16 };
            
            // creating an object of is_square class and initializing with test inputs
            is_square sq = new is_square(numbers);

            sq.check_sq(); // checking
             
            Console.ReadKey(); // pausing
        }
    }
}
