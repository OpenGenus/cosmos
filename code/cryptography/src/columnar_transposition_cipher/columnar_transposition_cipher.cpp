// CPP program for
// Columnar Transposition Cipher
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<int, int> keyMap;

void setPermutationOrder(string key)
{
    // Add the permutation
    for (size_t i = 0; i < key.length(); i++)
        keyMap[key[i]] = i;
}

// Encryption code for cipher
string encrypt(string object, string key)
{
    int row, col, j;
    string cipher = "";

    /* calculate column of the matrix*/
    col = key.length();

    /* calculate Maximum row of the matrix*/
    row = object.length() / col;

    if (object.length() % col)
        row += 1;

    char matrix[row][col];

    for (int i = 0, k = 0; i < row; i++)
        for (int j = 0; j < col;)
        {
            if (object[k] == '\0')
            {
                /* Adding the padding character '_' */
                matrix[i][j] = '_';
                j++;
            }

            if (isalpha(object[k]) || object[k] == ' ')
            {
                /* Adding only space and alphabet into matrix*/
                matrix[i][j] = object[k];
                j++;
            }
            k++;
        }

    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
    {
        j = ii->second;

        // getting cipher text from matrix column wise using permuted key
        for (int i = 0; i < row; i++)
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
                cipher += matrix[i][j];
    }

    return cipher;
}

// Decryption code for cipher
string decrypt(string cipher, string key)
{
    /* calculate row and column for cipher Matrix */
    int col = key.length();

    int row = cipher.length() / col;
    char cipherMat[row][col];

    /* add character into matrix column wise */
    for (int j = 0, k = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipher[k++];

    /* update the order of key for decryption */
    int index = 0;
    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
        ii->second = index++;

    /* Arrange the matrix column wise according
     * to permutation order by adding into new matrix */
    char decCipher[row][col];
    int k = 0;
    for (int l = 0, j; key[l] != '\0'; k++)
    {
        j = keyMap[key[l++]];
        for (int i = 0; i < row; i++)
            decCipher[i][k] = cipherMat[i][j];
    }

    /* getting Message using matrix */
    string msg = "";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (decCipher[i][j] != '_')
                msg += decCipher[i][j];

    return msg;
}

// Driver Program for columnar transposition
int main()
{
    /* message */
    string msg = "defend the east wall of the castle";
    string key = "GERMAN";
    setPermutationOrder(key);


    string cipher = encrypt(msg, key);
    cout << "Encrypted Message: " << cipher << endl;


    cout << "Decrypted Message: " << decrypt(cipher, key) << endl;

    return 0;
}
