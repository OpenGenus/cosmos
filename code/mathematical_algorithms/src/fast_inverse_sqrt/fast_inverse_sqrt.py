import struct


def fast_inverse_square_root(num):

    half = num / 2  # stores half of initial input
    unpacked_value = struct.unpack("!I", struct.pack("!f", num))[
        0
    ]  # unpacks input to get integer value from float
    bit_value = unpacked_value >> 1  # right bit shift
    magic_number = 0x5F3759DF  # predetermined magic value
    bit_result = format(
        (magic_number - bit_value), "032b"
    )  # subtracts magic number and bit value
    float_result = struct.unpack("!f", struct.pack("!I", int(bit_result, 2)))[
        0
    ]  # converts 32 bit result to float result
    precise_result = float_result * (
        1.5 - half * float_result * float_result
    )  # applies newton's method to get more precise value

    return precise_result


print(fast_inverse_square_root(3.14))
# estimated value: 0.5640973663058647 actual value: 0.564332648
