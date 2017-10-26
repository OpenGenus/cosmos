
object Catalan {
    def number(n: Int): BigInt = {
        if (n < 2) {
            1
        }
        else {
            val (top, bottom) = (2 to n).foldLeft((BigInt(1), BigInt(1))) { 
                    case ((topProd: BigInt, bottomProd: BigInt), k: Int) => (topProd * (n + k), bottomProd * k) 
                }
            top / bottom
        }
    }

    // to test
    // var c = catalan(3)
    // println(c)
    def recursive(n: Int): Int = {
        if (n <= 1) 1
        else (0 until n).map(i => recursive(i) * recursive(n - i - 1)).sum
    }
}

object Main {
    def main(args: Array[String]): Unit = {
        for (n <- 0 until 20) {
            println(s"${n}: ${Catalan.number(n)}")
        }
    }
}
