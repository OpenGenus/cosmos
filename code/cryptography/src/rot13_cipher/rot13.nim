# Part of Cosmos by OpenGenus Foundation

proc rot13(str: string): string =
    var rotated = ""
    for ch in str:
        let asciiVal = ord(ch)
        if asciiVal >= 65 and asciiVal <= 90:
            rotated &= chr(65 + ((asciiVal - 52) %% 26))
        elif asciiVal >= 97 and asciiVal <= 122:
            rotated &= chr(97 + ((asciiVal - 84) %% 26))
        else:
            rotated &= ch
    rotated

assert rot13("Why did the chicken cross the road?") == "Jul qvq gur puvpxra pebff gur ebnq?"
assert rot13("Gb trg gb gur bgure fvqr!") == "To get to the other side!"
