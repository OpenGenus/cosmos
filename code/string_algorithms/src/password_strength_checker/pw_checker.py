# coding=utf-8
# Author: Vitor Ribeiro

# This a program to check the security of passwords.

# Passwords must be at least 8 characters long.
# Passwords must contain at least one uppercase letter and one number.

import re, pyperclip

# First you need to copy your password to the clipboard, the program will do the rest.

password = pyperclip.paste()

eightLettersRegex = re.compile(r"\S{8,}")

oneUppercaseRegex = re.compile(r"[A-Z]")

oneNumberRegex = re.compile(r"\d")

check = {
    eightLettersRegex: "Your password must be 8 letters",
    oneUppercaseRegex: "Your password must have at least one uppercase Letter.",
    oneNumberRegex: "Your password must have at least one number.",
}

print("Analyzing your password.")

count = 1
for regex, msg in check.items():
    mo = regex.search(password)
    if mo == None:
        print(msg)
        break
    if count == len(check):
        print("Good! Your password is strong enough!")
    count += 1

print("End.")
