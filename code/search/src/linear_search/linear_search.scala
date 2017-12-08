/* Part of Cosmos by OpenGenus Foundation */

object LinearSearch extends App {

  def linearSearch[A: Equiv](list: List[A], element: A): Option[Int] = {
    list match {
      case Nil => None
      case head :: tail => if (head == element) Some(0) else (linearSearch(tail, element).map(_ + 1))
    }
  }

  val list = (0 to 1000) map (_ => scala.util.Random.nextInt(1000))
  val element = scala.util.Random.nextInt(1000)
  val output = linearSearch(list.toList, element)
  Console.println(s"Index: $output")
  
}