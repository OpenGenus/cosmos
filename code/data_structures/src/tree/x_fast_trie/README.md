# X-fast trie
Description
---
In computer science, an x-fast trie is a data structure for storing integers from a bounded domain. It supports exact and predecessor or successor queries in time O(log log M), using O(n log M) space, where n is the number of stored values and M is the maximum value in the domain.

API
---
- **add(key)**: Adds key to the Trie 
- **find(key)**: Checks if key is present in Trie 
- **successor(key)**: Returns the smallest existent element bigger than key
- **predecessor(key)**: Returns the biggest existent element smaller than key 
- **delete(key)**: Removes key from Trie

Average Time Complexity
---
- **add(key)**: O(log M) 
- **find(key)**: O(1) 
- **successor & predecessor**: O(log log M)
- **delete()**: O(log m)

Where M is the maximum value in the domain
 
