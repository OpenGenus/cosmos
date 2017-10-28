#include <array>
#include <assert.h>
#include <string>
#include <memory>

// only for test cases
#include <vector>
#include <iostream>

class Trie 
{
private:

  class Node 
  {
    static constexpr std::array<char, 63> alphabet = { '\0', '0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
      'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

public:

  void insert(std::string::const_iterator left, std::string::const_iterator right) 
  {
    auto& kid = kids[charToIndex(left == right ? '\0' : *left)];
    if (kid == nullptr) 
    {
      nKids++;
      kid = std::make_unique<Node>();
    }
    if (left != right) kid->insert(left+1, right);
  }

  int remove(std::string::const_iterator left, std::string::const_iterator right) 
  {
    int index = charToIndex(left == right ? '\0' : *left);
    if (kids[index] != nullptr && (left == right || 0 == kids[index]->remove(left+1, right))) 
    {
      nKids--;
      kids[index] = nullptr;
    }
    return nKids;
  }

  bool has(std::string::const_iterator left, std::string::const_iterator right) 
  {
    if (left == right) return kids[0] != nullptr;
    auto& kid = kids[charToIndex(*left)];
    if (kid == nullptr) return false;
    return kid->has(left+1, right);
  }

  void dump(std::string prefix) 
  {
    if (kids[0] != nullptr) std::cout << prefix << '\n';
    for (auto c : Node::alphabet) 
    {
      int index = charToIndex(c);
      if (kids[index] != nullptr) kids[index]->dump(prefix + c);
    }
  }

    int charToIndex(char c) 
    {
      int index = 0;
      if (c == '\0') return index;
      index++;
      if (c >= '0' && c <= '9') return index + c - '0';
      index += 1 + '9' - '0';
      if (c >= 'A' && c <= 'Z') return index + c - 'A';
      index += 1 + 'Z' - 'A';
      if (c >= 'a' && c <= 'z') return index + c - 'a';

      bool isInAlphabet = false;
      assert(isInAlphabet);
      return -1;
    }

    std::array<std::unique_ptr<Node>, alphabet.size()> kids;
    int nKids = 0;
  };

  Node root;

public:

  void insert(const std::string& key) 
  {
    root.insert(key.begin(), key.end());
  }

  void remove(const std::string& key) 
  {
    root.remove(key.begin(), key.end());
  }
  
  bool has(const std::string& key) 
  {
    return root.has(key.begin(), key.end());
  }

  void dump() 
  {
    root.dump(""); 
  }
};

constexpr std::array<char, 63> Trie::Node::alphabet;

int main() 
{
  std::vector<std::string> keys{ "cat", "case", "deaf", "deaf", "a", "an", "the", "" };

  Trie trie;
  for (auto& k : keys) trie.insert(k);

  trie.dump();

  assert(trie.has("cat"));

  trie.remove(keys[0]);

  assert(!trie.has("cat"));
  for (int i = 1; i < keys.size(); i++) assert(trie.has(keys[i]));

  return 0;
}
