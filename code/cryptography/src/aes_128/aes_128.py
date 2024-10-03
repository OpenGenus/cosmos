# AES 128
# By: David Beltrán (github.com/debeltranc)
# National university of Colombia
# Language: python
# This code demonstrates how AES works internally, for academic purposes only.
# If you want to use AES in your production software use robust libraries
# like PyCrypto


# Lookup tables
# Using lookup tables can help you to reduce time complexity, at cost of space complexity.

# S-box
# Used by the subBytes transformation
sBox = [
    0x63,
    0x7C,
    0x77,
    0x7B,
    0xF2,
    0x6B,
    0x6F,
    0xC5,
    0x30,
    0x01,
    0x67,
    0x2B,
    0xFE,
    0xD7,
    0xAB,
    0x76,
    0xCA,
    0x82,
    0xC9,
    0x7D,
    0xFA,
    0x59,
    0x47,
    0xF0,
    0xAD,
    0xD4,
    0xA2,
    0xAF,
    0x9C,
    0xA4,
    0x72,
    0xC0,
    0xB7,
    0xFD,
    0x93,
    0x26,
    0x36,
    0x3F,
    0xF7,
    0xCC,
    0x34,
    0xA5,
    0xE5,
    0xF1,
    0x71,
    0xD8,
    0x31,
    0x15,
    0x04,
    0xC7,
    0x23,
    0xC3,
    0x18,
    0x96,
    0x05,
    0x9A,
    0x07,
    0x12,
    0x80,
    0xE2,
    0xEB,
    0x27,
    0xB2,
    0x75,
    0x09,
    0x83,
    0x2C,
    0x1A,
    0x1B,
    0x6E,
    0x5A,
    0xA0,
    0x52,
    0x3B,
    0xD6,
    0xB3,
    0x29,
    0xE3,
    0x2F,
    0x84,
    0x53,
    0xD1,
    0x00,
    0xED,
    0x20,
    0xFC,
    0xB1,
    0x5B,
    0x6A,
    0xCB,
    0xBE,
    0x39,
    0x4A,
    0x4C,
    0x58,
    0xCF,
    0xD0,
    0xEF,
    0xAA,
    0xFB,
    0x43,
    0x4D,
    0x33,
    0x85,
    0x45,
    0xF9,
    0x02,
    0x7F,
    0x50,
    0x3C,
    0x9F,
    0xA8,
    0x51,
    0xA3,
    0x40,
    0x8F,
    0x92,
    0x9D,
    0x38,
    0xF5,
    0xBC,
    0xB6,
    0xDA,
    0x21,
    0x10,
    0xFF,
    0xF3,
    0xD2,
    0xCD,
    0x0C,
    0x13,
    0xEC,
    0x5F,
    0x97,
    0x44,
    0x17,
    0xC4,
    0xA7,
    0x7E,
    0x3D,
    0x64,
    0x5D,
    0x19,
    0x73,
    0x60,
    0x81,
    0x4F,
    0xDC,
    0x22,
    0x2A,
    0x90,
    0x88,
    0x46,
    0xEE,
    0xB8,
    0x14,
    0xDE,
    0x5E,
    0x0B,
    0xDB,
    0xE0,
    0x32,
    0x3A,
    0x0A,
    0x49,
    0x06,
    0x24,
    0x5C,
    0xC2,
    0xD3,
    0xAC,
    0x62,
    0x91,
    0x95,
    0xE4,
    0x79,
    0xE7,
    0xC8,
    0x37,
    0x6D,
    0x8D,
    0xD5,
    0x4E,
    0xA9,
    0x6C,
    0x56,
    0xF4,
    0xEA,
    0x65,
    0x7A,
    0xAE,
    0x08,
    0xBA,
    0x78,
    0x25,
    0x2E,
    0x1C,
    0xA6,
    0xB4,
    0xC6,
    0xE8,
    0xDD,
    0x74,
    0x1F,
    0x4B,
    0xBD,
    0x8B,
    0x8A,
    0x70,
    0x3E,
    0xB5,
    0x66,
    0x48,
    0x03,
    0xF6,
    0x0E,
    0x61,
    0x35,
    0x57,
    0xB9,
    0x86,
    0xC1,
    0x1D,
    0x9E,
    0xE1,
    0xF8,
    0x98,
    0x11,
    0x69,
    0xD9,
    0x8E,
    0x94,
    0x9B,
    0x1E,
    0x87,
    0xE9,
    0xCE,
    0x55,
    0x28,
    0xDF,
    0x8C,
    0xA1,
    0x89,
    0x0D,
    0xBF,
    0xE6,
    0x42,
    0x68,
    0x41,
    0x99,
    0x2D,
    0x0F,
    0xB0,
    0x54,
    0xBB,
    0x16,
]

# Inverted S-box
# Used by the invSubBytes transformation
isBox = [
    0x52,
    0x09,
    0x6A,
    0xD5,
    0x30,
    0x36,
    0xA5,
    0x38,
    0xBF,
    0x40,
    0xA3,
    0x9E,
    0x81,
    0xF3,
    0xD7,
    0xFB,
    0x7C,
    0xE3,
    0x39,
    0x82,
    0x9B,
    0x2F,
    0xFF,
    0x87,
    0x34,
    0x8E,
    0x43,
    0x44,
    0xC4,
    0xDE,
    0xE9,
    0xCB,
    0x54,
    0x7B,
    0x94,
    0x32,
    0xA6,
    0xC2,
    0x23,
    0x3D,
    0xEE,
    0x4C,
    0x95,
    0x0B,
    0x42,
    0xFA,
    0xC3,
    0x4E,
    0x08,
    0x2E,
    0xA1,
    0x66,
    0x28,
    0xD9,
    0x24,
    0xB2,
    0x76,
    0x5B,
    0xA2,
    0x49,
    0x6D,
    0x8B,
    0xD1,
    0x25,
    0x72,
    0xF8,
    0xF6,
    0x64,
    0x86,
    0x68,
    0x98,
    0x16,
    0xD4,
    0xA4,
    0x5C,
    0xCC,
    0x5D,
    0x65,
    0xB6,
    0x92,
    0x6C,
    0x70,
    0x48,
    0x50,
    0xFD,
    0xED,
    0xB9,
    0xDA,
    0x5E,
    0x15,
    0x46,
    0x57,
    0xA7,
    0x8D,
    0x9D,
    0x84,
    0x90,
    0xD8,
    0xAB,
    0x00,
    0x8C,
    0xBC,
    0xD3,
    0x0A,
    0xF7,
    0xE4,
    0x58,
    0x05,
    0xB8,
    0xB3,
    0x45,
    0x06,
    0xD0,
    0x2C,
    0x1E,
    0x8F,
    0xCA,
    0x3F,
    0x0F,
    0x02,
    0xC1,
    0xAF,
    0xBD,
    0x03,
    0x01,
    0x13,
    0x8A,
    0x6B,
    0x3A,
    0x91,
    0x11,
    0x41,
    0x4F,
    0x67,
    0xDC,
    0xEA,
    0x97,
    0xF2,
    0xCF,
    0xCE,
    0xF0,
    0xB4,
    0xE6,
    0x73,
    0x96,
    0xAC,
    0x74,
    0x22,
    0xE7,
    0xAD,
    0x35,
    0x85,
    0xE2,
    0xF9,
    0x37,
    0xE8,
    0x1C,
    0x75,
    0xDF,
    0x6E,
    0x47,
    0xF1,
    0x1A,
    0x71,
    0x1D,
    0x29,
    0xC5,
    0x89,
    0x6F,
    0xB7,
    0x62,
    0x0E,
    0xAA,
    0x18,
    0xBE,
    0x1B,
    0xFC,
    0x56,
    0x3E,
    0x4B,
    0xC6,
    0xD2,
    0x79,
    0x20,
    0x9A,
    0xDB,
    0xC0,
    0xFE,
    0x78,
    0xCD,
    0x5A,
    0xF4,
    0x1F,
    0xDD,
    0xA8,
    0x33,
    0x88,
    0x07,
    0xC7,
    0x31,
    0xB1,
    0x12,
    0x10,
    0x59,
    0x27,
    0x80,
    0xEC,
    0x5F,
    0x60,
    0x51,
    0x7F,
    0xA9,
    0x19,
    0xB5,
    0x4A,
    0x0D,
    0x2D,
    0xE5,
    0x7A,
    0x9F,
    0x93,
    0xC9,
    0x9C,
    0xEF,
    0xA0,
    0xE0,
    0x3B,
    0x4D,
    0xAE,
    0x2A,
    0xF5,
    0xB0,
    0xC8,
    0xEB,
    0xBB,
    0x3C,
    0x83,
    0x53,
    0x99,
    0x61,
    0x17,
    0x2B,
    0x04,
    0x7E,
    0xBA,
    0x77,
    0xD6,
    0x26,
    0xE1,
    0x69,
    0x14,
    0x63,
    0x55,
    0x21,
    0x0C,
    0x7D,
]

# E Table
# Used to perform Galois Field multiplications
eTable = [
    0x01,
    0x03,
    0x05,
    0x0F,
    0x11,
    0x33,
    0x55,
    0xFF,
    0x1A,
    0x2E,
    0x72,
    0x96,
    0xA1,
    0xF8,
    0x13,
    0x35,
    0x5F,
    0xE1,
    0x38,
    0x48,
    0xD8,
    0x73,
    0x95,
    0xA4,
    0xF7,
    0x02,
    0x06,
    0x0A,
    0x1E,
    0x22,
    0x66,
    0xAA,
    0xE5,
    0x34,
    0x5C,
    0xE4,
    0x37,
    0x59,
    0xEB,
    0x26,
    0x6A,
    0xBE,
    0xD9,
    0x70,
    0x90,
    0xAB,
    0xE6,
    0x31,
    0x53,
    0xF5,
    0x04,
    0x0C,
    0x14,
    0x3C,
    0x44,
    0xCC,
    0x4F,
    0xD1,
    0x68,
    0xB8,
    0xD3,
    0x6E,
    0xB2,
    0xCD,
    0x4C,
    0xD4,
    0x67,
    0xA9,
    0xE0,
    0x3B,
    0x4D,
    0xD7,
    0x62,
    0xA6,
    0xF1,
    0x08,
    0x18,
    0x28,
    0x78,
    0x88,
    0x83,
    0x9E,
    0xB9,
    0xD0,
    0x6B,
    0xBD,
    0xDC,
    0x7F,
    0x81,
    0x98,
    0xB3,
    0xCE,
    0x49,
    0xDB,
    0x76,
    0x9A,
    0xB5,
    0xC4,
    0x57,
    0xF9,
    0x10,
    0x30,
    0x50,
    0xF0,
    0x0B,
    0x1D,
    0x27,
    0x69,
    0xBB,
    0xD6,
    0x61,
    0xA3,
    0xFE,
    0x19,
    0x2B,
    0x7D,
    0x87,
    0x92,
    0xAD,
    0xEC,
    0x2F,
    0x71,
    0x93,
    0xAE,
    0xE9,
    0x20,
    0x60,
    0xA0,
    0xFB,
    0x16,
    0x3A,
    0x4E,
    0xD2,
    0x6D,
    0xB7,
    0xC2,
    0x5D,
    0xE7,
    0x32,
    0x56,
    0xFA,
    0x15,
    0x3F,
    0x41,
    0xC3,
    0x5E,
    0xE2,
    0x3D,
    0x47,
    0xC9,
    0x40,
    0xC0,
    0x5B,
    0xED,
    0x2C,
    0x74,
    0x9C,
    0xBF,
    0xDA,
    0x75,
    0x9F,
    0xBA,
    0xD5,
    0x64,
    0xAC,
    0xEF,
    0x2A,
    0x7E,
    0x82,
    0x9D,
    0xBC,
    0xDF,
    0x7A,
    0x8E,
    0x89,
    0x80,
    0x9B,
    0xB6,
    0xC1,
    0x58,
    0xE8,
    0x23,
    0x65,
    0xAF,
    0xEA,
    0x25,
    0x6F,
    0xB1,
    0xC8,
    0x43,
    0xC5,
    0x54,
    0xFC,
    0x1F,
    0x21,
    0x63,
    0xA5,
    0xF4,
    0x07,
    0x09,
    0x1B,
    0x2D,
    0x77,
    0x99,
    0xB0,
    0xCB,
    0x46,
    0xCA,
    0x45,
    0xCF,
    0x4A,
    0xDE,
    0x79,
    0x8B,
    0x86,
    0x91,
    0xA8,
    0xE3,
    0x3E,
    0x42,
    0xC6,
    0x51,
    0xF3,
    0x0E,
    0x12,
    0x36,
    0x5A,
    0xEE,
    0x29,
    0x7B,
    0x8D,
    0x8C,
    0x8F,
    0x8A,
    0x85,
    0x94,
    0xA7,
    0xF2,
    0x0D,
    0x17,
    0x39,
    0x4B,
    0xDD,
    0x7C,
    0x84,
    0x97,
    0xA2,
    0xFD,
    0x1C,
    0x24,
    0x6C,
    0xB4,
    0xC7,
    0x52,
    0xF6,
    0x01,
]

# L Table
# Used to perform Galois Field multiplications
lTable = [
    None,
    0x00,
    0x19,
    0x01,
    0x32,
    0x02,
    0x1A,
    0xC6,
    0x4B,
    0xC7,
    0x1B,
    0x68,
    0x33,
    0xEE,
    0xDF,
    0x03,
    0x64,
    0x04,
    0xE0,
    0x0E,
    0x34,
    0x8D,
    0x81,
    0xEF,
    0x4C,
    0x71,
    0x08,
    0xC8,
    0xF8,
    0x69,
    0x1C,
    0xC1,
    0x7D,
    0xC2,
    0x1D,
    0xB5,
    0xF9,
    0xB9,
    0x27,
    0x6A,
    0x4D,
    0xE4,
    0xA6,
    0x72,
    0x9A,
    0xC9,
    0x09,
    0x78,
    0x65,
    0x2F,
    0x8A,
    0x05,
    0x21,
    0x0F,
    0xE1,
    0x24,
    0x12,
    0xF0,
    0x82,
    0x45,
    0x35,
    0x93,
    0xDA,
    0x8E,
    0x96,
    0x8F,
    0xDB,
    0xBD,
    0x36,
    0xD0,
    0xCE,
    0x94,
    0x13,
    0x5C,
    0xD2,
    0xF1,
    0x40,
    0x46,
    0x83,
    0x38,
    0x66,
    0xDD,
    0xFD,
    0x30,
    0xBF,
    0x06,
    0x8B,
    0x62,
    0xB3,
    0x25,
    0xE2,
    0x98,
    0x22,
    0x88,
    0x91,
    0x10,
    0x7E,
    0x6E,
    0x48,
    0xC3,
    0xA3,
    0xB6,
    0x1E,
    0x42,
    0x3A,
    0x6B,
    0x28,
    0x54,
    0xFA,
    0x85,
    0x3D,
    0xBA,
    0x2B,
    0x79,
    0x0A,
    0x15,
    0x9B,
    0x9F,
    0x5E,
    0xCA,
    0x4E,
    0xD4,
    0xAC,
    0xE5,
    0xF3,
    0x73,
    0xA7,
    0x57,
    0xAF,
    0x58,
    0xA8,
    0x50,
    0xF4,
    0xEA,
    0xD6,
    0x74,
    0x4F,
    0xAE,
    0xE9,
    0xD5,
    0xE7,
    0xE6,
    0xAD,
    0xE8,
    0x2C,
    0xD7,
    0x75,
    0x7A,
    0xEB,
    0x16,
    0x0B,
    0xF5,
    0x59,
    0xCB,
    0x5F,
    0xB0,
    0x9C,
    0xA9,
    0x51,
    0xA0,
    0x7F,
    0x0C,
    0xF6,
    0x6F,
    0x17,
    0xC4,
    0x49,
    0xEC,
    0xD8,
    0x43,
    0x1F,
    0x2D,
    0xA4,
    0x76,
    0x7B,
    0xB7,
    0xCC,
    0xBB,
    0x3E,
    0x5A,
    0xFB,
    0x60,
    0xB1,
    0x86,
    0x3B,
    0x52,
    0xA1,
    0x6C,
    0xAA,
    0x55,
    0x29,
    0x9D,
    0x97,
    0xB2,
    0x87,
    0x90,
    0x61,
    0xBE,
    0xDC,
    0xFC,
    0xBC,
    0x95,
    0xCF,
    0xCD,
    0x37,
    0x3F,
    0x5B,
    0xD1,
    0x53,
    0x39,
    0x84,
    0x3C,
    0x41,
    0xA2,
    0x6D,
    0x47,
    0x14,
    0x2A,
    0x9E,
    0x5D,
    0x56,
    0xF2,
    0xD3,
    0xAB,
    0x44,
    0x11,
    0x92,
    0xD9,
    0x23,
    0x20,
    0x2E,
    0x89,
    0xB4,
    0x7C,
    0xB8,
    0x26,
    0x77,
    0x99,
    0xE3,
    0xA5,
    0x67,
    0x4A,
    0xED,
    0xDE,
    0xC5,
    0x31,
    0xFE,
    0x18,
    0x0D,
    0x63,
    0x8C,
    0x80,
    0xC0,
    0xF7,
    0x70,
    0x07,
]

# Lookup Functions =============================================================

# Function getInvsBox (decypher process)
# input: numerical (integer) position t look up in the Inverted S-box table.
# output: number at the position <<num>> inside the Inverted S-box table.
def getInvsBox(num):
    return isBox[num]


# Function getsBox
# input: numerical (integer) position t look up in the S-box table.
# output: number at the position <<num>> inside the S-box table.
def getsBox(num):
    return sBox[num]


# ===============================================================================


# Galois field multiplication  =================================================
# The multiplication is simply the result of a lookup of the L-Table, followed
# by the addition of the results, followed by a lookup to the E-Table.
def gMult(a, b):
    # special case check: mutiplying by zero
    if a == 0x00 or b == 0x00:
        return 0x00
    # special case check: multiplying by one
    elif a == 0x01 or b == 0x01:
        return a * b
    # if no special conditions, then lookup on the E-Table the result of adding
    # the lookup of both operands on the L-Table modulo 255
    else:
        return eTable[(lTable[a] + lTable[b]) % 0xFF]


# ===============================================================================


# Functions part of the cypher and decypher processes ==========================

# SubBytes Transformation (cypher process)
# Uses an S-Box to perform byte-by-byte substitution of the State matrix (stmt).
# Purpose: (high) non-linearity, confusion by non-linear substitution.
def subBytes(stmt):
    rt = []
    for i in range(4):
        rt.append([])
        for j in range(4):
            rt[i].append(getsBox(stmt[i][j]))
    return rt


# InvSubBytes Transformation (decypher process)
# The InvSubBytes Transformation is another lookup table using the Inverse S-Box.
def invSubBytes(stmt):
    rt = []
    for i in range(4):
        rt.append([])
        for j in range(4):
            rt[i].append(getInvsBox(stmt[i][j]))
    return rt


# ShiftRow transformation (cypher process)
# The four rows of the state matrix (stmt) are shifted cyclically to the left as follows
#   row 0 is not shifted
#   row 1 is shifted cyclically by 1 position to the left
#   row 2 is shifted cyclically by 2 positions to the left
#   row 3 is shifted cyclically by 3 positions to the left
# Purpose: high diffusion through linear operation.
def shiftRows(stmt):
    return [
        [stmt[0][0], stmt[0][1], stmt[0][2], stmt[0][3]],
        [stmt[1][1], stmt[1][2], stmt[1][3], stmt[1][0]],
        [stmt[2][2], stmt[2][3], stmt[2][0], stmt[2][1]],
        [stmt[3][3], stmt[3][0], stmt[3][1], stmt[3][2]],
    ]


# InvShiftRow Transformation (decypher process)
# The inverse of ShiftRow is obtained by shifting the rows to the right instead of the left.
def invShiftRows(stmt):
    return [
        [stmt[0][0], stmt[0][1], stmt[0][2], stmt[0][3]],
        [stmt[1][3], stmt[1][0], stmt[1][1], stmt[1][2]],
        [stmt[2][2], stmt[2][3], stmt[2][0], stmt[2][1]],
        [stmt[3][1], stmt[3][2], stmt[3][3], stmt[3][0]],
    ]


# MixColumn Transformation (cypher process)
# Each column is treated as a polynomial over GF(2^8) and is then multiplied
# modulo (x^4)+1 with a fixed polynomial 3(x^3)+(x^2)+x+2.
# Purpose: high diffusion through linear operation.
def mixColumns(stmt):
    rtmt = []
    m = [
        [0x02, 0x03, 0x01, 0x01],
        [0x01, 0x02, 0x03, 0x01],
        [0x01, 0x01, 0x02, 0x03],
        [0x03, 0x01, 0x01, 0x02],
    ]
    for i in range(4):
        rtmt.append([])
        for j in range(4):
            rtmt[i].append(
                gMult(m[i][0], stmt[0][j])
                ^ gMult(m[i][1], stmt[1][j])
                ^ gMult(m[i][2], stmt[2][j])
                ^ gMult(m[i][3], stmt[3][j])
            )
    return rtmt


# InvMixColumn Transformation (decypher process)
# The inverse of MixColumn exists because the 4×4 matrix used in MixColumn is invetible.
def InvMixColumns(stmt):
    rtmt = []
    # The transformation InvMixColumn is given by multiplying by the following matrix.
    m = [
        [0x0E, 0x0B, 0x0D, 0x09],
        [0x09, 0x0E, 0x0B, 0x0D],
        [0x0D, 0x09, 0x0E, 0x0B],
        [0x0B, 0x0D, 0x09, 0x0E],
    ]
    for i in range(4):
        rtmt.append([])
        for j in range(4):
            rtmt[i].append(
                gMult(m[i][0], stmt[0][j])
                ^ gMult(m[i][1], stmt[1][j])
                ^ gMult(m[i][2], stmt[2][j])
                ^ gMult(m[i][3], stmt[3][j])
            )
    return rtmt


# AddRoundKey Transformation (cypher and decypher process)
# The Round Key is bitwise XORed to the State.
def addRoundKey(stmt, rk):
    rt = [[], [], [], []]
    for i in range(4):
        for j in range(4):
            rt[i].append(stmt[i][j] ^ rk[i][j])
    return rt


# ==============================================================================

# Key generation functions =====================================================
# AES-128 must first create Nr (10) subkeys as follows:
#   * From a given key k arranged into a 4×4 matrix of bytes, we label the
#     first four columns W[0], W[1], W[2], W[3].
#   * This matrix is expanded by adding 40 more columns W[4], ... , W[43]
#     which are computed recursively as follows:
#       W[i] = W[i − 4] ⊕ W[i − 1] , if i ≡ 0 (mod 4) for i ∈ [4..43]
#       W[i − 4] ⊕ T(W[i − 1]), otherwise for i ∈ [4..43]
#     where T is the transformation of W[i − 1] obtained as follows:
#       Let the elements of the column W[i − 1] be a, b, c, d. Shift these
#       cyclically to obtain b, c, d, a. Now replace each of these bytes
#       with the corresponding element in the S-Box from the ByteSub
#       transformation to get 4 bytes e, f, g, h. Finally, compute the
#       round constant r[i] = 00000010^((i−4)/4) in GF(2^8) then T(W[i − 1])
#       is the columnvector (e ⊕ r[i], f, g, h)
#   * The round key for the ith round consist of the columns W[4i], W[4i+1],
#     W[4i + 2], W[4i + 3].

# rotWord
# The rotate operation takes a 32-bit word and rotates it eight bits to the left
# such that the high eight bits "wrap around" and become the low eight bits of the result.
def rotWord(rw):
    return [rw[1], rw[2], rw[3], rw[0]]


# subWord
# The key schedule uses Rijndael's S-box.
def subWord(rw):
    ret = []
    for i in rw:
        ret.append(getsBox(i))
    return ret


# rcon
# Rcon is what the Rijndael documentation calls the exponentiation of 2 to a user-specified value.
def rcon(r, rw):
    if 1 <= r <= 8:
        return [rw[0] ^ (1 << (r - 1)), rw[1], rw[2], rw[3]]
    elif r == 9:
        return [rw[0] ^ 0x1B, rw[1], rw[2], rw[3]]
    elif r == 10:
        return [rw[0] ^ 0x36, rw[1], rw[2], rw[3]]


# transpose
# not really a key generation function, just a matrix transposition operation
def transpose(matrix):
    return list(zip(*matrix))


# Key generation
# This function returns 10 subkeys following the Rijndael key schedule
def keyGen(keymt):
    roundKeys = {
        0: keymt,
        1: [],
        2: [],
        3: [],
        4: [],
        5: [],
        6: [],
        7: [],
        8: [],
        9: [],
        10: [],
    }
    for i in range(1, 11):
        lrk = transpose(roundKeys[i - 1])
        tr = rcon(i, subWord(rotWord(lrk[-1])))
        rk = []
        for j in range(4):
            rk.append([])
            for k in range(4):
                if j == 0:
                    rk[j].append(tr[k] ^ lrk[j][k])
                else:
                    rk[j].append(rk[j - 1][k] ^ lrk[j][k])
        roundKeys[i] = transpose(rk)
    return roundKeys


# ===============================================================================

# Single block (128 bit text) cypher and decypher operations ===================

# decypher
# inputs: cypher text as a 128-bit hex string, 128-bit hex key (as string)
#         (optional) set process to true if you want to see
#         all the steps of this process
# output: matrix containing clear message in hexadecimal ASCII
def decypher(ct, ky, process=False):
    if process:
        print("decipher process:")
    c1 = ct.replace(" ", "")
    k1 = ky.replace(" ", "")
    keymatrix = [
        [
            int(k1[0] + k1[1], 16),
            int(k1[8] + k1[9], 16),
            int(k1[16] + k1[17], 16),
            int(k1[24] + k1[25], 16),
        ],
        [
            int(k1[2] + k1[3], 16),
            int(k1[10] + k1[11], 16),
            int(k1[18] + k1[19], 16),
            int(k1[26] + k1[27], 16),
        ],
        [
            int(k1[4] + k1[5], 16),
            int(k1[12] + k1[13], 16),
            int(k1[20] + k1[21], 16),
            int(k1[28] + k1[29], 16),
        ],
        [
            int(k1[6] + k1[7], 16),
            int(k1[14] + k1[15], 16),
            int(k1[22] + k1[23], 16),
            int(k1[30] + k1[31], 16),
        ],
    ]
    stamatrix = [
        [
            int(c1[0] + c1[1], 16),
            int(c1[8] + c1[9], 16),
            int(c1[16] + c1[17], 16),
            int(c1[24] + c1[25], 16),
        ],
        [
            int(c1[2] + c1[3], 16),
            int(c1[10] + c1[11], 16),
            int(c1[18] + c1[19], 16),
            int(c1[26] + c1[27], 16),
        ],
        [
            int(c1[4] + c1[5], 16),
            int(c1[12] + c1[13], 16),
            int(c1[20] + c1[21], 16),
            int(c1[28] + c1[29], 16),
        ],
        [
            int(c1[6] + c1[7], 16),
            int(c1[14] + c1[15], 16),
            int(c1[22] + c1[23], 16),
            int(c1[30] + c1[31], 16),
        ],
    ]
    rkeys = keyGen(keymatrix)
    if process:
        print("\n====first Stage====")
        print("keys (10)")
        printMatrix(rkeys[10])
        print("Add round key (10)")
        state = addRoundKey(stamatrix, rkeys[10])
        printMatrix(state)
        print("Inverse Shift Rows")
        state = invShiftRows(state)
        printMatrix(state)
        print("Inverse Sub Bytes")
        state = invSubBytes(state)
        printMatrix(state)
        print("\n====Second Stage====")
    else:
        state = invSubBytes(invShiftRows(addRoundKey(stamatrix, rkeys[10])))
    for i in range(9, 0, -1):
        if process:
            print("keys (" + str(i) + ")")
            printMatrix(rkeys[i])
            print("Add round key (" + str(i) + ")")
            state = addRoundKey(state, rkeys[i])
            printMatrix(state)
            print("Inverse Mix Columns")
            state = InvMixColumns(state)
            printMatrix(state)
            print("Inverse Shift Rows")
            state = invShiftRows(state)
            printMatrix(state)
            print("Inverse Sub Bytes")
            state = invSubBytes(state)
            printMatrix(state)
        else:
            state = invSubBytes(
                invShiftRows(InvMixColumns(addRoundKey(state, rkeys[i])))
            )
    if process:
        print("====Third Stage====")
        print("keys (0")
        printMatrix(rkeys[0])
        print("Add round key (0)")
        state = addRoundKey(state, rkeys[0])
        printMatrix(state)
        print("====Result====")
        return state
    else:
        return addRoundKey(state, rkeys[0])


# cypher
# inputs: clear text message as an ASCII hexadecimal 128-bit string
# 		  128-bit hex key (as string)
#         (optional) set process to true if you want to see
#         all the steps of this process
# output: matrix containing the cypher text in hexadecimal representation
def cypher(mt, ky, process=False):
    if process:
        print("cipher process:")
    m1 = mt.replace(" ", "")
    k1 = ky.replace(" ", "")
    keymatrix = [
        [
            int(k1[0] + k1[1], 16),
            int(k1[8] + k1[9], 16),
            int(k1[16] + k1[17], 16),
            int(k1[24] + k1[25], 16),
        ],
        [
            int(k1[2] + k1[3], 16),
            int(k1[10] + k1[11], 16),
            int(k1[18] + k1[19], 16),
            int(k1[26] + k1[27], 16),
        ],
        [
            int(k1[4] + k1[5], 16),
            int(k1[12] + k1[13], 16),
            int(k1[20] + k1[21], 16),
            int(k1[28] + k1[29], 16),
        ],
        [
            int(k1[6] + k1[7], 16),
            int(k1[14] + k1[15], 16),
            int(k1[22] + k1[23], 16),
            int(k1[30] + k1[31], 16),
        ],
    ]
    stamatrix = [
        [
            int(m1[0] + m1[1], 16),
            int(m1[8] + m1[9], 16),
            int(m1[16] + m1[17], 16),
            int(m1[24] + m1[25], 16),
        ],
        [
            int(m1[2] + m1[3], 16),
            int(m1[10] + m1[11], 16),
            int(m1[18] + m1[19], 16),
            int(m1[26] + m1[27], 16),
        ],
        [
            int(m1[4] + m1[5], 16),
            int(m1[12] + m1[13], 16),
            int(m1[20] + m1[21], 16),
            int(m1[28] + m1[29], 16),
        ],
        [
            int(m1[6] + m1[7], 16),
            int(m1[14] + m1[15], 16),
            int(m1[22] + m1[23], 16),
            int(m1[30] + m1[31], 16),
        ],
    ]
    rkeys = keyGen(keymatrix)
    state = stamatrix
    if process:
        print("\n====first Stage====")
        print("keys (0)")
        printMatrix(rkeys[0])
        print("add round key (0)")
        state = addRoundKey(state, rkeys[0])
        printMatrix(state)
        print("\n====Second Stage====")
    else:
        state = addRoundKey(state, rkeys[0])
    for i in range(1, 10):
        if process:
            print("Sub Bytes")
            state = subBytes(state)
            printMatrix(state)
            print("Shift Rows")
            state = shiftRows(state)
            printMatrix(state)
            print("Mix Columns")
            state = mixColumns(state)
            printMatrix(state)
            print("keys (" + str(i) + ")")
            printMatrix(rkeys[i])
            print("add round key (" + str(i) + ")")
            state = addRoundKey(state, rkeys[i])
            printMatrix(state)
        else:
            state = addRoundKey(mixColumns(shiftRows(subBytes(state))), rkeys[i])
    if process:
        print("\n====third Stage====")
        print("Sub Bytes")
        state = subBytes(state)
        printMatrix(state)
        print("Shift Rows")
        state = shiftRows(state)
        printMatrix(state)
        print("keys (10)")
        printMatrix(rkeys[10])
        print("add round key (10)")
        state = addRoundKey(state, rkeys[10])
        printMatrix(state)
        print("====Result====")
        return transpose(zip(*state))
    else:
        return transpose(addRoundKey(shiftRows(subBytes(state)), rkeys[10]))


# ===============================================================================

# multi block text cypher and decypher =========================================

# encryption
# inputs: clear text message and 128-bit key (as hex string)
#         (optional) set process to true if you want to see
#         all the steps of this process
# output: cypher text as an hexadecimal string
def encryption(message, key, process=False):
    # split the array in 16 bit chunks
    messageArray = hexStringChunks(message.strip())
    # now encrypt the message and store it in a result matrix
    cyphertextArray = list()
    for msg in messageArray:
        cyphertextArray.append(matrixToLinearString(cypher(msg, key, process)))
    # return a string containing an hexadecimal cyphertext
    return "".join(cyphertextArray)


# decryption
# inputs: cypher text and 128-bit key (as hex string)
#         (optional) set process to true if you want to see
#         all the steps of this process
# output: clear text as string
def decryption(cyphertext, key, process=False):
    # split the array in 16 bit ckunks
    # and unhandled error should appear if the text given is not a cyphertext
    # not during this step but while the actual decypher is ocurring
    cyphertextArray = stringChunks(cyphertext.replace(" ", ""))
    # get the cleartext and store it in a result matrix
    messageArray = list()
    for ct in cyphertextArray:
        messageArray.append(matrixToText(decypher(ct, key, process)))
    # return the message, as we fill the last matrix with spaces to have full
    # 128 bit blocks, strip the string before returning it
    return ("".join(messageArray)).strip()


# ===============================================================================

# Formatting functions =========================================================

# Function printMatrix
# input: two-dimensional array of integers
# output: prints a matrix in console
def printMatrix(matrix):
    for i in range(len(matrix)):
        print("|", end=" ")
        for j in range(len(matrix[i])):
            print(format(matrix[i][j], "#04x"), end=" ")
        print("|\n", end="")


# Function matrixToLinearString
# input: two-dimensional array of integers
# output: string containing byte-formatted hexadecimal numbers
def matrixToLinearString(matrix):
    string = ""
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            string += format(matrix[i][j], "02x")
    return string


# Function hexStringChunks
# input: string of text
# output: array containing hexadecimal representation of 16 character
#         chunks of the original string, if a chunk is smaller than
#         16 characters, is filled with spaces
def hexStringChunks(string):
    return [
        str(string[i : 16 + i].ljust(16)[:16]).encode("utf-8").hex()
        for i in range(0, len(string), 16)
    ]


def stringChunks(string):
    return [string[i : 32 + i] for i in range(0, len(string), 32)]


def printHexArray(array):
    print("[" + " ".join("0x{:02x}".format(x) for x in array) + "]")


def matrixToText(matrix):
    nm = transpose(matrix)
    ret = ""
    for i in nm:
        for j in i:
            ret += format(j, "#04x")[2:]
    return bytes.fromhex(ret).decode("utf-8")


# ===============================================================================

# Test use cases ===============================================================
if __name__ == "__main__":
    # This case uses the following message "AES es muy facil"
    # Chosen because has exactly 16 characters (128-bit string)
    # translated into ASCII Hex code gives us 414553206573206d757920666163696c
    # the key to use is 2b7e151628aed2a6abf7158809cf4f3c
    # our expected cypher text is e448e574a374d90cc33c22af9b8eab7f

    m = "41 45 53 20 65 73 20 6d 75 79 20 66 61 63 69 6c"
    c = "e4 48 e5 74 a3 74 d9 0c c3 3c 22 af 9b 8e ab 7f"
    k = "2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c"
    newc = matrixToLinearString(cypher(m, k))
    print("First use case:")
    print("cypher-->\n\t" + newc)
    print("decypher the result-->\n\t" + matrixToText(decypher(newc, k)))
    print("check the expected cypher text-->\n\t" + matrixToText(decypher(c, k)))

    # This case uses the phrase "Paranoia is our profession"
    # Chosen because it has more than 16 characters (32 characters)
    # the given cypher text is 110414d9e16367cea4269282504b7daeb27e32ee510c0f1a2b11ee9d48c13806
    # the given key is 2b7e151628aed2a6abf7158809cf4f3c

    m = "Paranoia is our profession"
    c1 = "11 04 14 d9 e1 63 67 ce a4 26 92 82 50 4b 7d ae"
    c2 = "b2 7e 32 ee 51 0c 0f 1a 2b 11 ee 9d 48 c1 38 06"
    k = "2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c"

    print("\n\nSecond use case:")
    print(
        "using block functions-->\n\t"
        + matrixToText(decypher(c1, k))
        + matrixToText(decypher(c2, k))
    )
    print("decryption using decryption function-->\n\t" + decryption(c1 + c2, k))
    print("check te cypher-->\n\t" + encryption(m, k))
