class node:
    def __init__(self, data=None):
        self.data = data
        if not data:
            self.weight = 0
        else:
            self.weight = len(data)
        self.left = None
        self.right = None
        self.parent = None

    def size(self):
        if self.data:
            return len(self.data)
        tmp = self.weight
        if self.right:
            return tmp + self.right.size()

    def addChild(self, side, node):
        node.parent = self
        nodeSize = node.size()

        if side == "left":
            self.left = node
            self.weight = nodeSize
        elif side == "right":
            self.right = node

        tmp = self
        while tmp.parent:
            if tmp.parent.left == tmp:
                tmp.parent.weight += nodeSize
            tmp = tmp.parent

    def removeChild(self, side):
        result = None
        if side == "left":
            result = self.left
            self.left = None
            self.weight = 0
        elif side == "right":
            result = self.right
            self.right = None
        nodeSize = result.size()
        tmp = self
        while tmp.parent:
            if tmp.parent.left == tmp:
                tmp.parent.weight -= nodeSize
            tmp = tmp.parent
        return result


class Rope:
    def __init__(self, text=None):
        if text:
            self.head = node(text)
        else:
            self.head = node()

    def Index(self, ind, node=None):
        if node is None:
            node = self.head
        if node.weight <= ind:
            return self.Index(ind - node.weight, node.right)
        elif node.left:
            return self.Index(ind, node.left)
        else:
            return node.data[ind]

    def concat(self, rope):
        result = Rope()
        result.head.addChild("left", self.head)
        result.head.addChild("right", rope.head)
        self.head = result.head

    def split(self, ind):
        result = Rope()
        tmp = self.head
        splitOff = list()
        # Lookup the node with the index
        while True:
            if tmp.weight <= ind and tmp.right:
                ind = ind - tmp.weight
                tmp = tmp.right
            elif tmp.left:
                tmp = tmp.left
            else:
                break
        # Split that node if the split point is in a node
        if ind != 0:
            node1 = node(tmp.data[:ind])
            node2 = node(tmp.data[ind:])
            nodeParent = node()
            nodeParent.addChildLeft(node1)
            nodeParent.addChildRight(node2)
            if tmp.parent.left == tmp:
                tmp = tmp.parent
                tmp.removeChild("left")
                tmp.addChild("left", nodeParent)
                tmp = nodeParent.right
            else:
                tmp = tmp.parent
                tmp.removeChild("right")
                tmp.addChild("right", nodeParent)
                tmp = nodeParent.right

        # Get everything else to the right of ind
        first = True
        while tmp.parent:
            if not tmp.parent.left:
                tmp = tmp.parent
            elif tmp.parent.left == tmp:
                if tmp.parent.right:
                    splitOff.append(tmp.parent.removeChild("right"))
                else:
                    tmp = tmp.parent
            elif tmp.parent.right == tmp and first:
                first = False
                tmp = tmp.parent
                splitOff.append(tmp.removeChild("right"))

        # Make a rope with the content right of ind to return
        rightRope = rope()
        while len(splitOff) > 0:
            rightRope.insert(0, splitOff.pop(0))
        return rightRope

    def insert(self, ind, rope):
        rightSide = self.split(ind)
        self.concat(rope)
        self.concat(rightSide)

    def delete(self, ind_left, ind_right):
        rightSide = self.split(ind_right)
        self.split(ind_left)
        self.concat(rightSide)


ROPE = Rope()
