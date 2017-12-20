/* Part of Cosmos by OpenGenus Foundation */
import scala.collection.mutable.ArrayBuffer

object PigeonHoleSort {
  def sort(list: List[Int]): List[Int] = {
    val min = list.min
    val max = list.max

    val buffer: ArrayBuffer[Boolean] = ArrayBuffer((min to max).map(_ => false): _ *)
    list.foreach(x => buffer(x - min) = true)

    Stream.from(min).zip(buffer).collect {
      case (value, hole) if hole => value
    }.toList
  }
  def main(args: Array[String]): Unit = {
    print(PigeonHoleSort.sort(List(-1,2,1,10,15,13)))
  }
}


