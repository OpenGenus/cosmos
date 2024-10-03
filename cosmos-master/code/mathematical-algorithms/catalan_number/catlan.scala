 def catalan(n: Int): Int =
    if (n <= 1) 1
    else (0 until n).map(i => catalan(i) * catalan(n - i - 1)).sum
/* to test
  *var c = catalan(3)
  *println(c)
*/