"""
A pangram or holoalphabetic sentence is a sentence using every letter of a given alphabet at least once.
The best-known English pangram is "The quick brown fox jumps over the lazy dog."
A pangrammatic lipogram is a text that uses every letter of the alphabet but excludes one of them. 
"""
# Part of Cosmos by OpenGenus Foundation
#
alphabet = "abcdefghijklmnopqrstuvwxyz"


def pangrammaticChecker(string):
    string.lower()
    counter = 0
    for x in alphabet:
        if string.find(x) < 0:
            counter += 1
    if counter == 0:
        result = "Pangram"
    elif counter == 1:
        result = "Pangrammatic Lipogram"
    else:
        result = "Not a pangram but might a lipogram"
    return result


if __name__ == "__main__":
    print(pangrammaticChecker("The quick brown fox jumps over the lazy dog"))
