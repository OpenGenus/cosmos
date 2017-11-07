/* Part of Cosmos by OpenGenus Foundation */
using System;

namespace AutomophicCSharp
{
    class Automorphic
    {
        static void Main (string[] args)
        {
            for(double i=0; i<=10000000; i++)
            {
                if(isAutomorphic(i))
                {
                    Console.WriteLine(String.Format("{0} is automorphic - {1}", i, i*i));
                }
            }
        }

        static bool isAutomorphic(double value)
        {
            // convert the value to a string
            string stringValue = value.ToString();

            // get the square as a string
            string stringSquared = (value * value).ToString();

            return stringSquared.EndsWith(stringValue);
        }
    }
}