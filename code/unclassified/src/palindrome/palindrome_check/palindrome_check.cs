using System;

namespace Palindrome
{
    class Program
    {
        public static bool isPalindrome(string str)
        {
            for (int i = 0, j = str.Length - 1; i < str.Length / 2; ++i, --j)
            {
                if(str[i] != str[j])
                {
                    return false;
                }
            }
            return true;
        }

        public static void Main()
        {
            Console.WriteLine(isPalindrome("lol")); // True
            Console.WriteLine(isPalindrome("lolwa"));  // False
        }
    }
}