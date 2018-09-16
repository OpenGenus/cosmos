object Main
{

  def merge(left: List[Int], right: List[Int]): List[Int] =
  {
    if (left.isEmpty)
    {
      return right
    }
    else if (right.isEmpty)
    {
      return left
    }

    if (left.head < right.head)
    {
      return left.head :: merge(left.tail, right)
    }
    else
    {
      return right.head :: merge(left, right.tail)
    }
  }

  def merge_sort(xs: List[Int]): List[Int] = {
    if (xs.size == 1) {
      return xs
    }

    merge(merge_sort(xs.slice(0, xs.size/2)), merge_sort(xs.slice(xs.size/2, xs.size)))
  }

  def main(args: Array[String]) =
  {
    println(merge(List(1,3,5), List(2,4,6)))
    println(merge_sort(List(4,2,3,1,6,2,7,1,116,3,11,135)))
  }
}
