# An efficient information reTRIEval data structure


class TrieNode(object):
    def __init__(self):
        self.children = {}

    def __repr__(self):
        return str(self.children)


def insert(root_node, word):
    n = root_node
    for character in word:
        t = n.children.get(character)
        if not t:
            t = TrieNode()
            n.children[character] = t
        n = t


def search(root_node, search_string):
    node = root_node
    for character in search_string:
        c = node.children.get(character)
        if not c:
            return False
        node = c
    return True


root = TrieNode()

insert(root, "abc")
insert(root, "pqrs")

print(search(root, "abc"))  # will print True
print(search(root, "xyz"))  # will print False
