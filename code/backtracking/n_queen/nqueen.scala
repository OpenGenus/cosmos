
object NQueens {
  type Board = List[Int]
  
  def solve(n:Int) : Option[Board] = solve1(n, List.empty).headOption.map(_.reverse)
  
  def solve1(n:Int, b: Board) : List[Board] = if ( n == 0) {
    List(b)
  } else (for {
      i <- 1 to (n + b.size)
      if placeable(i,b)
      r <- solve1(n-1,i :: b)
    } yield r).toList
  
  
  def placeable(n:Int, board:Board): Boolean = 
    board.zip(Stream.from(1)).filter { case (x, i) =>
      n == x || math.abs (n - x) == i
    }.isEmpty
  
}