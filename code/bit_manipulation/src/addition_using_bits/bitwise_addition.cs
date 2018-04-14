using System;

namespace BitwiseAddition
{
    class Program
    {
        static internal int bitwiseRecursiveAddition(int n, int m)
        {
            if(m == 0)
                return n;
    
            var carry = n & m;
            return bitwiseRecursiveAddition(n ^ m, carry << 1);
        }

        static internal int bitwiseIterativeAddition(int n, int m)
        {
            while(m != 0) {
                var carry = n & m;
                n ^= m;
                m = carry << 1;
            }
            return n;
        }
    
        static public void Main()
        {
            Console.WriteLine(bitwiseRecursiveAddition(10, 20));
            Console.WriteLine(bitwiseIterativeAddition(50, 20));
        }
    }
}