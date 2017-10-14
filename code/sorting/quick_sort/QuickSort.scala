/* Part of Cosmos by OpenGenus Foundation */
object QuickSort extends App {

  def quickSort[A <% Ordered[A]](input: List[A]): List[A] = {
    input match {
      case Nil => Nil
      case head :: tail =>
        val (l, g) = tail partition (_ < head)
        quickSort(l) ::: head :: quickSort(g)
    }
  }

  val input = (0 to 1000) map (_ => scala.util.Random.nextInt(1000))
  val output = quickSort(input.toList)
  Console.println(output)
}