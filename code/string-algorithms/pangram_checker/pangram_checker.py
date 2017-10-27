# Part of Cosmos by OpenGenus Foundation

def pangram_checker(text):
    return {chr(i) for i in range(ord('a'), ord('z') + 1)}.issubset(text.lower())

print(pangram_checker('hello')) # False
print(pangram_checker('The quick brown fox jumps over the lazy dog')) # True
