#include <iostream>
#include <string>

std::string encryptXOR(const std::string& inputString, const std::string& key) {
    int keySize = key.size();
    std::string encryptedString = inputString;
    int size = inputString.size();
    for (int i = 0; i < size; i++) {
        encryptedString[i] = char(int(inputString[i]) ^ int(key[i%keySize]));
    }

    return encryptedString;
}

int main() {
    std::string key, inputString, encryptedString;

    std::cout << "Enter input: ";
    std::getline(std::cin, inputString);
    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    encryptedString = encryptXOR(inputString, key);
    std::cout << std::endl << encryptedString << std::endl; //Encryption using key 
    std::cout << encryptXOR(encryptedString, key) << std::endl; //Decryption using same key and function
    return 0;
}