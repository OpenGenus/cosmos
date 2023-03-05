'''
 * Part of Cosmos by OpenGenus Foundation.
 * Determine if the machine is in Little Endian or Big Endian.
 '''

import struct # To convert the number to bytes in network byte order

def is_big_endian(num):
    # Use pack to convert the number to bytes in network byte order (big endian)
    packed = struct.pack('!H', num)
    # Check if the first byte is zero, indicating little endian
    return packed[0] == 0

input_num = 1
if is_big_endian(input_num):
    print("Big Endian")
else:
    print("Little Endian")
