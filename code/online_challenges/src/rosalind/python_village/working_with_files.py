# Print even number lines
def workingWithFiles():
    rosalind = open("C:/Users/Chris/Downloads/rosalind_ini5.txt")
    parity = False

    for line in rosalind:
        if parity:
            print(line)
        parity = not parity

    rosalind.close()