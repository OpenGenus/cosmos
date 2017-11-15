// Part of Cosmos by OpenGenus Foundation
/*
 * Public API:
 * get(): to find a data
 * put(): to insert a data
 * remove(): to remove a data
 * size: to get number of nodes
 * height: to get height of splay tree
 */

class SplayTree<KeyT : Comparable<KeyT>, ValueT>() {
    private inner class Node(val key: KeyT, var value: ValueT? = null) {
        var left: Node? = null
        var right: Node? = null
    }
    private var root : Node? = null
    var size: Int = 0
        private set
    val height
        get() = height(root)

    private fun height(x : Node?) : Int {
        var result = -1
        if (x != null) {
            result = 1 + maxOf(height(x.left), height(x.right))
        }
        return result
    }
    private fun rotateLeft(x : Node?) : Node? {
        val y : Node? = x?.right
        x?.right = y?.left
        y?.left = x
        return y
    }

    private fun rotateRight(x : Node?) : Node? {
        val y : Node? = x?.left
        x?.left = y?.right
        y?.right = x
        return y
    }

    private fun splay(h : Node?, key : KeyT) : Node? {
        var root : Node = h ?: return null

        if (key < root.key) {
            val left : Node = root.left ?: return root

            if (key < left.key) {
                left.left = splay(left.left, key)
                root = rotateRight(root) ?: return null

            } else if (key > left.key) {
                left.right = splay(left.right, key)
                if (left.right != null) {
                    root.left = rotateLeft(left)
                }
            }

            return if (root.left == null) root else rotateRight(root)

        } else if (key > root.key) {
            val right : Node = root.right ?: return root

            if (key < right.key) {
                right.left = splay(right.left, key)
                if (right.left != null) {
                    root.right = rotateRight(right)
                }

            } else if (key > right.key) {
                right.right = splay(right.right, key)
                root = rotateLeft(root) ?: return null
            }

            return if (root.right == null) root else rotateLeft(root)

        } else {
            return root
        }
    }

    fun get(key: KeyT) : ValueT? {
        root = splay(root, key)
        if (root?.key == key) {
            return root?.value
        }
        return null
    }

    fun put(key: KeyT, value: ValueT) {
        if (root == null) {
            root = Node(key, value)
            size++
            return
        }

        root = splay(root, key)
        val rootKey = root?.key ?: return
        if (key < rootKey) {
            val n = Node(key, value)
            n.left = root?.left
            n.right = root
            root?.left = null
            root = n
            size++

        } else if (key > rootKey) {
            val n = Node(key, value)
            n.right = root?.right
            n.left = root
            root?.right = null
            root = n
            size++

        } else {
            root?.value = value
        }
    }

    fun remove(key: KeyT) {
        root = splay(root, key)

        val rootKey = root?.key ?: return
        if (key == rootKey) {
            size--
            if (root?.left == null) {
                root = root?.right
            } else {
                val x = root?.right
                root = root?.left
                splay(root, key)
                root?.right = x
            }
        }
    }
}

fun main(args : Array<String>) {
    val splay_tree = SplayTree<String, Int>()
    splay_tree.put("OpenGenus", 1)
    splay_tree.put("Cosmos", 2)
    splay_tree.put("Vidsum", 3)
    splay_tree.put("Splay", 4)

    println("Size Before: " + splay_tree.size)
    println("Height Before: " + splay_tree.height)
    splay_tree.remove("Splay")
    println("Size After: " + splay_tree.size)
    println("Height After: " + splay_tree.height)
    println(splay_tree.get("OpenGenus"))
}