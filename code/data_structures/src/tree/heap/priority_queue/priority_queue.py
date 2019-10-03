# Part of Cosmos by OpenGenus Foundation
import math


def default_compare_fn(p, q):
    diff = p - q
    if diff < 0:
        return -1
    elif diff > 0:
        return 1
    else:
        return 0


class PriorityQueue(object):
    def __init__(self, data=[], compare_fn=default_compare_fn):
        self.data = data
        self.compareFn = compare_fn

        self.init()

    def init(self):
        n = len(self.data)
        if n > 0:
            start = math.floor((n / 2) - 1)
            for i in range(int(start), 0, -1):
                self._down(i, n)

    def push(self, item):
        self.data.append(item)
        self._up(len(self.data) - 1)

    def pop(self):
        n = len(self.data)
        if n == 0:
            return None

        self.data[0], self.data[n - 1] = self.data[n - 1], self.data[0]
        self._down(0, n - 1)

        return self.data.pop()

    def _up(self, index):
        while index > 0:
            parent_index = int(math.floor((index - 1) / 2))
            parent_item = self.data[parent_index]
            current_item = self.data[index]

            if (
                parent_index == index
                or not self.compareFn(current_item, parent_item) < 0
            ):
                break
            self.data[index], self.data[parent_index] = (
                self.data[parent_index],
                self.data[index],
            )
            index = parent_index

    def _down(self, index, n):
        i = index
        while True:
            current_item = self.data[i]
            j1 = 2 * i + 1
            if j1 > n or j1 < 0:
                break
            j = j1
            j2 = j1 + 1
            if j2 < n and self.compareFn(self.data[j2], self.data[j1]) < 0:
                j = j2
            if self.compareFn(self.data[j], current_item) >= 0:
                break

            self.data[j], self.data[i] = self.data[i], self.data[j]
            i = j

        return i > index

    def top(self):
        return self.data[0]

    def empty(self):
        return len(self.data) == 0

    def __str__(self):
        return "PriorityQueue: {}".format(self.data)
        # return f'PriorityQueue: {self.data}'


if __name__ == "__main__":
    pq = PriorityQueue([45, 6, 4, 3, 2, 72, 34, 12, 456, 29, 312])
    pq.push(1)
    pq.pop()
    print(pq)
