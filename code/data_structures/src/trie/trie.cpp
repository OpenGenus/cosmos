#include <iostream>
#include <string>
#include <array>

class TrieNode {
public:
    std::array<TrieNode*, 26> children;
    bool isEnd;

    TrieNode() : isEnd{false} {
        children.fill(nullptr);
    }
};

class Trie {
public:
    Trie() : root_{new TrieNode()} { }

    void insert(const std::string& word);
    bool search(const std::string& word);
    bool startsWith(const std::string& prefix);

private:
    TrieNode* root_;
};

void Trie::insert(const std::string& word) {
    TrieNode* node = root_;
    for (char ch : word) {
        int i = ch - 'a';
        if (!node->children[i]) {
            node->children[i] = new TrieNode();
        }
        node = node->children[i];
    }
    node->isEnd = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* node = root_;
    for (char ch : word) {
        int i = ch - 'a';
        if (!node->children[i]) {
            return false;
        }
        node = node->children[i];
    }
    return node->isEnd;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* node = root_;
    for (char ch : prefix) {
        int i = ch - 'a';
        if (!node->children[i]) {
            return false;
        }
        node = node->children[i];
    }
    return true;
}

int main() {
    Trie trie;
    trie.insert("apple");
    std::cout << "Search 'apple': " << trie.search("apple") << "\n";
    std::cout << "Search 'app': " << trie.search("app") << "\n";
    std::cout << "StartsWith 'app': " << trie.startsWith("app") << "\n";
    trie.insert("app");
    std::cout << "Search 'app': " << trie.search("app") << "\n";

    return 0;
}