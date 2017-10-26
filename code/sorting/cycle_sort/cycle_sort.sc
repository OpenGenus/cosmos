 def cycleSort(a: Array[Int]): (Array[Int], Int) = {
    var writes = 0
 
    for (cycleStart <- 0 until a.length - 1) {
      var value = a(cycleStart)
 
      // count the number of values that are smaller than value since cycleStart
      var pos = cycleStart
 
      for (i <- cycleStart + 1 until a.length)
        if (a(i) < value) pos += 1
 
      // skip if there aren't any
      if (pos != cycleStart) {
 
        // skip duplicates
        while (a(pos) == value) pos += 1
 
        // put val into final position
        val tmp = a(pos)
        a(pos) = value
        value = tmp
        writes += 1
 
        // repeat as long as we can find values to swap
        // otherwise start new cycle
        while (pos != cycleStart) {
          pos = cycleStart
          for (i <- cycleStart + 1 until a.length)
            if (a(i) < value) pos += 1
 
          while (a(pos) == value) pos += 1
 
          val tmp = a(pos)
          a(pos) = value
          value = tmp
          writes += 1
        }
      }
    }
    (a, writes)
  }
 
