import java.util.Random
import scala.collection.Searching._
import scala.reflect.ClassTag

object SkipList {
    val MAX_LEVELS = 32;
    val random = new Random()
}

class SkipList[T](private var nextLists: Array[SkipList[T]], private var data: T) {

    def this(firstElement: T) = this(Array.ofDim(SkipList.MAX_LEVELS), firstElement)

    private def randomNumberOfLevels(maxLevels: Int): Int = {
        var i = SkipList.random.nextInt()
        var count = 1
        while ((i & 1) == 1 && count < maxLevels) {
            count += 1
            i = i >> 1
        }
        count
    }

    def contains(target: T)(implicit ord: Ordering[T]): Boolean = {
        return contains(target, nextLists.length - 1)
    }

    def contains(target: T, level: Int)(implicit ord: Ordering[T]): Boolean = {
        // println(s"contains: level ${level}, target ${target}")
        if (level == 0) {
            return (
                if (target == data) {
                    true
                }
                else if (ord.lt(target, data)) {
                    false
                }
                else if (nextLists(0) != null) {
                    nextLists(0).contains(target, level)
                }
                else {
                    false
                })
        }
        else if (nextLists(level) == null || ord.lt(target, nextLists(level).data)) {
            return contains(target, level - 1)
        }
        else if (ord.gteq(target, nextLists(level).data)) {
            return nextLists(0).contains(target, level)
        }
        throw new RuntimeException("Shouldn't get here.")
    }

    def insert(newElement: T)(implicit ord: Ordering[T]): Unit = {
        insert(newElement, nextLists.length - 1, this)
    }

    def insert(newElement: T, level: Int, headOfList: SkipList[T])(implicit ord: Ordering[T]): Unit = {
        // println(s"insert: level ${level}, newElement ${newElement}, current element: ${data}.")
        if (level == 0) {
            if (newElement == data) {
                return
            }
            else if (nextLists(0) != null && ord.gteq(newElement, nextLists(0).data)) {
                return insert(newElement, level, headOfList)
            }
            else {
                // Create next node with random height and elements that don't fit into this node
                val numLevelsForNewNode = randomNumberOfLevels(SkipList.MAX_LEVELS)
                val nextNode = new SkipList(Array.ofDim[SkipList[T]](numLevelsForNewNode), newElement)
                // Fix bottom links, this -> new -> next
                nextNode.nextLists(0) = nextLists(0)
                nextLists(0) = nextNode

                if (ord.gt(data, newElement)) {
                    nextNode.data = data
                    data = newElement
                }

                return headOfList.insertNewNode(nextNode, nextNode.nextLists.length - 1)
            }
        }
        else if (nextLists(level) == null) {
            return insert(newElement, level - 1, headOfList)
        }
        else if (ord.gteq(newElement, nextLists(level).data)) {
            return nextLists(level).insert(newElement, level, headOfList)
        }
        throw new RuntimeException("Shouldn't get here.")
    }

    def insertNewNode(newNode: SkipList[T], startLevel: Int)(implicit ord: Ordering[T]): Unit = {
        var currentNode = this
        for (level <- startLevel until 0 by -1) {
            while (currentNode.nextLists(level) != null && ord.gteq(newNode.data, currentNode.nextLists(level).data)) {
                currentNode = currentNode.nextLists(level)
            }
            newNode.nextLists(level) = currentNode.nextLists(level)
            currentNode.nextLists(level) = newNode
        }
    }

    override def toString(): String = {
        data + (if (nextLists(0) == null) "" else ", " + nextLists(0))
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        val list = new SkipList(Array.ofDim[SkipList[String]](5), "aab")
        println(list)
        println(list.contains("aaa"))
        println(list.contains("aab"))
        list.insert("aaa")
        println(list)
        println(list.contains("aaa"))
        println(list.contains("aab"))
        list.insert("aac")
        println(list)
        println(list.contains("aaa"))
        println(list.contains("aab"))
        println(list.contains("aac"))
    }
}
