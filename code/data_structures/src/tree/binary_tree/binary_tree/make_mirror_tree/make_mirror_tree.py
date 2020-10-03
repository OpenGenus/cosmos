# Part of Cosmos by OpenGenus Foundation


class Node(object):
    def __init__(self, data=-1, path="", left=None, right=None):
        self.data = data
        self.path = path
        self.left = left
        self.right = right


def inorder(root):
    if root:
        print(root.data, " path", root.path, end=" \n")

        inorder(root.left)
        inorder(root.right)


def insertbydata(root, d, char, newd):
    global x
    if root:
        if root.data == d:
            x = root
            if char == "L":

                x.left = Node(newd, x.path + "1")
                # x=x.left

            else:
                x.right = Node(newd, x.path + "0")
                # x=x.right
                # print(x.data)
        insertbydata(root.left, d, char, newd)
        insertbydata(root.right, d, char, newd)


def searchbypath(root, pat):
    global x
    if root:

        # print(root.path)
        if root.path == pat:
            x = root
            # print( x.data)
        searchbypath(root.left, pat)

        searchbypath(root.right, pat)
    if x == None:
        return -1
    return x.data


def mirror_path(st):
    k = ""
    for i in st:
        if i == "0":
            k += "1"
        else:
            k += "0"
    return k


def searchbydata(root, d):
    global x
    if root:
        if root.data == d:
            x = root
        searchbydata(root.left, d)

        searchbydata(root.right, d)
    if x != None:

        return x
    return -1


head = Node(1)
t = [int(i) for i in input().split()]
for i in range(t[0] - 1):
    li = [j for j in input().split()]
    insertbydata(head, int(li[0]), li[2], int(li[1]))
# inorder(head)
for i in range(t[1]):
    inputd = int(input())
    mirrorreflecttionofinputd = searchbypath(
        head, (mirror_path(searchbydata(head, inputd).path))
    )
    if inputd != head.data:

        if inputd == mirrorreflecttionofinputd:
            print(-1)
        else:
            print(mirrorreflecttionofinputd)
    else:

        print(head.data)

"""
input should be like this
10 8
1 2 R
1 3 L
2 4 R
2 5 L
3 6 R
3 7 L
5 8 R
5 9 L
7 10 R
2
5
3
6
1
10
9
4

First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi printing the mirror node if it exists else printing -1.
"""
