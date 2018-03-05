count = 0

def make_sentence(str_piece, dictionaries):
    global count
    if len(str_piece) == 0:
        return True
    for i in range(0, len(str_piece)):
        prefix, suffix = str_piece[0:i], str_piece[i:]
        if ((prefix in dictionaries and suffix in dictionaries)
                or (prefix in dictionaries
                    and make_sentence(suffix, dictionaries))):
            count += 1
    return True
if __name__ == "__main__":
    dictionaries = ["", "app", "let", "t", "apple", "applet"]
    word = "applet"
    make_sentence(word, dictionaries)
print count
