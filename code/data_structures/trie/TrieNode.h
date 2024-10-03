#include <unordered_map>
using namespace std;

class TrieNode {
	public:
	char data;
	bool isTerminal;
	unordered_map<char, TrieNode*> children;
	TrieNode(char data) {
		this->data = data;
		isTerminal = false;
	}
}
