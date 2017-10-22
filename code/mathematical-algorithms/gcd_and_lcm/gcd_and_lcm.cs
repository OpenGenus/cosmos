using System;

namespace gcd_and_lcm
{
    class gcd_lcm
    {
        int a, b;
        public gcd_lcm(int number1,int number2)
        {
            a = number1;
            b = number2;
        }
        public int gcd()
        {
            int temp1 = a, temp2 = b;
            while (temp1 != temp2)
            {
                if (temp1 > temp2)
                {
                    temp1 -= temp2;
                }
                else
                {
                    temp2 -= temp1;
                }
            }
            return temp2;
        }
        public int lcm()
        {
            return a * b / gcd();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int a = 20, b = 120;
            gcd_lcm obj = new gcd_lcm(a, b);

            Console.WriteLine("GCD of {0} and {1} is {2}", a, b, obj.gcd());
            Console.WriteLine("LCM of {0} and {1} is {2}", a, b, obj.lcm());

            Console.ReadKey();
        }
    }
}
