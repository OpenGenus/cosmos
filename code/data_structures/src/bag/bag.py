class Bag:
    """
  Create a collection to add items and iterate over it.
  There is no method to remove items.
  """

    # Initialize a bag as a list
    def __init__(self):
        self.bag = []

    # Return the size of the bag
    def __len__(self):
        return len(self.bag)

    # Test if a item is in the bag
    def __contains__(self, item):
        return item in self.bag

    # Return a item in the bag by its index
    def __getitem__(self, key):
        return self.bag[key]

    # Add item to the bag
    def add(self, item):
        self.bag.append(item)

    # Return the bag showing all its items
    def items(self):
        return self.bag

    # Test if the bag is empty
    def isEmpty(self):
        return len(self.bag) == 0


## Tests ##
bag1 = Bag()

print(len(bag1))

bag1.add("test")
bag1.add("shamps")

print(len(bag1))

print("bag1 is empty?", bag1.isEmpty())

print("test is in bag1", "test" in bag1)
print("shampz is in bag1", "shampz" in bag1)

for item in bag1:
    print(item)

print(bag1.items())
