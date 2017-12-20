Bloom Filter
---
A space-efficient probabilistic data structure that is used to test whether an element is a member of 
a set. False positive matches are possible, but false negatives are not; i.e. a query returns either "possibly in set" 
or "definitely not in set". Elements can be added to the set, but not removed.

## Api

* `Add(item)`: Adds the item into the set
* `Check(item) bool`: Check if the item possibly exists into the set

## Complexity

**Time**

If we are using a bloom filter with  bits and  hash function, 
insertion and search will both take  time. 
In both cases, we just need to run the input through all of 
the hash functions. Then we just check the output bits.

|  Operation | Complexity  |
|---|---|
|  insertion |  O(k)  |
|  search |  O(k)  |

**Space**
The space of the actual data structure (what holds the data).

|  Complexity |
|---|
|  O(m) |

Where `m` is the size of the slice.