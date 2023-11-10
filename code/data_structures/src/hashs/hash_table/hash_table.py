"""
Hash Table implementation in Python using linear probing. 
This code is based on the c/c++ implementation that I used to study hashing.
https://github.com/jwasham/practice-c/tree/master/hash_table  
"""

# Maximum number of elements.
MAX_SIZE = 8  # Small size helps in checking for collission response

# Key-Value pairs
class HashObject(object):
    def get_dummy_key():
        return "<Dummy>"

    def get_null_key():
        return "<Null>"

    def __init__(self):
        self.key_ = None
        self.value_ = None

    def set_key(self, key):
        self.key_ = key

    def set_value(self, value):
        self.value_ = value

    def get_key(self):
        return self.key_

    def get_value(self):
        return self.value_

    def set_as_dummy(self):
        self.set_key(HashObject.get_dummy_key())
        self.set_value("")


# HashTable class
class HashTable(object):

    # init method
    def __init__(self, n):
        self.size_ = n
        self.data_ = [HashObject() for _ in range(n)]

    # print method
    def __str__(self):
        output = ""
        for i in range(self.size_):
            if self.data_[i].get_key() != None:
                output += (
                    str(i)
                    + " => "
                    + str(
                        self.data_[i].get_key()
                        + " : "
                        + str(self.data_[i].get_value())
                        + "\n"
                    )
                )

        return output

    # hash method
    def s_hash(self, key):
        hash_val = 0
        for i in key:
            hash_val = (hash_val * 31) + ord(i)

        return hash_val % self.size_

    # insert a key-value pair into the table
    def add(self, key_val_pair):
        index = self.s_hash(key_val_pair.get_key())
        original_index = index
        found = False
        dummy_index = -1

        while self.data_[index].get_key() != None:
            if self.data_[index].get_key() == key_val_pair.get_key():
                found = True
                break

            if (
                dummy_index == -1
                and self.data_[index].get_key() == HashObject.get_dummy_key()
            ):
                dummy_index = index

            index = (index + 1) % self.size_
            if index == original_index:
                return

        if not found and dummy_index != -1:
            index = dummy_index

        self.data_[index].set_key(key_val_pair.get_key())
        self.data_[index].set_value(key_val_pair.get_value())

    # check whether the key eists in the table
    def exists(self, key):
        index = self.s_hash(key)
        original_index = index

        while self.data_[index].get_key() != None:
            if self.data_[index].get_key() == key:
                return True

            index = (index + 1) % self.size_
            if index == original_index:
                return False

        return False

    # Get value corresponding to the key
    def get(self, key):
        index = self.s_hash(key)
        original_index = index

        while self.data_[index].get_key() != None:
            if self.data_[index].get_key() == key:
                return self.data_[index].get_value()

            index = (index + 1) % self.size_
            if index == original_index:
                return HashObject.get_null_key()

        return HashObject.get_null_key()

    # Remove the entry with the given key
    def remove(self, key):
        index = self.s_hash(key)
        original_index = index

        while self.data_[index].get_key() != None:
            if self.data_[index].get_key() == key:
                self.data_[index].set_as_dummy()
                break

            index = (index + 1) % self.size_
            if index == original_index:
                break


if __name__ == "__main__":
    state = HashObject()
    table = HashTable(MAX_SIZE)

    state.set_key("Bihar")
    state.set_value("Patna")
    table.add(state)

    state.set_key("Jharkhand")
    state.set_value("Ranchi")
    table.add(state)

    state.set_key("Kerala")
    state.set_value("Thiruvanantpuram")
    table.add(state)

    state.set_key("WB")
    state.set_value("Kolkata")
    table.add(state)

    print(table)

    table.remove("Jharkhand")

    table.remove("WB")

    print(table)

    state.set_key("WB")
    state.set_value("Kolkata")
    table.add(state)

    print(table)
