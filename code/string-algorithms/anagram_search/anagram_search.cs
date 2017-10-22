using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnagramSearch
{
    class Program
    {
        static void Main(string[] args)
        {
            printAnagramResult("Anagram", "Nag A Ram", anagram_search("Anagram", "Nag A Ram"));
            printAnagramResult("Nascar", "Battles", anagram_search("Nascar", "Battles"));
            printAnagramResult("Lisp", "Clips", anagram_search("Lisp", "Clips"));
            printAnagramResult("Angel", "Glean", anagram_search("Angel", "Glean"));

            Console.ReadKey();
        }

        public static bool anagram_search(string first, string second)
        {
            // Remove all whitespace
            first = first.Replace(" ", string.Empty);
            second = second.Replace(" ", string.Empty);

            if (first.Length != second.Length)
            {
                return false;
            }

            // Convert to lowercase and sort
            first = first.ToLower();
            second = second.ToLower();
            char[] _first = first.ToArray();
            Array.Sort(_first);
            char[] _second = second.ToArray();
            Array.Sort(_second);

            first = new string(_first);
            second = new string(_second);

            for (int i = 0; i < first.Length; i++)
            {
                if (first[i] != second[i])
                {
                    return false;
                }
            }

            return true;
        }

        public static void printAnagramResult(string first, string second, bool result)
        {
            if (result)
            {
                Console.WriteLine(first + " and  " + second + " are anagrams.");
            }

            else
            {
                Console.WriteLine(first + " and  " + second + " are not anagrams.");
            }
        }
    }
}
