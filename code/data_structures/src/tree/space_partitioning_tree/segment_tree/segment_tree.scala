import scala.reflect.ClassTag

case class SegmentTree[T: ClassTag](input: Array[T], aggregator: (T, T) => T) {

    val maxArraySize = Math.pow(2.0, Math.ceil(Math.log(input.length) / Math.log(2.0))).toInt * 2 - 1
    val treeArray = populateTree((0, input.length - 1), Array.ofDim[T](maxArraySize), 0)

    def leftChild(index: Int) = index * 2 + 1
    def rightChild(index: Int) = index * 2 + 2
    def midIndex(left: Int, right: Int) = left + (right - left) / 2

    def populateTree(inputRange: (Int, Int), treeArray: Array[T], treeIndex: Int): Array[T] = {
        assert(inputRange._1 <= inputRange._2)

        if (inputRange._1 == inputRange._2) {
            treeArray(treeIndex) = input(inputRange._1)
        }
        else {
            val mid = midIndex(inputRange._1, inputRange._2)
            populateTree((inputRange._1, mid), treeArray, leftChild(treeIndex))
            populateTree((mid + 1, inputRange._2), treeArray, rightChild(treeIndex))
            treeArray(treeIndex) = aggregator(treeArray(leftChild(treeIndex)), treeArray(rightChild(treeIndex)))
        }
        treeArray
    }

    def getAggregate(start: Int, end: Int): T = {
        assert(start <= end)
        getAggregate(0, input.length - 1, start, end, 0)
    }

    def getAggregate(start: Int, end: Int, queryStart: Int, queryEnd: Int, treeIndex: Int): T = {
        // Query range entirely inside of range
        // println(s"segment range: ${start}, ${end}")
        // println(s"query range: ${queryStart}, ${queryEnd}")
        if (queryStart <= start && queryEnd >= end) {
            // println("returning single node value")
            treeArray(treeIndex)
        }
        else {
            val mid = midIndex(start, end)
            // println(s"${start}, ${mid}, ${end}")

            if (mid < queryStart) {
                // Query range starts after mid, throw out left half
                getAggregate(mid + 1, end, queryStart, queryEnd, rightChild(treeIndex))
            }
            else if (queryEnd < mid + 1) {
                // Query range ends beefore mid, throw out right half
                getAggregate(start, mid, queryStart, queryEnd, leftChild(treeIndex))
            }
            else {
                aggregator(
                    getAggregate(start,   mid, queryStart, queryEnd, leftChild(treeIndex)),
                    getAggregate(mid + 1, end, queryStart, queryEnd, rightChild(treeIndex)))
            }
        }
    }

    def update(index: Int, value: T): Unit = {
        update((0, treeArray.length - 1), index, value, 0)
    }

    def update(inputRange: (Int, Int), index: Int, value: T, treeIndex: Int): Unit = {
         if (inputRange._1 == inputRange._2) {
            assert(index == inputRange._1)
            treeArray(treeIndex) = value
        }
        else {
            val mid = midIndex(inputRange._1, inputRange._2)
            if (index <= mid) {
                update((inputRange._1, mid), index, value, leftChild(treeIndex))
            }
            else {
                update((mid + 1, inputRange._2), index, value, rightChild(treeIndex))
            }
            treeArray(treeIndex) = aggregator(treeArray(leftChild(treeIndex)), treeArray(rightChild(treeIndex)))
        }
   }
}

object Main {
    def main(args: Array[String]): Unit = {
        val segTree = SegmentTree[Int](Array(1, 2, -3, 4, 5), (x: Int, y: Int) => Math.min(x, y))
        println(segTree.getAggregate(0, 13))
        val sumTree = SegmentTree[Int](Array(1, 2, -3, 4, 5), (x: Int, y: Int) => x + y)
        println(sumTree.getAggregate(1, 3))
    }
}
