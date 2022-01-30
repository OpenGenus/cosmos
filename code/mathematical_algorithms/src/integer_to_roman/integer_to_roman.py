romanNumerals = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I",
}


def integerToRoman(number):
    result = ""

    for integer, romanNumber in romanNumerals.items():
        while number >= integer:
            result += romanNumber
            number -= integer
    return result


num = int(input("Enter a number: "))

print("\nYour number: " + str(num))
print("Your number in Roman Numerals: " + integerToRoman(num))
