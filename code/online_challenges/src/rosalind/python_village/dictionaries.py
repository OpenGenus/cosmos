# Find the occurences of each word in the sentence
def dictionaries(sentence):
    words = {}

    for word in sentence.split(" "):
        if word in words:
            words[word] = words.get(word) + 1
        else:
            words[word] = 1

    for key, value in words.items():
        print(key, value)