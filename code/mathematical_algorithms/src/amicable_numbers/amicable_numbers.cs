using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace amicable_numbers
{
    class Program
    {
        static void amicable_numbers(int from, int to)
        {
            for(int i = from; i < to; i++)
            {
                int x = i, y;
                int sum1 = 0, sum2 = 0;
                for (int j = 1; j < x; j++)
                {
                    if (x % j == 0)
                        sum1 += j;
                }
                y = sum1;
                for (int j = 1; j < y; j++)
                {
                    if (y % j == 0)
                        sum2 += j;
                }
                if (sum2 == x && x != y)
                {
                    Console.WriteLine(x);
                }
            }
        }
        static void Main(string[] args)
        {
            int num1 = 10;
            int num2 = 2000;
            Console.WriteLine("amicable nunmbers between {0} and {1} are", num1, num2);
            amicable_numbers(num1, num2);
            Console.ReadKey();
        }
    }
}
