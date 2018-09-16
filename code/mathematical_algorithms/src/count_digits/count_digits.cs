using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace count_digits
{
    class Program
    {
        static int digits(int number)
        {
            int count = 0;
            while (number != 0)
            {
                count++;
                number /= 10;
            }
            return count;
        }
        static void Main(string[] args)
        {
            int number = 89922;
            Console.WriteLine("number {0} has {1} digits", number, digits(number));
            Console.ReadKey();
        }
    }
}
