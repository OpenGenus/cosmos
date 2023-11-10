package main

import (
	"fmt"
	"hash"
	"hash/fnv"

	"github.com/spaolacci/murmur3"
)

// Minimal interface that the Bloom filter must implement
type Interface interface {
	Add(item []byte)        // Adds the item into the Set
	Check(item []byte) bool // Performs probabilist test if the item exists in the set or not.
}

// BloomFilter probabilistic data structure definition
type BloomFilter struct {
	bitset  []bool        // The bloom-filter bitset
	k       uint          // Number of hash values
	n       uint          // Number of elements in the filter
	m       uint          // Size of the bloom filter
	hashfns []hash.Hash64 // The hash functions
}

// Returns a new BloomFilter object,
func New(size, numHashValues uint) *BloomFilter {
	return &BloomFilter{
		bitset:  make([]bool, size),
		k:       numHashValues,
		m:       size,
		n:       uint(0),
		hashfns: []hash.Hash64{murmur3.New64(), fnv.New64(), fnv.New64a()},
	}
}

// Adds the item into the bloom filter set by hashing in over the hash functions
func (bf *BloomFilter) Add(item []byte) {
	hashes := bf.hashValues(item)
	i := uint(0)

	for {
		if i >= bf.k {
			break
		}

		position := uint(hashes[i]) % bf.m
		bf.bitset[uint(position)] = true

		i += 1
	}

	bf.n += 1
}

// Test if the item into the bloom filter is set by hashing in over the hash functions
func (bf *BloomFilter) Check(item []byte) (exists bool) {
	hashes := bf.hashValues(item)
	i := uint(0)
	exists = true

	for {
		if i >= bf.k {
			break
		}

		position := uint(hashes[i]) % bf.m
		if !bf.bitset[uint(position)] {
			exists = false
			break
		}

		i += 1
	}

	return
}

// Calculates all the hash values by hashing in over the hash functions
func (bf *BloomFilter) hashValues(item []byte) []uint64 {
	var result []uint64

	for _, hashFunc := range bf.hashfns {
		hashFunc.Write(item)
		result = append(result, hashFunc.Sum64())
		hashFunc.Reset()
	}

	return result
}

func main() {
	bf := New(1024, 3)

	bf.Add([]byte("hello"))
	bf.Add([]byte("world"))
	bf.Add([]byte("1234"))
	bf.Add([]byte("hello-world"))

	fmt.Printf("hello in bloom filter = %t \n", bf.Check([]byte("hello")))
	fmt.Printf("world in bloom filter = %t \n", bf.Check([]byte("world")))
	fmt.Printf("helloworld in bloom filter = %t \n", bf.Check([]byte("helloworld")))
	fmt.Printf("1 in bloom filter = %t \n", bf.Check([]byte("1")))
	fmt.Printf("2 in bloom filter = %t \n", bf.Check([]byte("2")))
	fmt.Printf("3 in bloom filter = %t \n", bf.Check([]byte("3")))

}
