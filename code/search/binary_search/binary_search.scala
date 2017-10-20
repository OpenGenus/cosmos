object binary_search {
	def recursiveBinarySearch[A <% Ordered[A]](a: IndexedSeq[A], v: A) = {
	  def recurse(low: Int, high: Int): Option[Int] = (low + high) / 2 match {
	    case _ if high < low => None
	    case mid if a(mid) > v => recurse(low, mid - 1)
	    case mid if a(mid) < v => recurse(mid + 1, high)
	    case mid => Some(mid)
	  }
	  recurse(0, a.size - 1)
	}

	def binarySearch[T](xs: Seq[T], x: T)(implicit ordering: Ordering[T]): Option[Int] = {
	    var low: Int = 0
	    var high: Int = xs.size - 1
	 
	    while (low <= high)
	      low + high >>> 1 match {
	        case guess if ordering.gt(xs(guess), x) => high = guess - 1 //too high
	        case guess if ordering.lt(xs(guess), x) => low = guess + 1 // too low
	        case guess => return Some(guess) //found it
	      }
	    None //not found
	  }

	def testBinarySearch(n: Int) = {
	  val odds = 1 to n by 2
	  val result = (0 to n).flatMap(binarySearch(odds, _))
	  assert(result == (0 until odds.size))
	  println(s"$odds are odd natural numbers")
	  for (it <- result)
	    println(s"$it is ordinal of ${odds(it)}")
	}
	 
	def main(args: Array[String]): Unit = {
		testBinarySearch(12)
	}
}


