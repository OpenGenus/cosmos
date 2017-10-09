#Author: Amit Kr. Singh
#Github: @amitsin6h
#Social: @amitsin6h
#OpenGenus Contributor

def PalindromeCheck(self):
    palindrome = self[::-1]
    if (self == palindrome):
        print True
    else:
        print False

PalindromeCheck('madam')
