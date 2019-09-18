#!/usr/bin/env python3


def compress(input_string):
    """Compresses the given input string"""

    # Build the dictionary
    dict_size = 256  # All ASCII characters
    dictionary = {chr(i): i for i in range(dict_size)}

    buffer = ""
    result = []
    for ch in input_string:
        tmp = buffer + ch
        if tmp in dictionary:
            buffer = tmp
        else:
            result.append(dictionary[buffer])
            dictionary[tmp] = dict_size
            dict_size += 1
            buffer = ch
    if buffer:
        result.append(dictionary[buffer])
    return result


def decompress(compressed):
    """Given a list of numbers given by compress to a string"""

    dict_size = 256  # ASCII characters
    dictionary = {i: chr(i) for i in range(dict_size)}

    result = ""
    buffer = chr(compressed.pop(0))
    result += buffer
    for ch in compressed:
        if ch in dictionary:
            entry = dictionary[ch]
        elif ch == dict_size:
            entry = ch + ch[0]
        else:
            raise ValueError("Bad Compression for %s" % ch)
        result += entry

        dictionary[dict_size] = buffer = entry[0]
        dict_size += 1

        buffer = entry
    return result


if __name__ == "__main__":
    """Test cases for LZW"""

    # Test 1
    test_case_1 = "Hello World!!"
    compressed = compress(test_case_1)
    print(compressed)
    decompressed = decompress(compressed)
    print(decompressed)
