func is_palindrome(str: string): bool =
    let length = str.len - 1
    for i in 0..(length mod 2):
        if str[i] != str[length - i]:
            return false
    true

from unicode import reversed
func is_palindrome_str_rev(str: string): bool =
    str.reversed == str

when isMainModule:
    assert("madam".is_palindrome)
    assert(not is_palindrome("nimrod"))
    assert("madam".is_palindrome_str_rev)
