def longest_palindromic_sequence(s):
    l = len(s)
    palindrome = [[ 0 if i != j else 1 
                             for i in xrange(l)] 
                                 for j in xrange(l)]
    for j in xrange(1, l):
        for i in xrange(l - 1):
            # candidate index
            y = i + j
            # in case candidate index is after length of text break
            if y >= l:
                break

            # in case equal characters, update length
            if s[i] == s[y]:
                if j == 1:
                    palindrome[i][h] = 2
                else:    
                    palindrome[i][y] = palindrome[i + 1][y - 1] + 2 
            else:
                # characters not equal take max
                palindrome[i][y] = max(palindrome[i + 1][y], 
                                              palindrome[i][y - 1])

    # return the maximum length
    return palindrome[0][l - 1]   
