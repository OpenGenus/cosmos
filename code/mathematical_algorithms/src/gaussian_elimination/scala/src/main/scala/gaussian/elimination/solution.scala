package gaussian.elimination

import structures.{Epsilon, Matrix}

case class Solution(matrix: Matrix[Double], b: List[Double], lastPivot: Int, epsilon: Epsilon) {
  def isSingular: MatrixType = {
    val det = (0 until matrix.M).foldRight(1.0)((curr, acc) => matrix.rows(curr)(curr) * acc)

    if( det != 0 ) NotSingular
    else Singular
  }

  def solve(): Option[List[Double]] = {
    isSingular match {
      case Singular => None
      case NotSingular => Some(solveSystem())
    }
  }

  private def solveSystem(): List[Double] = {
    /*
      1 2 3 4 5
      0 1 2 3 4
      0 0 1 2 3
      0 0 0 1 2
      0 0 0 0 1
      =>
      0 0 0 0 1
      0 0 0 1 2
      0 0 1 2 3
      0 1 2 3 4
      1 2 3 4 5
     */

    /*
      1
      1 2
      1 2 3
      1 2 3 4
      1 2 3 4 5
     */
    val removedZeroes = matrix.rows.map(r => r.dropWhile(_ == 0.0)).reverse

    val zippedWithB = removedZeroes.zip(b.reverse)

    val result = zippedWithB.foldLeft(List.empty[Double]) { (acc, curr) =>
      val result = curr._2
      val coefficient = curr._1.head
      val restOfEquation = curr._1.tail
      val leftSideSum = restOfEquation.zip(acc).foldRight(0.0) { (curr, acc) =>
        acc + curr._1 * curr._2
      }

      epsilon.truncate((result - leftSideSum) / coefficient) +: acc
    }

    result
  }
}
