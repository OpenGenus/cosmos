"""
Huffman encoding and decoding.

Given a string given from the user, it will calculate and print
the Huffman encoding

Cosmos octoberfest 2017
"""

from collections import Counter
from operator import itemgetter
from queue import PriorityQueue


class HuffmanTree(object):
    """A class representing a Huffman tree."""

    def __init__(self, left=None, right=None):
        """Initialize a HuffmanTree."""
        self.left = left
        self.right = right

    def __lt__(self, other):
        """Priorityqueue fails when compairing HuffmanTree with str."""
        return True

    def __gt__(self, other):
        """Priorityqueue fails when compairing HuffmanTree with str."""
        return True


def traverse_tree(node, prefix='', code={}):
    """Add prefixes for each letter."""
    if isinstance(node[1].left[1], HuffmanTree):
        traverse_tree(node[1].left, prefix+'0', code)
    else:
        code[node[1].left[1]] = prefix+'0'
    if isinstance(node[1].right[1], HuffmanTree):
        traverse_tree(node[1].right, prefix+'1', code)
    else:
        code[node[1].right[1]] = prefix+'1'

    return code


def count_frequence(word):
    """Return a list of tuples with the frequence of each letter orderded."""
    letters = Counter(word)
    return (sorted(letters.items(), key=itemgetter(1)))


def create_huffman_tree(word):
    """Create the huffman tree and return the encoding."""
    frequence = count_frequence(word)
    queue = PriorityQueue()

    for letter in frequence:
        queue.put((letter[1], letter[0]))

    while queue.qsize() > 1:
        left = queue.get()
        right = queue.get()
        node = HuffmanTree(left, right)
        queue.put((left[0] + right[0], node))

    # return queue.get()
    return traverse_tree(node=queue.get())


if __name__ == '__main__':
    word = input("Huffman encoding\nGive a string to encode: ").lower()

    codes = create_huffman_tree(word)

    for c in codes:
        print(c, codes[c])

    print('\n', word)
    for letter in word:
        print(codes[letter], end='')
    print('\n')
