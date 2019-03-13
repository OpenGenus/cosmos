def longest_pal(test_num):
    num = str(test_num)
    # booleanArray with [start][end]
    pal_boolean_array = [[False for e in range(len(num))] for s in range(len(num))]
    # all one-letter substrings are palindromes
    for s in range(len(num)):  # length one substrings are all palindromes
        pal_boolean_array[s][s] = True
    longest = 1

    for s in range(len(num) - 1):  # check substrings of length 2
        palindrome_boolean = num[s] == num[s + 1]
        pal_boolean_array[s][s + 1] = palindrome_boolean
        if palindrome_boolean:
            longest = 2

    for lengths_to_check in range(3, len(num) + 1):  # lengths greater than 2
        for s in range(len(num) - lengths_to_check + 1):
            other_characters_symmetry = pal_boolean_array[s + 1][
                s + lengths_to_check - 2
            ]
            palindrome_boolean = (
                num[s] == num[s + lengths_to_check - 1] and other_characters_symmetry
            )
            pal_boolean_array[s][s + lengths_to_check - 1] = palindrome_boolean
            if palindrome_boolean:
                longest = max(longest, lengths_to_check)
    return longest
