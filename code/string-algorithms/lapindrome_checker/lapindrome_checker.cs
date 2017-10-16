using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 *      LAPINDROME CHECKER
 *
 * Part of cosmos from OpenGenus Foundation
 * */

namespace lapindrome_checker
{
    /// <summary>
    /// lapindrome class accepts a string
    /// its a static class, no need of creating objects
    /// direct access,
    ///
    /// lapindrome.str = "<your_test_string>";
    /// lapindrome.check();
    /// </summary>
    static class lapindrome
    {
        /// <summary>
        /// Accepting string to for testing
        /// </summary>
        static public string str { get; set; }   // static public property for direct access without creating any method

        /// <summary>
        /// method to check if string is lapindrome then return true, else false;
        /// </summary>
        static public bool check()
        {

            // calculating the length
            int len = str.Length;

            // getting middle element
            int mid = len / 2;

            // getting the split delimiter
            int delim = len % 2 == 0 ? mid : mid + 1; // for odd number of elements in string ignoring the middlemost

            // slicing two strings
            string left = str.Substring(0, mid);
            string right = str.Substring(delim);

            // sorting strings using lambda expression
            left = String.Concat(left.OrderBy(x => x));
            right = String.Concat(right.OrderBy(x => x));

            // testing if equal
            if (left == right)
            {
                return true;  // here string is lapindrome
            }
            else
            {
                return false;  // here string is not lapindrome
            }
        }
    }

    /// <summary>
    /// Main program class
    /// </summary>
    class Program
    {
        /// <summary>
        /// Main Function
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            /*
             * Demo Goes Here
             * */

            // TEST CASE 1
            lapindrome.str = "tbhaxor";
            if (lapindrome.check())
                Console.WriteLine("lapindrome");
            else
                Console.WriteLine("not lapindrome");

            // TEST CASE 2
            lapindrome.str = "xyzyx";
            if (lapindrome.check())
                Console.WriteLine("lapindrome");
            else
                Console.WriteLine("not lapindrome");

            Console.ReadKey();

        }
    }
}
