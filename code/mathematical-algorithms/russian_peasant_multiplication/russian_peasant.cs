using System;

namespace russian_peasant
{
    class russ_peasant
    {
        int a, b;
        public russ_peasant(int number1,int number2)
        {
            a = number1;
            b = number2;
        }
        public int multiply()
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
            russ_peasant obj = new russ_peasant(15, 20);
            Console.WriteLine(obj.multiply());

            Console.ReadKey();
        }
    }
}
