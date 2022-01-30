def isPalindromeRecursive(string):
    if len(string) == 2 or len(string) == 1:
        return True
    if string[0] != string[len(string) - 1]:
        return False
    return isPalindromeRecursive(string[1 : len(string) - 1])


def isPalindromeReverse(string):
    return string == string[::-1]


def isPalindromeIterative(string):
    start = 0
    end = len(string) - 1
    while start < end:
        start = start + 1
        end = end - 1
        if string[start] != string[end]:
            return False
    return True


if __name__ == "__main__":
    print(isPalindromeRecursive("alpha"))  # should output false
    print(isPalindromeRecursive("racecar"))  # should output true
    print(isPalindromeRecursive("abba"))  # should output true

    print(isPalindromeReverse("alpha"))  # should output false
    print(isPalindromeReverse("racecar"))  # should output true
    print(isPalindromeReverse("abba"))  # should output true

    print(isPalindromeIterative("alpha"))  # should output false
    print(isPalindromeIterative("racecar"))  # should output true
    print(isPalindromeIterative("abba"))  # should output true
