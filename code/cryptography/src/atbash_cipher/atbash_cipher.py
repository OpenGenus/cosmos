# Programmer: Elizabeth Viele
# Updated: 10/07/2017
# Part of Cosmos by OpenGenus Foundation
import argparse


"""
Function to encode/decode given string
"""


def cipher(string):
    newstring = ""
    char = ""
    for i in string:
        # Get each individual character from the string and get it's number
        char = get_switch_char(i)
        newstring += char

    return newstring


"""
Get the number character associated with given character
"""


def get_switch_char(char):
    # create the list of the corresponding characters
    char_dict = dict()
    char_dict["a"] = "z"
    char_dict["b"] = "y"
    char_dict["c"] = "x"
    char_dict["d"] = "w"
    char_dict["e"] = "v"
    char_dict["f"] = "u"
    char_dict["g"] = "t"
    char_dict["h"] = "s"
    char_dict["i"] = "r"
    char_dict["j"] = "q"
    char_dict["k"] = "p"
    char_dict["l"] = "o"
    char_dict["m"] = "n"
    char_dict["z"] = "a"
    char_dict["y"] = "b"
    char_dict["x"] = "c"
    char_dict["w"] = "d"
    char_dict["v"] = "e"
    char_dict["u"] = "f"
    char_dict["t"] = "g"
    char_dict["s"] = "h"
    char_dict["r"] = "i"
    char_dict["q"] = "j"
    char_dict["p"] = "k"
    char_dict["o"] = "l"
    char_dict["n"] = "m"

    return char_dict[char]


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("string")

    # parse the argument
    args = parser.parse_args()

    # run the function
    new_string = cipher(args.string.lower())

    # print translated answer
    print("Your translated string is: " + new_string)