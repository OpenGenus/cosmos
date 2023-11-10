# Part of Cosmos by OpenGenus Foundation


def longest_palindrome(text):
    """ Find the maximum length of a palindrome subsequence

    Dynamic Programming approach on solving the longest palindromic sequence.
    Time complexity: O(n^2), n = length of text.

    Args:
        text: string which will be processed
    Returns:
        Integer of maximum palindrome subsequence length
    """
    length = len(text)
    # create palindromes length list (space O(n))
    palindromes_lengths = [1] * length
    # iterate on each substring character
    for fgap in range(1, length):
        # get pre-calculated length
        pre = palindromes_lengths[fgap]
        # reversed iteration on each substring character
        for rgap in reversed(range(0, fgap)):
            tmp = palindromes_lengths[rgap]
            if text[fgap] == text[rgap]:
                # if equal characters, update palindromes_lengths
                if rgap + 1 > fgap - 1:
                    # if characters are neighbors, palindromes_lengths is 2
                    palindromes_lengths[rgap] = 2
                else:
                    # else they're added to the pre-calculated length
                    palindromes_lengths[rgap] = 2 + pre
            else:
                # if first and last characters do not match, try the latter ones
                palindromes_lengths[rgap] = max(
                    palindromes_lengths[rgap + 1], palindromes_lengths[rgap]
                )
            # update pre-calculated length
            pre = tmp
    # return the maximum palindrome length
    return palindromes_lengths[0]


def main():
    """ Main routine to test longest_palindrome funtion """
    print(longest_palindrome("bbabcbcab"))  # 7: babcbab | bacbcab
    print(longest_palindrome("abbaab"))  # 4: abba | baab
    print(longest_palindrome("opengenus"))  # 3: ene | ege | ngn | nen


if __name__ == "__main__":
    main()
