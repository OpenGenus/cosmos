/**
 *  Fully persistent Treap implementation (Allows all operations in any version)
 *  Average complexity for insert, search and remove is O(log N)
 *  It uses O(N * log N) memory.
 */

import java.util.*


class TreapNode<T : Comparable<T>> {
    val value: T
    val priority: Int
    val leftChild: TreapNode<T>?
    val rightChild: TreapNode<T>?

    constructor(value: T, priority: Int, leftChild: TreapNode<T>?, rightChild: TreapNode<T>?) {
        this.value = value
        this.priority = priority
        this.leftChild = leftChild
        this.rightChild = rightChild
    }
    constructor(value: T, leftChild: TreapNode<T>?, rightChild: TreapNode<T>?)
            : this(value, Random().nextInt(), leftChild, rightChild)

    fun cloneReplaceLeft(leftChild: TreapNode<T>?): TreapNode<T> {
        return TreapNode(this.value, this.priority, leftChild, this.rightChild)
    }

    fun cloneReplaceRight(rightChild: TreapNode<T>?): TreapNode<T> {
        return TreapNode(this.value, this.priority, this.leftChild, rightChild)
    }
}


class PersistentTreap<T : Comparable<T>>(private val root: TreapNode<T>? = null) {

    fun insert(value: T): PersistentTreap<T> {
        return PersistentTreap(insert(root, value))
    }

    fun remove(value: T): PersistentTreap<T> {
        return PersistentTreap(remove(root, value))
    }

    fun search(value: T): Boolean {
        return search(root, value)
    }

    fun inorder(): List<T> {
        return inorder(root)
    }

    fun dump() {
        if (root == null)
            println("Empty tree")
        else
            dump(root, 0)
    }

    private fun dump(currentNode: TreapNode<T>?, offset: Int) {
        if (currentNode != null) {
            dump(currentNode.rightChild, offset + 1)
            print(" ".repeat(offset))
            print(String.format("%s\t %20d\n", currentNode.value.toString(), currentNode.priority))
            dump(currentNode.leftChild, offset + 1)

        }
    }

    private fun inorder(currentNode: TreapNode<T>?): List<T> {
        if (currentNode == null)
            return listOf()
        val list: MutableList<T> = mutableListOf()
        list.addAll(inorder(currentNode.leftChild))
        list.add(currentNode.value)
        list.addAll(inorder(currentNode.rightChild))
        return list
    }

    private fun rotateLeft(currentNode: TreapNode<T>?): TreapNode<T>? {
        return currentNode?.rightChild?.cloneReplaceLeft(
                currentNode.cloneReplaceRight(currentNode.rightChild.leftChild))
    }

    private fun rotateRight(currentNode: TreapNode<T>?): TreapNode<T>? {
        return currentNode?.leftChild?.cloneReplaceRight(
                currentNode.cloneReplaceLeft(currentNode.leftChild.rightChild)
        )
    }

    private fun balance(currentNode: TreapNode<T>?): TreapNode<T>? {
        if (currentNode == null) return null
        if (currentNode.leftChild != null && currentNode.leftChild.priority > currentNode.priority)
            return rotateRight(currentNode)
        if (currentNode.rightChild != null && currentNode.rightChild.priority > currentNode.priority)
            return rotateLeft(currentNode)
        return currentNode
    }

    private fun insert(currentNode: TreapNode<T>?, value: T): TreapNode<T>? {
        if (currentNode == null)
            return TreapNode(value, null, null)
        return balance(
            if (value <= currentNode.value)
                currentNode.cloneReplaceLeft(insert(currentNode.leftChild, value))
            else
                currentNode.cloneReplaceRight(insert(currentNode.rightChild, value))
        )
    }

    private fun remove(currentNode: TreapNode<T>?, value: T): TreapNode<T>? {
        if (currentNode == null || (currentNode.leftChild == null && currentNode.rightChild == null && currentNode.value == value))
            return null
        return when {
            value < currentNode.value -> currentNode.cloneReplaceLeft(remove(currentNode.leftChild, value))
            value > currentNode.value -> currentNode.cloneReplaceRight(remove(currentNode.rightChild, value))
            else -> if (currentNode.leftChild == null ||
                            (currentNode.rightChild != null && currentNode.rightChild.priority > currentNode.leftChild.priority))
                        with (rotateLeft(currentNode)!!) {
                            cloneReplaceLeft(remove(leftChild, value))
                        }
                    else
                        with (rotateRight(currentNode)!!) {
                            cloneReplaceRight(remove(rightChild, value))
                        }
        }
    }

    private fun search(currentNode: TreapNode<T>?, value: T): Boolean {
        if (currentNode == null)
            return false
        return when {
            value < currentNode.value -> search(currentNode.leftChild, value)
            value > currentNode.value -> search(currentNode.rightChild, value)
            else -> true
        }
    }

}

fun <T : Comparable<T>> List<T>.isSorted(): Boolean {
    return (0 until this.size-1).none { this[it] > this[it +1] }
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val treapVersions: MutableList<PersistentTreap<Int>> = mutableListOf()
    var currentTreap = PersistentTreap<Int>()
    treapVersions.add(currentTreap)
    println("Treap Test\n")
    /**  Perform tree operations  **/
    loop@ while (true) {
        println("\nTreap Operations\n")
        println("1. insert ")
        println("2. delete ")
        println("3. search")
        println("4. show tree")
        println("5. exit")

        print("Choose version: ")
        val version = scan.nextInt()
        if (version >= treapVersions.size) {
            println("Version $version does not exist")
            continue
        }
        currentTreap = treapVersions[version]

        print("Choose operation: ")
        val choice = scan.nextInt()
        when (choice) {
            1 -> {
                println("Enter integer element to insert")
                currentTreap = currentTreap.insert(scan.nextInt())
            }
            2 -> {
                println("Enter integer element to delete")
                currentTreap = currentTreap.remove(scan.nextInt())
            }
            3 -> {
                println("Enter integer element to search")
                println("Search result : " + currentTreap.search(scan.nextInt()))
            }
            4 -> currentTreap.dump()
            5 -> break@loop
            else -> println("Invalid operation")
        }
        if (!currentTreap.inorder().isSorted())
            println("SOMETHING WENT WRONG")
        if (choice == 1 || choice == 2) {
            println("Created version ${treapVersions.size}")
            treapVersions.add(currentTreap)
        }
    }
}
