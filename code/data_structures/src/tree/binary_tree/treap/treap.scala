import java.util.Random

case class Treap[T](el: T, priority: Int, left: Treap[T], right: Treap[T]) { // extends Treap[T] {

    def contains(target: T)(implicit ord: Ordering[T]): Boolean = {
        if (target == el) {
            true
        } else if (ord.lt(target, el)) {
            if (left == null) false
            else left.contains(target)
        } else {
            if (right == null) false
            else right.contains(target)
        }
    }

    def insert(newEl: T)(implicit ord: Ordering[T]): Treap[T] = insert(newEl, new Random().nextInt())

    def insert(newEl: T, newPriority: Int)(implicit ord: Ordering[T]): Treap[T] = {
        if (newEl == el) {
            this
        } else if (ord.lt(newEl, el)) {
            val newTreap = 
                if (left == null) {
                    this.copy(left = Treap(newEl, newPriority, null, null))
                } else {
                    this.copy(left = left.insert(newEl, newPriority))
                }

            if (newTreap.left.priority > priority) {
                // rotate right to raise node with higer priority
                val leftChild = newTreap.left
                leftChild.copy(right = newTreap.copy(left = leftChild.right))
            } else {
                newTreap
            }
        } else {
            val newTreap = 
                if (right == null) {
                    this.copy(right = Treap(newEl, newPriority, null, null))
                } else {
                    this.copy(right = right.insert(newEl, newPriority))
                }

            if (newTreap.right.priority > priority) {
                // rotate left to raise node with higer priority
                val rightChild = newTreap.right
                rightChild.copy(left = newTreap.copy(right = rightChild.left))
            } else {
                newTreap
            }
        }
    }

    def inOrder(visitor: (T, Int) => Unit): Unit = {
        if (left != null) left.inOrder(visitor);
        visitor(el, priority)
        if (right != null) right.inOrder(visitor);
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        Treap("a", 100, null, null).insert("b").insert("c").inOrder((el: String, priority: Int) => println((el, priority)))
        Treap("a", 100, null, null).insert("c").insert("c").inOrder((el: String, priority: Int) => println((el, priority)))
        Treap("a", 100, null, null).insert("c").insert("b").inOrder((el: String, priority: Int) => println((el, priority)))
        println(Treap("a", 100, null, null).insert("c").insert("b").contains("e"))
        println(Treap("a", 100, null, null).insert("c").insert("b").contains("b"))
        println(Treap("a", 100, null, null).insert("c").insert("b").contains("a"))
    }
}
