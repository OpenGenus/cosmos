import sys
import getopt
import hashlib

ROUNDS = 8
BLOCKSIZE = 8
BLOCKSIZE_BITS = BLOCKSIZE * 8
SECRET = "my_secret"


key_256 = lambda x: hashlib.sha256((x + SECRET).encode('utf-8')).hexdigest() #to normalise string into 256 bits
bintoint = lambda x: int(x, 2)
xor = lambda x, y: ''.join(chr(ord(a) ^ ord(b)) for a, b in zip(x, y)) #string xor, byte wise
stobin = lambda x: ''.join( '{:08b}'.format(ord(c)) for c in x ) #converts ascii of each char into 8bit string
itobin = lambda x: bin(x) #int to bin
bintostr = lambda b: ''.join(chr(int(b[i: i + 8], 2)) for i in range(0, len(b), 8)) #binary number to string

def main(argv):
    decrypt = False
    encrypt = False

    try:
        opts, args = getopt.getopt(argv, "det:k:o:")
    except:
        sys.exit(1)

    if len(sys.argv[1:]) < 6:
        print ('Usage: ./{} -[d|e] -t <input_textfile> -k <key> -o <outputfile>'.format(__file__))
        sys.exit(2)
    for opt, arg in opts:
        if opt == "-d":
            decrypt = True
        elif opt == "-e":
            encrypt = True
        elif opt == "-t":
            filename = str(arg)
        elif opt == "-k":
            key = str(arg)
        elif opt == "-o":
            outfilename = str(arg)
        else:
            exit()


    with open(filename, "r") as f:
        input_text = f.read().strip()

    if (encrypt):
        output = encryptMessage(key, input_text)
    elif (decrypt):
        output = decryptCipher(key, input_text)

    with open(outfilename, 'w') as fw:
        fw.write(output)


    print(output)


def encryptMessage(key, message):
    ciphertext = ""
    n = BLOCKSIZE  

    
    message = [message[i: i + n] for i in range(0, len(message), n)]
    lengthOfLastBlock = len(message[-1])
    message[-1] += (" " * (n - lengthOfLastBlock))

    key = key_256(key)
    for block in message:
        L = [""] * (ROUNDS + 1)
        R = [""] * (ROUNDS + 1)
        L[0] = block[0:BLOCKSIZE//2]
        R[0] = block[BLOCKSIZE//2:BLOCKSIZE]

        for i in range(1, ROUNDS+1):
            L[i] = R[i - 1]
            R[i] = xor(L[i - 1], scramble(R[i - 1], i, key))

        ciphertext += (L[ROUNDS] + R[ROUNDS])
    return ciphertext

def decryptCipher(key, ciphertext):
    message = ""
    n = BLOCKSIZE 

    ciphertext = [ciphertext[i: i + n] for i in range(0, len(ciphertext), n)]

    lengthOfLastBlock = len(ciphertext[-1])

    ciphertext[-1] += (" " * (n - lengthOfLastBlock))
    key = key_256(key)
    for block in ciphertext:
        #print ("Block: " + block)
        L = [""] * (ROUNDS + 1)
        R = [""] * (ROUNDS + 1)
        L[ROUNDS] = block[0:BLOCKSIZE//2]
        R[ROUNDS] = block[BLOCKSIZE//2:BLOCKSIZE]
        for i in range(ROUNDS, 0, -1):
            R[i-1] = L[i]
            L[i-1] = xor(R[i], scramble(L[i], i, key))


        message += (L[0] + R[0])
    return message




def scramble(x, i, k):
    """
    Design choice:
        All functions implemented here are such that reversing this for 
        the processing of the cipher text, reversing L and R terms would result in the
        same output
    """
    k = stobin(k) # converts key to bit string
    x = stobin(str(x)) #L[i] also gets converted

    k = bintoint(k) #the bin gets converted to an int
    x = bintoint(x) 

    res = pow((x * k), i) #raises
    res = itobin(res) #binary output

    return bintostr(res) #string for coherency




if __name__ == "__main__":
    main(sys.argv[1:])