# Trie
Description
---
In computer science, also called digital tree and sometimes radix tree or prefix tree 
(as they can be searched by prefixes), 
is a kind of search tree -- an ordered tree data structure that is used to store a 
dynamic set or associative array where the keys are usually strings.

Trie API
---
- insert(text): Insert a text node into the trie.
- contains(text) or search(text): Return true trie contains text otherwise return false
- delete(text): Insert a text node from the trie if exists.

Complexity
---
Insert and search costs O(key_length), 
however the memory requirements of Trie is 
O(ALPHABET_SIZE * key_length * N) 
where N is number of keys in Trie.
