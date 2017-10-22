
object BinomialHeap {
    def apply[T](value: T)(implicit ord: Ordering[T], treeOrd: Ordering[BinTree[T]]) = new BinomialHeap(Map())(ord, treeOrd).add(BinTree(value))
}

case class BinomialHeap[T](heap: Map[Int, BinTree[T]])(implicit ord: Ordering[T], treeOrd: Ordering[BinTree[T]]) {

    def add(tree: BinTree[T]): BinomialHeap[T] = {
        if (heap.contains(tree.order)) {
            BinomialHeap(heap - tree.order).add(tree.merge(heap(tree.order)))
        } else {
            BinomialHeap(heap + (tree.order -> tree))
        }
    }

    def add(value: T): BinomialHeap[T] = add(BinTree(value))

    def min(): T = heap.valuesIterator.min.value

    def deleteMin(): BinomialHeap[T] = {
        val minTree = heap.valuesIterator.min
        if (minTree.order == 0) {
            BinomialHeap(heap - minTree.order)
        } else {
            val remainingHeap = BinomialHeap(heap - minTree.order)
            minTree.kids.foldLeft(remainingHeap) { case (acc: BinomialHeap[T], tree: BinTree[T]) => acc.add(tree) }
        }
    }
}

object BinTree {
    def apply[T](value: T)(implicit ord: Ordering[T]) = new BinTree(value, 0, IndexedSeq())
}

case class BinTree[T](value: T, order: Int, kids: IndexedSeq[BinTree[T]])(implicit ord: Ordering[T]) {

    def merge(other: BinTree[T]): BinTree[T] = {
        assert(other.order == order)

        if (ord.lt(other.value, value)) {
            BinTree(other.value, order + 1, other.kids :+ this)
        } else {
            BinTree(value, order + 1, kids :+ other)
        }
    }
}

object Main {
    def main(args: Array[String]):  Unit = {
        implicit val ord = Ordering.by[BinTree[Int], Int](_.value)
        println(BinomialHeap(10).add(-5))
        println(BinomialHeap(10).add(-5).add(3))
        println(BinomialHeap(10).add(-5).add(3).add(13))
        println(BinomialHeap(10).add(-5).add(3).add(13).min)
        println(BinomialHeap(10).add(-5).add(3).add(13).deleteMin())
    }
}
