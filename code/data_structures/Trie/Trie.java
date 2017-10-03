class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isEnd;

    public TrieNode() {}
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
            if (node.children[c - 'a'] == null) {
                node.children[c - 'a'] = new TrieNode();
            }
            node = node.children[c - 'a'];
        }

        node.isEnd = true;
    }

    // Returns true if the word is in the trie.
    public boolean search(String word) {
        TrieNode node = searchNode(word);

        if (node == null) {
            return false;
        } else {
            return node.isEnd;
        }
    }

    // Returns true if there is any word in the trie that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode node = searchNode(prefix);

        if (node == null) {
            return false;
        } else {
            return true;
        }
    }

    public TrieNode searchNode(String s) {
        TrieNode node = root;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (node.children[c - 'a'] != null) {
                node = node.children[c - 'a'];
            } else {
                return null;
            }
        }

        if (node == root) return null;

        return node;
    }
}
