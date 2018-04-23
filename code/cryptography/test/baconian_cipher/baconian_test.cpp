#include <assert.h>
#include <iostream>
#include "./../../src/baconian_cipher/baconian.cpp"

// Part of Cosmos by OpenGenus Foundation
int main()
{
    std::string baconianString = "AABBBAABAAABABBABABBABBBA BABBAABBBABAAABABABBAAABB";
    std::string englishString = "HELLO WORLD";
    std::map<char, std::string> generatedCipher = createBaconianMap();
    assert(encrypt(generatedCipher, englishString) == baconianString);
    assert(decrypt(generatedCipher, baconianString) == englishString);
    std::cout << "Testing Complete\n";
}
