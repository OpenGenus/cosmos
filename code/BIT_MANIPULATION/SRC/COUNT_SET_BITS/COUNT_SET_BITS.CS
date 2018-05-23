using System;

namespace CountSetBits
{
    class Program
    {
        static internal int countSetBits(int number)
        {
            string bin = Convert.ToString(number, 2); // getting binary number
            int count = 0;
            foreach (char bit in bin)
            {
                if(bit == '1')
                    count++;
            }
            return count;
        }

        static public void Main()
        {
            Console.WriteLine(countSetBits(13));
        }
    }
}