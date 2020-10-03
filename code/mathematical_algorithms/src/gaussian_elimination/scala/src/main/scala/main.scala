import gaussian.elimination.GaussianElimination
import structures.{Epsilon, RegularMatrix}

object Main extends App {
  val matrixTest = RegularMatrix[Double](List(
    List[Double](0.02, 0.01, 0, 0),
    List[Double](1.0, 2, 1, 0),
    List[Double](0, 1, 2, 1),
    List[Double](0, 0, 100, 200)
  ))

  // example from
  // http://web.mit.edu/10.001/Web/Course_Notes/GaussElimPivoting.html

  val matrixTest2 = RegularMatrix[Double]((0.0 until 100.0 by 1.0).toList.map(i => (0.0 until 100.0 by 1.0).toList))
  val b2 = (100.0 until 0.0 by -1.0).toList

  val b = List[Double](0.02, 1, 4, 800)
  
  val solution = GaussianElimination.startAlgorithm(matrixTest, b, Epsilon(6))

  println(solution.matrix)

  solution.solve() match {
    case None => println("No solution")
    case Some(result) => println(result)
  }

  //println(GaussianElimination.startAlgorithm(matrixTest2, b, Epsilon(3)))

  //(0 until matrixTest.N).map(matrixTest.maxByColumn).foreach(println)
}
