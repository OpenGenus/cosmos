import annotation.tailrec
import collection.mutable.{IndexedSeq, IndexedSeqLike}

object QuicksortInPlace {
    def sort[T](data: IndexedSeqLike[T, _])(implicit ord: Ordering[T]): Unit = {
        sort(data, 0, data.length)
    }

    // start inclusive, end exclusive
    def sort[T](data: IndexedSeqLike[T, _], start: Int, end: Int)(implicit ord: Ordering[T]): Unit = {
        val runLength = end - start
        if (runLength < 2) {
            return
        }
        else if (runLength == 2) {
            if (ord.gt(data(start), data(start + 1))) {
                val t = data(start)
                data(start) = data(start + 1)
                data(start + 1) = t
            }
            return
        }
        else {
            val pivot = {
                val midIndex = start + (end - start) / 2
                val (a, b, c) = (data(start), data(midIndex), data(end - 1))
                if (ord.lt(a, b)) {
                    if (ord.lt(b, c))   b
                    else                ord.max(a, c)
                } else {
                    if (ord.lt(c, b))   b
                    else                ord.min(a, c)
                }
            }

            // Dutch flag version
            var low = start
            var mid = start
            var high = end - 1
            while (mid <= high) {
                if (ord.lt(data(mid), pivot)) {
                    val t = data(mid)
                    data(mid) = data(low)
                    data(low) = t
                    low += 1
                    mid += 1
                }
                else if (ord.equiv(data(mid), pivot)) {
                    mid += 1
                }
                else {
                    // mid is higher than pivot
                    val t = data(mid)
                    data(mid) = data(high)
                    data(high) = t
                    high -= 1
                }
            }
            sort(data, start, low)
            sort(data, mid, end)
        }
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        val a = IndexedSeq((0 until 100000) map (_ => scala.util.Random.nextInt(100000)):_*)
        val s = System.currentTimeMillis()
        QuicksortInPlace.sort(a)
        val e = System.currentTimeMillis()
        println(a.toList == a.toList.sorted)
        println((e - s) + " ms")
    }
}
