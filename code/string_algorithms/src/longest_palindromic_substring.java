// Java implementation of O(n^2)
// time and O(1) space method
// to find the longest palindromic substring
public class LongestPalinSubstring {
	// A utility function to print
	// a substring str[low..high]
	static void printSubStr(String str,
							int low, int high)
	{
		System.out.println(
			str.substring(
				low, high + 1));
	}

	// This function prints the
	// longest palindrome substring
	// (LPS) of str[]. It also
	// returns the length of the
	// longest palindrome
	static int longestPalSubstr(String str)
	{
		// The result (length of LPS)
		int maxLength = 1;

		int start = 0;
		int len = str.length();

		int low, high;

		// One by one consider every
		// character as center
		// point of even and length
		// palindromes
		for (int i = 1; i < len; ++i) {
			// Find the longest even
			// length palindrome with
			// center points as i-1 and i.
			low = i - 1;
			high = i;
			while (low >= 0 && high < len
				&& str.charAt(low)
						== str.charAt(high)) {
				--low;
				++high;
			}
		
			// Move back to the last possible valid palindrom substring
			// as that will anyway be the longest from above loop
			++low; --high;
			if (str.charAt(low) == str.charAt(high) && high - low + 1 > maxLength) {
				start = low;
				maxLength = high - low + 1;
			}

			// Find the longest odd length
			// palindrome with center point as i
			low = i - 1;
			high = i + 1;
			while (low >= 0 && high < len
				&& str.charAt(low)
						== str.charAt(high)) {
				--low;
				++high;
			}
		
			// Move back to the last possible valid palindrom substring
			// as that will anyway be the longest from above loop
			++low; --high;
			if (str.charAt(low) == str.charAt(high) && high - low + 1 > maxLength) {
				start = low;
				maxLength = high - low + 1;
			}
		}

		System.out.print("Longest palindrome substring is: ");
		printSubStr(str, start, start + maxLength - 1);

		return maxLength;
	}

	// Driver program to test above function
	public static void main(String[] args)
	{

		String str = "todayisabeautifulday";
		System.out.println("Length is: " + longestPalSubstr(str));
	}
}


