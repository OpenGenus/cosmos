using System;

namespace russian_peasant
{
    static class russ_peasant
    {
        static public int multiply(int a, int b)
        {
            int res = 0;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    res += a;
                }
                a <<= 2;
                b >>= 2;
            }
            return res;
        }
    }
    class Program
    {
        static void Main()
        {
            int number1 = 10;
            int number2 = 25;
            
            Console.WriteLine(russ_peasant.multiply(number1, number2));
            

            Console.ReadKey();
        }
    }
}
