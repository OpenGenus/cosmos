using System;
using System.Linq;

namespace PalindromeChecker {
	class Program {
		static void Main(string[] args) {
			Console.WriteLine(IsPalindrome("Borrow or rob?")); // should output true
			Console.WriteLine(IsPalindrome("To be, or not to be.")); // should output false
			Console.WriteLine(IsPalindrome("A Toyota’s a Toyota.")); // should output true
			Console.WriteLine(IsPalindrome("It's peanut butter jelly time!")); // should output false
			Console.WriteLine(IsPalindrome("A Santa dog lived as a devil God at NASA.")); // should output true
			Console.WriteLine(IsPalindrome("Man is not what he thinks he is, he is what he hides.")); // should output false
			Console.WriteLine(IsPalindrome("Are we not pure? “No, sir!” Panama’s moody Noriega brags. “It is garbage!” Irony dooms a man—a prisoner up to new era.")); // should output true
		}

		static bool IsPalindrome(string str) {
			string s = new string(str.ToLower().Where(c => Char.IsLetterOrDigit(c)).ToArray());
			char[] arr = s.ToCharArray();
			Array.Reverse(arr);
			string r = new string(arr);
			return s == r;
		}
	}
}
