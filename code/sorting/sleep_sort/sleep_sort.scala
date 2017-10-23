object Main
{
  def sleep_sort(xs: List[Int]): List[Int] =
  {
    var r: List[Int] = Nil
    var threads: List[Thread] = Nil
    for (x <- xs)
    {
      val t = new Thread(new Runnable
      {
        def run()
        {
          Thread.sleep(x)
          this.synchronized
          {
            r = r:+ x
          }
        }
      })
      threads = t :: threads
      t.start
    }

    for (t <- threads)
    {
      t.join()
    }
    r
  }
  def main(args: Array[String]) =
  {
    println(sleep_sort(List(100,99,3,15,2)))
  }
}
