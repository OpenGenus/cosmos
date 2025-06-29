# Trie (Prefix Tree)

A **Trie** is a tree-based data structure that stores a dynamic set or associative array where the keys are usually strings. It is efficient for **searching, inserting, and prefix queries**.

## Operations

- **Insert** a string into the Trie.
- **Search** to check if a string is present.
- **StartsWith** to check if a given prefix exists.

## Time Complexity

| Operation   | Complexity |
|-------------|------------|
| Insert      | O(L)       |
| Search      | O(L)       |
| StartsWith  | O(L)       |

Where `L` is the length of the string.

## Sample Usage

```cpp
Trie trie;
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true