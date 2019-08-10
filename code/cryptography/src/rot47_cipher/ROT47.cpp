#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cctype>

std::map<char, char> characterMap;

std::map<char, char> start();
std::map<char, char> create();
std::map<char, char> read();
bool exists(const std::string& filename);
std::string convert(std::string String);

int main() {
    characterMap = start();
    std::string inputString, encryptedString;

    std::getline(std::cin, inputString);
    encryptedString = convert(inputString);
    std::cout << encryptedString << std::endl;
}

std::map<char, char> start() {
    if (exists("CaesarTable.dat")) {
        return read();
    }

    else {
        return create();
    }
}

bool exists(const std::string& filename) {
    std::ifstream file(filename.data());
    return file.good();
}

std::map<char, char> create() {
    std::fstream file;
    std::map<char, char> CaesarTable;
    int characterMap = 33;

    file.open("CaesarTable.dat", std::fstream::binary | std::fstream::trunc | std::fstream::out);
    for (int i = 0; i < 47; i++, characterMap++) {
        CaesarTable[char(characterMap)] = char(characterMap+47);
    }

    for (int i = 0; i < 47; i++, characterMap++) {
        CaesarTable[char(characterMap)] = char(characterMap-47);
    }

    for (std::pair<char, char> entry : CaesarTable) {
        file << entry.first;
        file << entry.second;
    }

    file.close();
    return CaesarTable;
}

std::map<char, char> read() {
    std::fstream file;
    std::map<char, char> CaesarTable;
    char key, value;

    file.open("CaesarTable.dat", std::fstream::binary | std::fstream::in);
    for (int i = 0; i < 94; i++) {
        file >> key;
        file >> value;
        CaesarTable[key] = value;
    }

    file.close();
    return CaesarTable;
}

std::string convert(std::string String) {
    std::string rtrn = String;
    for (int i = 0; i < String.length(); i++) {
        rtrn[i] = characterMap[String[i]];
    }   

    return rtrn;
}