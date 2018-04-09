/*
    Takes values from CLI Arguments
    How to run

    $ mcs average.cs
    $ mono average.exe 1 2 3 4 5

 */

using System;

namespace Average
{
    class Program
    {
        public static void Main(string[] argv)
        {
            float sum = 0.0f;
            float n;
            foreach(var num in argv)
            {
                n = float.Parse(num);
                sum += n;
            }

            Console.WriteLine(sum / argv.Length);
        }
    }    
}