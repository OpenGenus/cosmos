using System;

namespace Replace
{
    public class Program
    {
        private static string replace(string number)
        {
            string N = "";
            foreach (char n in number)
            {
                if (n == '0')
                {
                    N += '5';
                }
                else
                {
                    N += n;
                }
            }
            return N;
        }
        
        public static void Main()
        {
            Console.Write("enter a number : ");
            string number = Console.ReadLine();
            
            Console.WriteLine(replace(number));
        }
    }

}
