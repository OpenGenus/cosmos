using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * Armstrong number is a number that is equal to the sum of cubes of its digits. 
 * For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
 * 
 * */
namespace armstrong
{
    class armstrong
    {
        int number;
        public armstrong(int number)
        {
            this.number = number;
        }
        public bool check()
        {
            if (number == getcSum())
                return true;

            return false;
        }

        int getcSum()
        {
            int dupli = number;
            int sum = 0;
            while (dupli != 0)
            {
                sum += getcube(dupli % 10);
                dupli /= 10;
            }
            return sum;
        }
        int getcube(int number)
        {
            return number * number * number;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int num = 15;
            armstrong arm = new armstrong(num);
            if (arm.check())
                Console.WriteLine("{0} is an armstrong number", num);
            else
                Console.WriteLine("{0} is not an armstrong number", num);

            Console.ReadKey(); // pauses the program
        }
    }
}
