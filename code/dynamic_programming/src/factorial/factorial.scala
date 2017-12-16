/* Part of Cosmos by OpenGenus Foundation */

import scala.annotation.tailrec

/**
  * Implement factorial using tail recursion
  */
object main {

  @tailrec
  private def _factorial(of: Int, current: Int): Int = {
    if (of == 0) {
      current
    } else {
      _factorial(of - 1, of * current)
    }
  }

  def factorial(of: Int): Int = {
    _factorial(of, 1)
  }

  def main(args: Array[String]) = {
    val number: Int = 5
    println(s"The factorial of ${number} is ${factorial(number)}")
  }
}
