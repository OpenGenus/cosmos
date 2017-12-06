#!/bin/sh

# Check if a given string is palindrome
palindrome()
{
    str=$1
    revstr=$(echo "$1" | rev)
    if [ "$str" = "$revstr" ] ; then
        return 0
    fi
    return 255
}

# Example
# Palindrome
if palindrome "aba" ; then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi

# Not Palindrome
if palindrome "abcdef" ; then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
