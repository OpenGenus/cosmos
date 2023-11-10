class CircularBuffer:
    __array = []
    __size = 0
    __idx = 0

    def __init__(self, size):
        self.__array = [[] for _ in range(0, size)]
        self.__size = size

    def push(self, x):
        self.__array[self.__idx] = x
        self.__idx = (self.__idx + 1) % self.__size

    def get_ordered(self):
        retarr = []
        for i in range(0, self.__size):
            retarr += [self.__array[(i + self.__idx) % self.__size]]
        return retarr


buf = CircularBuffer(2)

buf.push(1)
buf.push(2)
buf.push(3)

for n in buf.get_ordered():
    print(n)
