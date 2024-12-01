#include "TrieNode.h"

class Trie {
	TrieNode* root;
	int numWords;
	public:
	Trie() {
		numWords = 0;
		root = new TrieNode('\0');
	}

	private:
	static bool insertWord(char* word, TrieNode* node) {
		if (word[0] == '\0') {
			if (node->isTerminal) {
				return false;
			}
			node->isTerminal = true;
			return true;
		}
		TrieNode* child;
		if (node->children.count(word[0]) > 0) {
			child = node->children[word[0]];
		} else {
			child = new TrieNode(word[0]);
			node->children[word[0]] = child;
		}
		return insertWord(word + 1, child);
	}

	static bool deleteWord(char* word, TrieNode* node) {
		if (word[0] == '\0') {
			if (!node->isTerminal) {
				return false;
			}
			node->isTerminal = false;
			return true;
		}
		TrieNode* child;
		if (node->children.count(word[0]) > 0) {
			child = node->children[word[0]];
		} else {
			return false;
		}
		bool output = deleteWord(word + 1, child);
		if(!child->isTerminal && child->children.size() == 0) {
			delete child;
			node->children.erase(word[0]);
		}
		return output;
	}

	public:
	void deleteWord(char* word) {
		if (deleteWord(word, root)) {
			numWords--;
		}
	}

	void insertWord(char* word) {
		if (insertWord(word, root)) {
			numWords++;
		}
	}
	
	bool hasWord(char* word) {
		TrieNode* currentNode = root;
		int i = 0;
		while (word[i] != '\0') {
			TrieNode* child;
			if (node->children.count(word[i]) > 0) {
				child = node->children[word[i]];
			} else {
				return false;
			}
			currentNode = child;
			i++;
		}
		return currentNode->isTerminal;
	}
};
