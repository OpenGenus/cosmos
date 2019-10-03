# Part of Cosmos by OpenGenus Foundation.

# Make a new Queue class with list.
class Queue:
    def __init__(self, size_max):
        self.__max = size_max
        self.__data = []

    # Adds an item to the end of the queue.
    def enqueue(self, x):
        if len(self.__data) == self.__max:
            print("Queue is full")
        else:
            self.__data.append(x)

    # Removes the first item of the queue without returning it.
    def dequeue(self):
        if len(self.__data) == 0:
            print("Queue is empty")
        else:
            self.__data.pop(0)

    # Returns the first item of the queue.
    def front(self):
        if len(self.__data) == 0:
            print("Queue is empty")
            return False
        return self.__data[0]

    # Returns the size of the queue, not the maximum size.
    def size(self):
        return len(self.__data)

    # Returns the maximum size that the queue can hold
    def capacity(selfs):
        return len(self.__max)


# Return all items from queue in list.
def get(queue):
    lst = []
    while queue.size() > 0:
        lst.append(queue.front())
        queue.dequeue()

    # I don't the items to be removed, so I add them again.
    # But if you want, you can remove/comment it out.
    for item in lst:
        queue.enqueue(item)

    return lst


# Return reversed queue.
def reverse(queue):
    # Reverse the return value, which is in list type, from get() method
    temp = get(queue)[::-1]

    # Add all items from reversed list to rev
    rev = Queue(len(temp))
    for item in temp:
        rev.enqueue(item)
    return rev


# Print formatted output.
def display(queue):
    # First, it will show you the original queue.
    print("Original queue: {}".format(get(queue)))
    # Then, it will show the reversed one.
    print("Reversed queue: {}\n".format(get(reverse(queue))))


# Add all item in list to queue.
def listToQueue(lst):
    queue = Queue(len(lst))
    for item in lst:
        queue.enqueue(item)
    return queue


# Examples.
int_arr = [1, 3, 2, 5, 4]
string_arr = ["alpha", "beta", "gamma", "echo", "delta"]
double_arr = [1.1, 3.2, 1.2, 5.4, 4.3]
mix_arr = [1, "alpha", 2.1, True, "D"]

# Collect all example in one list.
examples = [int_arr, string_arr, double_arr, mix_arr]

# First, each example will be transfered from list to queue,
# then it will be printed as output.
for item in examples:
    display(listToQueue(item))
