#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;


struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};


struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};


HuffmanNode* buildHuffmanTree(const string& message) {
    map<char, int> frequencyMap;

    
    for (char ch : message) {
        if (ch != ' ') {
            frequencyMap[ch]++;
        }
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    
    for (const auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }


    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}


void generateHuffmanCodes(HuffmanNode* root, const string& code, map<char, string>& huffmanCodes) {
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->character] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}


string encodeMessage(const string& message, const map<char, string>& huffmanCodes) {
    string encodedMessage = "";

    for (char ch : message) {
        if (ch != ' ') {
            encodedMessage += huffmanCodes.at(ch);
        }
    }

    return encodedMessage;
}

string decodeMessage(const string& encodedMessage, const HuffmanNode* root) {
    string decodedMessage = "";
    const HuffmanNode* currentNode = root;

    for (char bit : encodedMessage) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedMessage += currentNode->character;
            currentNode = root;
        }
    }

    return decodedMessage;
}

int main() {
    string message;
    cout << "Enter a message to encode using Huffman coding: ";
    getline(cin, message);

    HuffmanNode* huffmanTreeRoot = buildHuffmanTree(message);

    map<char, string> huffmanCodes;
    generateHuffmanCodes(huffmanTreeRoot, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string encodedMessage = encodeMessage(message, huffmanCodes);
    cout << "Encoded Message: " << encodedMessage << endl;

    string decodedMessage = decodeMessage(encodedMessage, huffmanTreeRoot);
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
