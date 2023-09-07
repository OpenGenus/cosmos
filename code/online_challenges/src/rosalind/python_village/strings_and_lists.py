# Splice the string with the given indices
def stringsAndLists():

    parseString = input("String: ")
    i1 = int(input("First index: "))
    i2 = int(input("Second index: "))
    i3 = int(input("Third index: "))
    i4 = int(input("Fourth index: "))

    return parseString[i1:i2+1] + " " + parseString[i3:i4+1]