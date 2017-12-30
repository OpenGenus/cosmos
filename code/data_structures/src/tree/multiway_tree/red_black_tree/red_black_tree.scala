
// From http://scottlobdell.me/2016/02/purely-functional-red-black-trees-python/

case class RBTree[T](left: RBTree[T], value: T, right: RBTree[T], isBlack: Boolean) {

    val height: Int = {
        val leftHeight  = if (left  == null) 0 else left.height
        val rightHeight = if (right == null) 0 else right.height
        Math.max(leftHeight, rightHeight)
    }

    def insert(value: T)(implicit ord: Ordering[T]): RBTree[T] = update(RBTree(null, value, null, false)).blacken()

    def balance(): RBTree[T] = {
        if (!isBlack) {
            this
        }
        else if (left != null && !left.isBlack) {
            if (right != null && !right.isBlack)                recolored()
            else if (left.left  != null && !left.left.isBlack)  rotateRight().recolored()
            else if (left.right != null && !left.right.isBlack) this.copy(left = left.rotateLeft()).rotateRight().recolored()
            else this
        }
        else if (right != null && !right.isBlack) {
            if (right.right != null && !right.right.isBlack)    rotateLeft().recolored()
            else if (right.left != null && !right.left.isBlack) this.copy(right = right.rotateRight()).rotateLeft().recolored()
            else                                                this
        }
        else this
    }

    def update(node: RBTree[T])(implicit ord: Ordering[T]): RBTree[T] = {
        if (ord.lt(node.value, value)) {
            if (left == null) this.copy(left = node.balance()).balance()
            else              this.copy(left = left.update(node).balance()).balance()
        }
        else {
            if (right == null) this.copy(right = node.balance()).balance()
            else               this.copy(right = right.update(node).balance()).balance()
        }
    }

    def blacken(): RBTree[T] = {
        if (isBlack) this
        else         this.copy(isBlack = true)
    }

    def recolored() = RBTree(left.blacken(), value, right.blacken(), false)

    def rotateLeft():  RBTree[T] = right.copy(left = this.copy(right = right.left))
    def rotateRight(): RBTree[T] = left.copy(right = this.copy(left  = left.right))

    def isMember(other: T)(implicit ord: Ordering[T]): Boolean = {
        if (ord.lt(other, value))       left.isMember(other)
        else if (ord.gt(other, value))  right.isMember(other)
        else true
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        println(RBTree(null, 7, null, false).insert(6).insert(3))
        println(RBTree(null, 1, null, false).insert(2))
        println(RBTree(null, 1, null, false).insert(2).insert(3))
        println(RBTree(null, 1, null, false).insert(2).insert(3).insert(4).insert(5))
        println(RBTree(null, 1, null, false).insert(2).insert(3).insert(4).insert(5).insert(6))
        println(RBTree(null, 1, null, false).insert(2).insert(3).insert(4).insert(5).insert(6).insert(7))
    }
}
