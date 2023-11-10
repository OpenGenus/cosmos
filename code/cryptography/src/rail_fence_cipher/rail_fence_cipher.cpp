#include <iostream>
#include <cstring>
#include <string>
// Part of Cosmos by OpenGenus Foundation
// Rails fence cipher - Cryptography
using namespace std;

string Encryptor(string msg, int key)
{
    int msgLen = msg.size();
    bool direction = true;
    char enc[key][msgLen];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < msgLen; j++)
            enc[i][j] = '\n';

    for (int i = 0, row = 0, col = 0; i < msgLen; i++)
    {
        if (row == 0 || row == key - 1)
            direction = !direction;
        enc[row][col++] = msg[i];
        direction ? row-- : row++;
    }
    string cipher;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < msgLen; j++)
            if (enc[i][j] != '\n')
                cipher.push_back(enc[i][j]);

    return cipher;
}

string Decryptor(string cipher, int key)
{
    int cipLen = cipher.size();
    bool direction;
    char dec[key][cipLen];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipLen; j++)
            dec[i][j] = '\n';

    for (int i = 0, row = 0, col = 0; i < cipLen; i++)
    {
        if (row == 0)
            direction = false;
        else if (row == key - 1)
            direction = true;
        dec[row][col++] = '*';
        direction ? row-- : row++;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipLen; j++)
            if (dec[i][j] == '*' && index < cipLen)
                dec[i][j] = cipher[index++];

    string msg;
    for (int i = 0, row = 0, col = 0; i < cipLen; i++)
    {
        if (row == 0)
            direction = false;
        else if (row == key - 1)
            direction = true;
        if (dec[row][col] != '*')
            msg.push_back(dec[row][col++]);
        direction ? row-- : row++;
    }
    return msg;
}


int main()
{
    int key, choice;
    std::string cip, msg;
    cout << "1. Encrypt \n2. Decrypt \n>>";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Message\n>>";
        cin.ignore();
        std::getline(std::cin, msg);
        cout << "Enter Key\n>>";
        cin >> key;
        cout << "Encrypted Message\n>>" << Encryptor(msg, key);
    }
    else if (choice == 2)
    {
        cout << "Enter Encrypted Message\n>>";
        cin.ignore();
        std::getline(std::cin, cip);
        cout << "Enter Key\n>>";
        cin >> key;
        cout << "Original Message\n>>" << Decryptor(cip, key);
    }
    return 0;
}
