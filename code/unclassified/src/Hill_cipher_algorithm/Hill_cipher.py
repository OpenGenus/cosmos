
keyMatrix = [[0] * 3 for i in range(3)]
messageVector = [[0] for i in range(3)]
cipherMatrix = [[0] for i in range(3)] 

def __getKeyMatrix__(key):
    k = 0
    for i in range(3): 
        for j in range(3): 
            keyMatrix[i][j] = ord(key[k]) % 65
            k += 1

def __encrypt__(messageVector):
    for i in range(3): 
        for j in range(1): 
            cipherMatrix[i][j] = 0
            for x in range(3): 
                cipherMatrix[i][j] += (keyMatrix[i][x] * 
                                       messageVector[x][j]) 
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26
  
def __HillCipher__(message, key):
    __getKeyMatrix__(key)
    for i in range(3): 
        messageVector[i][0] = ord(message[i]) % 65
    __encrypt__(messageVector)
    CipherText = [] 
    for i in range(3): 
        CipherText.append(chr(cipherMatrix[i][0] + 65))
    print("Ciphertext: ", "".join(CipherText)) 

def __main__():

    message = "ACT"
    key = "GYBNQKURP"
    __HillCipher__(message, key)
  
if __name__ == "__main__": 
    __main__()
