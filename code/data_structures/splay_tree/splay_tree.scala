
case class SplayTree[T, U](key: T, value: U, left: SplayTree[T, U], right: SplayTree[T, U]) {

    // Should guarantee the inserted key's node is the returned node
    def insert(newKey: T, newValue: U)(implicit ord: Ordering[T]): SplayTree[T, U] = {
        if (ord.lt(newKey, key)) {
            if (left == null) {
                SplayTree(newKey, newValue, null, this)
            } else {
                val newLeft = left.insert(newKey, newValue)
                newLeft.copy(right = this.copy(left = newLeft.right))
            }
        } else if (ord.gt(newKey, key)) {
            if (right == null) {
                SplayTree(newKey, newValue, this, null)
            } else {
                val newRight = right.insert(newKey, newValue)
                newRight.copy(left = this.copy(right = newRight.left))
            }
        } else {
            this
        }
    }

    // Should guarantee the get-ed key's node is the returned node
    def get(newKey: T)(implicit ord: Ordering[T]): Option[SplayTree[T, U]] = {
        if (ord.lt(newKey, key)) {
            if (left == null) {
                None
            } else {
                left.get(newKey).map { newLeft =>
                    newLeft.copy(right = this.copy(left = newLeft.right))
                }
            }
        } else if (ord.gt(newKey, key)) {
            if (right == null) {
                None
            } else {
                right.get(newKey).map { newRight =>
                    newRight.copy(left = this.copy(right = newRight.left))
                }
            }
        } else {
            Option(this)
        }
    }

    def inOrder(visitor: (T, U) => Unit): Unit = {
        if (left != null) left.inOrder(visitor);
        visitor(key, value)
        if (right != null) right.inOrder(visitor);
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        val st = SplayTree("a", 100, null, null).insert("b", 2).insert("c", 3)
        st.inOrder((el: String, priority: Int) => println((el, priority)))
        st.get("b").foreach { st2 =>
            println((st2.key, st2.value))
        }
        st.get("b").get("c").foreach { st2 =>
            println((st2.key, st2.value))
        }
        st.get("b").get("c").get("a").foreach { st2 =>
            println((st2.key, st2.value))
        }
    }
}
