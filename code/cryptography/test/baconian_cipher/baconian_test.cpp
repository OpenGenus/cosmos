#include <assert.h>
#include <iostream>
#include "./../../src/baconian_cipher/baconian.cpp"

// Part of Cosmos by OpenGenus Foundation
int main()
{
    std::string baconian_string = "AABBBAABAAABABBABABBABBBA BABBAABBBABAAABABABBAAABB"; 
    std::string english_string = "HELLO WORLD";
    std::map<char, std::string> generatedCipher = createBaconianMap();
    // Testing with typed out map
    assert(encrypt(cipher, english_string) == baconian_string);
    assert(decrypt(cipher, baconian_string) == english_string);
    // Testing with map generated from createBaconianMap() function
    assert(encrypt(generatedCipher, english_string) == baconian_string);
    assert(decrypt(generatedCipher, baconian_string) == english_string);
    std::cout << "Testing Complete\n";
}
