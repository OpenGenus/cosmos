using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace coprime_numbers
{
    class coprime
    {
        int a, b;
        public coprime(int num1,int num2)
        {
            a = num1;
            b = num2;
        }
        int gcd()
        {
            while (a != b)
            {
                if (a > b)
                {
                    a -= b;
                }
                else
                {
                    b -= a;
                }
            }
            return a;
        }
        public bool check()
        {
            return gcd() == 1;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int num1 = 10, num2 = 5;
            coprime cp = new coprime_numbers.coprime(num1, num2);
            if (cp.check())
                Console.WriteLine("coprime");
            else
                Console.WriteLine("not coprime");

            Console.ReadKey();
        }
    }
}
