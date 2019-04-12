/* Part of Cosmos by OpenGenus Foundation */

class Node {
  constructor() {
    this.keys = new Map();
    this.end = false;
  }
  setEnd() {
    this.end = true;
  }
  isEnd() {
    return this.end;
  }
}

class Trie {
  constructor() {
    this.root = new Node();
  }

  add(input, node = this.root) {
    if (input.length === 0) {
      node.setEnd();
      return;
    } else if (!node.keys.has(input[0])) {
      node.keys.set(input[0], new Node());
      return this.add(input.substr(1), node.keys.get(input[0]));
    } else {
      return this.add(input.substr(1), node.keys.get(input[0]));
    }
  }
  isWord(word) {
    let node = this.root;
    while (word.length > 1) {
      if (!node.keys.has(word[0])) {
        return false;
      } else {
        node = node.keys.get(word[0]);
        word = word.substr(1);
      }
    }
    return node.keys.has(word) && node.keys.get(word).isEnd() ? true : false;
  }
  print() {
    let words = [];
    const search = function(node, string) {
      if (node.keys.size !== 0) {
        for (let letter of node.keys.keys()) {
          search(node.keys.get(letter), string.concat(letter));
        }
        if (node.isEnd()) {
          words.push(string);
        }
      } else {
        string.length > 0 ? words.push(string) : undefined;
        return;
      }
    };
    search(this.root, "");
    return words.length > 0 ? words : mo;
  }
}

// Trie Examples

myTrie.add("cat");
myTrie.add("catch");
myTrie.add("dog");
myTrie.add("good");
myTrie.add("goof");
myTrie.add("jest");
myTrie.add("come");
myTrie.add("comedy");
myTrie.isWord("catc");
myTrie.isWord("jest");
myTrie.isWord("come");
myTrie.print();
