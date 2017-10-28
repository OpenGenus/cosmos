import scala.annotation.tailrec

/**
  * Implement log of factorial using tail recursion
  */
object main {

  @tailrec
  private def _factorial(n: Int, ans: Double, i: Int): Double = {
    if (i > n) {
      ans
    } else {
      _factorial(n, ans + math.log(i), i + 1)
    }
  }

  def factorial(of: Int): Double = _factorial(of, 0.0, 1)

  def main(args: Array[String]) = {
    val number: Int = 5
    println(s"The factorial of log ($number) is ${factorial(number)}")
  }
}