// 0 and 1 are the first two numbers in the sequence,
//so we start the accumulators with 0,1.
// At every iteration, we add the two numbers to get the next one.
// Path of Cosmos by OpenGenus Foundation
//returns nth fibonacci number
def fib(n: Int): Int = {
@annotation.tailrec//makes sure loop() is tail recursive
 def loop(n: Int, prev: Int, cur: Int): Int =
  if (n == 0) prev
  else loop(n - 1, cur, prev + cur)
loop(n, 0, 1)
}
//to test
//println(fib(6))

