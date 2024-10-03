def main():
    """
    Determine whether or not a string is a palindrome.
    :print: 'That's a palindrome.' if the string is a palindrome,
             'That isn't a palindrome' otherwise.
    """
    input_str = input("Enter a string: ")
    if is_palindrome(input_str):
        print("That's a palindrome.")
    else:
        print("That isn't a palindrome.")


def is_palindrome(string):
    """
    Determine whether or not a string is a palindrome.
    :param string: string the characters to check
    :return: True if the string is a palindrome, False otherwise
    """

    # check that the word is not one character or empty
    if len(string) <= 1:

        # if it gets to this statement, it's a palindrome
        return True

    # check if the characters at each index are the same
    if string[0] == string[-1]:

        # if it gets to this statement, it's a palindrome
        return is_palindrome(string[1:-1])


# Call the main function.
if __name__ == "__main__":
    main()
