// Part of Cosmos by OpenGenus Foundation
class TrieNode {
    char c; 
    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    boolean isEnd;
 
    public TrieNode() {}
    public TrieNode(char c){ this.c = c; }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode node = root;

        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (!node.children.containsKey(c)) {
                node.children.put(c,new TrieNode(c));
            }
            node = node.children.get(c); 
        }

        node.isEnd = true;
    }

    // Returns true if the word is in the trie.
    public boolean search(String word) {
        TrieNode node = searchNode(word);
        return (node == null) ? false : node.isEnd; 
    }

    // Returns true if there is any word in the trie that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode node = searchNode(prefix);
        return (node == null) ? false : true; 
    }

    public TrieNode searchNode(String s) {
        TrieNode node = root;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (node.children.containsKey(c)) {
                node = node.children.get(c);
            } else {
                return null;
            }
        }

        if (node == root) return null;

        return node;
    }
}
