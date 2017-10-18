using System;

namespace reverse_number
{
        class Program
        {
                static void Main(string[] args)
                {
                        var num = 123456789;
                        Console.WriteLine("reverse of {0} is {1}", num, ReverseNumber(num));
                }

                static int ReverseNumber(int number)
                {
                        var c = number.ToString().ToCharArray();
                        Array.Reverse(c);
                        return Int32.Parse(new String(c));
                }
        }
}
