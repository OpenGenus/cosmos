initial_hash_values = [
    "6a09e667",
    "bb67ae85",
    "3c6ef372",
    "a54ff53a",
    "510e527f",
    "9b05688c",
    "1f83d9ab",
    "5be0cd19",
]

sha_256_constants = [
    "428a2f98",
    "71374491",
    "b5c0fbcf",
    "e9b5dba5",
    "3956c25b",
    "59f111f1",
    "923f82a4",
    "ab1c5ed5",
    "d807aa98",
    "12835b01",
    "243185be",
    "550c7dc3",
    "72be5d74",
    "80deb1fe",
    "9bdc06a7",
    "c19bf174",
    "e49b69c1",
    "efbe4786",
    "0fc19dc6",
    "240ca1cc",
    "2de92c6f",
    "4a7484aa",
    "5cb0a9dc",
    "76f988da",
    "983e5152",
    "a831c66d",
    "b00327c8",
    "bf597fc7",
    "c6e00bf3",
    "d5a79147",
    "06ca6351",
    "14292967",
    "27b70a85",
    "2e1b2138",
    "4d2c6dfc",
    "53380d13",
    "650a7354",
    "766a0abb",
    "81c2c92e",
    "92722c85",
    "a2bfe8a1",
    "a81a664b",
    "c24b8b70",
    "c76c51a3",
    "d192e819",
    "d6990624",
    "f40e3585",
    "106aa070",
    "19a4c116",
    "1e376c08",
    "2748774c",
    "34b0bcb5",
    "391c0cb3",
    "4ed8aa4a",
    "5b9cca4f",
    "682e6ff3",
    "748f82ee",
    "78a5636f",
    "84c87814",
    "8cc70208",
    "90befffa",
    "a4506ceb",
    "bef9a3f7",
    "c67178f2",
]


def dec_to_bin(dec):
    return str(format(dec, "b"))


def dec_to_bin_8_bit(dec):
    return str(format(dec, "08b"))


def dec_to_bin_32_bit(dec):
    return str(format(dec, "032b"))


def dec_to_bin_64_bit(dec):
    return str(format(dec, "064b"))


def dec_to_hex(dec):
    return str(format(dec, "x"))


def bin_to_dec(bin_string):
    return int(bin_string, 2)


def hex_to_dec(hex_string):
    return int(hex_string, 16)


def L_P(SET, n):
    to_return = []
    j = 0
    k = n
    while k < len(SET) + 1:
        to_return.append(SET[j:k])
        j = k
        k += n
    return to_return


def string_to_list(bit_string):
    bit_list = []
    for i in range(len(bit_string)):
        bit_list.append(bit_string[i])
    return bit_list


def list_to_string(bit_list):
    bit_string = ""
    for i in range(len(bit_list)):
        bit_string += bit_list[i]
    return bit_string


def rotate_right(bit_string, n):
    bit_list = string_to_list(bit_string)
    for i in range(n):
        last_elem = list(bit_list.pop(-1))
        bit_list = last_elem + bit_list
    return list_to_string(bit_list)


def shift_right(bit_string, n):
    len_bit_string = len(bit_string)
    bit_string = bit_string[: len_bit_string - n :]
    front = "0" * n
    return front + bit_string


def mod_32_addition(input_set):
    return sum(input_set) % 4294967296


def xor_2str(string_1, string_2):
    xor_string = ""
    for i in range(len(string_1)):
        if string_1[i] == string_2[i]:
            xor_string += "0"
        else:
            xor_string += "1"
    return xor_string


def and_2str(string_1, string_2):
    and_list = []
    for i in range(len(string_1)):
        if string_1[i] == "1" and string_2[i] == "1":
            and_list.append("1")
        else:
            and_list.append("0")
    return list_to_string(and_list)


def or_2str(string_1, string_2):
    or_list = []
    for i in range(len(string_1)):
        if string_1[i] == "0" and string_2[i] == "0":
            or_list.append("0")
        else:
            or_list.append("1")
    return list_to_string(or_list)


def not_str(bit_string):
    not_string = ""
    for i in range(len(bit_string)):
        if bit_string[i] == "0":
            not_string += "1"
        else:
            not_string += "0"
    return not_string


"""
SHA-256 Specific Functions:
"""


def Ch(x, y, z):
    return xor_2str(and_2str(x, y), and_2str(not_str(x), z))


def Maj(x, y, z):
    return xor_2str(xor_2str(and_2str(x, y), and_2str(x, z)), and_2str(y, z))


def e_0(x):
    return xor_2str(
        xor_2str(rotate_right(x, 2), rotate_right(x, 13)), rotate_right(x, 22)
    )


def e_1(x):
    return xor_2str(
        xor_2str(rotate_right(x, 6), rotate_right(x, 11)), rotate_right(x, 25)
    )


def s_0(x):
    return xor_2str(
        xor_2str(rotate_right(x, 7), rotate_right(x, 18)), shift_right(x, 3)
    )


def s_1(x):
    return xor_2str(
        xor_2str(rotate_right(x, 17), rotate_right(x, 19)), shift_right(x, 10)
    )


def message_pad(bit_list):
    pad_one = bit_list + "1"
    pad_len = len(pad_one)
    k = 0
    while ((pad_len + k) - 448) % 512 != 0:
        k += 1
    back_append_0 = "0" * k
    back_append_1 = dec_to_bin_64_bit(len(bit_list))
    return pad_one + back_append_0 + back_append_1


def message_bit_return(string_input):
    bit_list = []
    for i in range(len(string_input)):
        bit_list.append(dec_to_bin_8_bit(ord(string_input[i])))
    return list_to_string(bit_list)


def message_pre_pro(input_string):
    bit_main = message_bit_return(input_string)
    return message_pad(bit_main)


def message_parsing(input_string):
    return L_P(message_pre_pro(input_string), 32)


def message_schedule(index, w_t):
    new_word = dec_to_bin_32_bit(
        mod_32_addition(
            [
                bin_to_dec(s_1(w_t[index - 2])),
                bin_to_dec(w_t[index - 7]),
                bin_to_dec(s_0(w_t[index - 15])),
                bin_to_dec(w_t[index - 16]),
            ]
        )
    )
    return new_word


def sha_256(input_string):
    w_t = message_parsing(input_string)
    a = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[0]))
    b = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[1]))
    c = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[2]))
    d = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[3]))
    e = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[4]))
    f = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[5]))
    g = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[6]))
    h = dec_to_bin_32_bit(hex_to_dec(initial_hash_values[7]))
    for i in range(0, 64):
        if i <= 15:
            t_1 = mod_32_addition(
                [
                    bin_to_dec(h),
                    bin_to_dec(e_1(e)),
                    bin_to_dec(Ch(e, f, g)),
                    hex_to_dec(sha_256_constants[i]),
                    bin_to_dec(w_t[i]),
                ]
            )
            t_2 = mod_32_addition([bin_to_dec(e_0(a)), bin_to_dec(Maj(a, b, c))])
            h = g
            g = f
            f = e
            e = mod_32_addition([bin_to_dec(d), t_1])
            d = c
            c = b
            b = a
            a = mod_32_addition([t_1, t_2])
            a = dec_to_bin_32_bit(a)
            e = dec_to_bin_32_bit(e)
        else:
            w_t.append(message_schedule(i, w_t))
            t_1 = mod_32_addition(
                [
                    bin_to_dec(h),
                    bin_to_dec(e_1(e)),
                    bin_to_dec(Ch(e, f, g)),
                    hex_to_dec(sha_256_constants[i]),
                    bin_to_dec(w_t[i]),
                ]
            )
            t_2 = mod_32_addition([bin_to_dec(e_0(a)), bin_to_dec(Maj(a, b, c))])
            h = g
            g = f
            f = e
            e = mod_32_addition([bin_to_dec(d), t_1])
            d = c
            c = b
            b = a
            a = mod_32_addition([t_1, t_2])
            a = dec_to_bin_32_bit(a)
            e = dec_to_bin_32_bit(e)
    hash_0 = mod_32_addition([hex_to_dec(initial_hash_values[0]), bin_to_dec(a)])
    hash_1 = mod_32_addition([hex_to_dec(initial_hash_values[1]), bin_to_dec(b)])
    hash_2 = mod_32_addition([hex_to_dec(initial_hash_values[2]), bin_to_dec(c)])
    hash_3 = mod_32_addition([hex_to_dec(initial_hash_values[3]), bin_to_dec(d)])
    hash_4 = mod_32_addition([hex_to_dec(initial_hash_values[4]), bin_to_dec(e)])
    hash_5 = mod_32_addition([hex_to_dec(initial_hash_values[5]), bin_to_dec(f)])
    hash_6 = mod_32_addition([hex_to_dec(initial_hash_values[6]), bin_to_dec(g)])
    hash_7 = mod_32_addition([hex_to_dec(initial_hash_values[7]), bin_to_dec(h)])
    final_hash = [
        dec_to_hex(hash_0),
        dec_to_hex(hash_1),
        dec_to_hex(hash_2),
        dec_to_hex(hash_3),
        dec_to_hex(hash_4),
        dec_to_hex(hash_5),
        dec_to_hex(hash_6),
        dec_to_hex(hash_7),
    ]
    return "".join(final_hash)


assert (
    sha_256("cosmos")
) == "4cbe19716b1aa73a67dc4b28c34391879b503259fc76852082b4dafcf0de85b2"
