using System;

namespace LeapTest
{
    public class Program
    {
        private static bool isLeap(int year)
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
        
        public static void Main()
        {
            int startYear, endYear;
            Console.Write("enter starting year : ");
            Int32.TryParse(Console.ReadLine(), out startYear);
            Console.Write("enter ending year : ");
            Int32.TryParse(Console.ReadLine(), out endYear);
            
            for(int i = startYear; i <= endYear; ++i) 
            {
                if(isLeap(i))
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}
