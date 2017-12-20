# Part of Cosmos by OpenGenus Foundation

# A Bloom filter implementation in python


class bloomFilter:
    def __init__(self, size=1000, hashFunctions=None):
        """ Construct a bloom filter with size bits(default: 1000) and the associated hashFunctions.
            Default hash function is i.e. hash(e)%size.
        """
        self.bits = 0
        self.M = size
        if hashFunctions is None:
            self.k = 1
            self.hashFunctions = [lambda e, size: hash(e) % size]
        else:
            self.k = len(hashFunctions)
            self.hashFunctions = hashFunctions

    def add(self, value):
        """ Insert value in bloom filter"""
        for hf in self.hashFunctions:
            self.bits |= 1 << hf(value, self.M)

    def __contains__(self, value):
        """
        Determine whether a value is present. A false positive might be returned even if the element is
        not present. However, a false negative will never be returned.
        """
        for hf in self.hashFunctions:
            if self.bits & 1 << hf(value, self.M) == 0:
                return False
        return True


# Example of usage
bf = bloomFilter()

bf.add("Francis")
bf.add("Claire")
bf.add("Underwood")

if "Francis" in bf:
    print("Francis is in BloomFilter :)")

if "Zoe" not in bf:
    print("Zoe is not in BloomFilter :(")
