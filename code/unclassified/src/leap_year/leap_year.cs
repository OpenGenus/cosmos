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
            int startYear = 2001;
            int endYear = 2101;
            
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
