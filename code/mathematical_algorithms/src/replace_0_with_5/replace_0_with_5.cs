using System;

namespace Replace
{
    public class Program
    {
        private static string replace(string n)
        {
            return n.Replace('0', '5');
        }
        
        public static void Main()
        {
            Console.Write("enter a number : ");
            string number = Console.ReadLine();
            
            Console.WriteLine(replace(number));
        }
    }

}
