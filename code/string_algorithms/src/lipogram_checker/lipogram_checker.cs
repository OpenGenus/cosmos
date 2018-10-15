using System;
/*
 * Part of cosmos by OpenGenus Foundation
 * */
namespace lipogram_checker
{
    class Program
    {
        /// <summary>
        /// Method to check if a string is lipogram or not
        /// </summary>
        /// <param name="str">String To Check</param>
        /// <returns>Integer Value</returns>
        static int lipogram(string str)
        {
            int count = 0;
            string alphabets = "abcdefghijklmnopqrstuvwxyz";
            str = str.ToLower();
            for (int i = 0; i < alphabets.Length; i++)
            {
                int index = str.IndexOf(alphabets[i]);

                if (index < 0 || index > str.Length)
                    count++;
            }
            return count;
        }
        static void Main(string[] args)
        {
            string to_chk = "The quick brown fox jumped over the lazy dog";

            int val = lipogram(to_chk);

            if (val == 0)
                Console.WriteLine("Pangram");
            else if (val >= 2)
                Console.WriteLine("Not a pangram but might a lipogram");
            else
                Console.WriteLine("Pangrammatic Lipogram");

            Console.ReadKey();
        }
    }
}
