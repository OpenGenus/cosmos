/**
 * X-fast trie is a data structure for storing integers from a bounded domain
 * More info about the structure and complexity here: https://en.wikipedia.org/wiki/X-fast_trie
 */

class XFastTrie(domain: Long) {

    private class Node(var left: Node? = null, var right: Node? = null,
                       var leftAdiac: Node? = null, var rightAdiac: Node? = null) {
        var descendant: Node? = null
        var key: Long? = null
        fun isLeaf(): Boolean = (left == null && right == null)
    }

    private val root = Node()
    private val levels: Int = java.lang.Long.numberOfLeadingZeros(0) - java.lang.Long.numberOfLeadingZeros(domain) + 1
    private var hashes: Array<MutableMap<Long, Node>> = Array(this.levels, {HashMap<Long, Node>()})

    fun add(key: Long) {
        val pred = nodePredecessor(key)
        val succ = nodeSuccessor(key)
        val newNode = Node(leftAdiac = pred, rightAdiac = succ)

        pred?.rightAdiac = newNode
        succ?.leftAdiac = newNode

        newNode.key = key
        add(key, leaf = newNode)
    }

    private fun add(key: Long, leaf: Node) {
        var currentNode = root
        for (level in this.levels-2 downTo 1) {
            if (((key shr level) and 1L) == 1L) {
                if (currentNode.right == null) {
                    currentNode.right = Node()
                    hashes[level].put(key shr level, currentNode.right!!)
                }
                currentNode = currentNode.right!!
            }
            else {
                if (currentNode.left == null) {
                    currentNode.left = Node()
                    hashes[level].put(key shr level, currentNode.left!!)
                }
                currentNode = currentNode.left!!
            }
        }
        if (key and 1L == 1L)
            currentNode.right = leaf
        else
            currentNode.left = leaf
        hashes[0].put(key, leaf)
        fixDescendants(root, key, this.levels-2)
    }

    private fun fixDescendants(currentNode: Node, key: Long, level: Int) : Pair<Node?, Node?>{
        if (level == -1)
            return Pair(currentNode, currentNode)
        val nextNode = if (((key shr level) and 1L) == 1L) currentNode.right else currentNode.left
        var (minNode, maxNode) = fixDescendants(nextNode!!, key, level-1)
        if (nextNode == currentNode.right && currentNode.left == null && minNode != null)
            currentNode.descendant = minNode
        else if (nextNode == currentNode.right && currentNode.left != null)
            minNode = null
        else if (nextNode == currentNode.left && currentNode.right == null && maxNode != null)
            currentNode.descendant = maxNode
        else if (nextNode == currentNode.left && currentNode.right != null)
            maxNode = null

        return Pair(minNode, maxNode)
    }

    fun find(key: Long) = hashes[0].contains(key)

    private fun getAncestor(key: Long): Node{
        var step = 1
        var level = levels-1
        while (step < levels) step *= 2
        while (step > 0) {
            if (level - step >= 0 && hashes[level - step].containsKey(key shr (level - step)))
                level -= step
            step /= 2
        }
        return if (level == levels-1) root else hashes[level].get(key shr level)!!
    }

    private fun nodeSuccessor(key: Long): Node? {
        val lowestAncenstor = getAncestor(key)
        if (lowestAncenstor.isLeaf())
            return lowestAncenstor.rightAdiac
        val descendant = lowestAncenstor.descendant
        if (lowestAncenstor.left == null)
            return descendant
        if (lowestAncenstor.right == null)
            return descendant?.rightAdiac
        return null
    }

    private fun nodePredecessor(key: Long): Node? {
        val lowestAncestor = getAncestor(key)
        val descendant = lowestAncestor.descendant
        if (lowestAncestor.isLeaf())
            return lowestAncestor.leftAdiac
        if (lowestAncestor.left == null)
            return descendant?.leftAdiac
        if (lowestAncestor.right == null)
            return descendant
        return null
    }

    fun successor(key: Long): Long? = nodeSuccessor(key)?.key
    fun predecessor(key: Long): Long? = nodePredecessor(key)?.key


    /**
     * Returns true if the key existed
     */
    fun delete(key: Long): Boolean {
        val leaf = hashes[0][key] ?: return false
        val leftAdiac = leaf.leftAdiac
        val rightAdiac = leaf.rightAdiac
        leftAdiac?.rightAdiac = rightAdiac
        rightAdiac?.leftAdiac = leftAdiac
        hashes[0].remove(key)
        removePath(root, key, leftAdiac, rightAdiac, levels-2, leaf)
        return true
    }

    /**
     * Return true if node is deleted
     */
    private fun removePath(currentNode: Node, key: Long, leftAdiac: Node?, rightAdiac: Node?, level: Int, leaf: Node): Boolean {
        if (level == -1)
            return true
        val nextNode = if (((key shr level) and 1L) == 1L) currentNode.right else currentNode.left
        val del = removePath(nextNode!!, key, leftAdiac, rightAdiac, level - 1, leaf)
        if (currentNode.right == nextNode && del) {
            currentNode.right = null
            currentNode.descendant = leftAdiac
        }
        if (currentNode.left == nextNode && del){
            currentNode.left = null
            currentNode.descendant = rightAdiac
        }
        if (currentNode.left == null && currentNode.right == null) {
            hashes[level+1].remove(key shr (level+1))
            return true
        }
        else if (currentNode.left == nextNode && currentNode.right == null &&
                currentNode.descendant == leaf) {
            currentNode.descendant = leftAdiac
        }
        else if (currentNode.right == nextNode && currentNode.left == null &&
                currentNode.descendant == leaf) {
            currentNode.descendant = rightAdiac
        }
        return false
    }
}

fun checkContains(trie: XFastTrie, values: List<Long>, MAX_VALUE: Long) {
    for (i in 0..MAX_VALUE) {
        val myNext = values.filter({it > i}).sorted().firstOrNull()
        val actualNext = trie.successor(i)
        val myPrev = values.filter({it < i}).sorted().lastOrNull()
        val actualPrev = trie.predecessor(i)

        if (myNext != actualNext)
            println("error")
        if (myPrev != actualPrev)
            println("error")
    }
    val myContent = (0..MAX_VALUE).filter { trie.find(it) }.sorted().toLongArray()
    if (!(myContent contentEquals values.sorted().toLongArray()))
        println("error")
}

fun main(args: Array<String>) {
    val MAX_VALUE = 1023L
    val TO_ADD = 200
    val TO_DELETE = 80
    val trie = XFastTrie(MAX_VALUE)

    val values = (0..MAX_VALUE).shuffled().subList(0, TO_ADD)
    values.forEach { trie.add(it) }

    checkContains(trie, values, MAX_VALUE)

    val toDel = values.shuffled().subList(0, TO_DELETE)
    val rest = values.filter { !toDel.contains(it) }
    toDel.forEach { trie.delete(it) }

    checkContains(trie, rest, MAX_VALUE)
}