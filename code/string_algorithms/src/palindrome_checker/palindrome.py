def is_palindrome_recursive(string):
    if len(string) <= 1:
        return True

    if string[0] != string[-1]:
        return False

    return is_palindrome_recursive(string[1:-1])


def is_palindrome_reverse(string):
    return string == string[::-1]


def is_palindrome_iterative(string):
    start = 0
    end = len(string) - 1

    while start < end:
        if string[start] != string[end]:
            return False

        start += 1
        end -= 1

    return True


if __name__ == "__main__":
    print(is_palindrome_recursive("alpha"))  # should output false
    print(is_palindrome_recursive("racecar"))  # should output true
    print(is_palindrome_recursive("abba"))  # should output true

    print(is_palindrome_reverse("alpha"))  # should output false
    print(is_palindrome_reverse("racecar"))  # should output true
    print(is_palindrome_reverse("abba"))  # should output true

    print(is_palindrome_iterative("alpha"))  # should output false
    print(is_palindrome_iterative("racecar"))  # should output true
    print(is_palindrome_iterative("abba"))  # should output true
