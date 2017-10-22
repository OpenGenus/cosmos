import collection.immutable.BitSet

object BloomFilter {
    def apply[T](size: Int): Option[BloomFilter[T]] = {
        if (size < 0) None
        Some(BloomFilter[T](size, BitSet.empty))
    }
}

case class BloomFilter[T](size: Int, bitSet: BitSet) {

    def defaultIndicies(item: T): (Int, Int) = {
        val hash = item.hashCode()
        val hash2 = (hash >> 16) | (hash << 16)
        (Math.floorMod(hash, size), Math.floorMod(hash2, size))
    }

    def add(item: T): BloomFilter[T] = {
        val (h1, h2) = defaultIndicies(item)
        BloomFilter(size, bitSet.+(h1, h2))
    }

    def contains(item: T): Boolean = {
        val (h1, h2) = defaultIndicies(item)
        bitSet.contains(h1) && bitSet.contains(h2)
    }
}

object Main {
    def main(args: Array[String]):  Unit = {
        println(BloomFilter[Int](100).get.add(5))
        println(BloomFilter[Int](100).get.add(5).contains(5))
        println(BloomFilter[Int](100).get.add(5).contains(6))
        println(BloomFilter[Int](100).get.add(5).add(7))
        println(BloomFilter[Int](100).get.add(5).add(7).contains(5))
        println(BloomFilter[Int](100).get.add(5).add(7).contains(7))
        println(BloomFilter[Int](100).get.add(5).add(7).contains(6))
    }
}
