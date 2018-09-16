(* Bubblesort
 * Time complexity:  O( n^2 )
 *)
fun bubblesort [] = []
  | bubblesort (x::xs) =
    let
      val (y, ys, s) = foldl ( fn (c, (p, ps, s)) =>
          if c < p then (p, c::ps, true) else (c, p::ps, s)
      ) (x, [], false) xs;
      val xs' = foldl op:: [] (y::ys)
    in
        if s then bubblesort xs' else xs'
    end

val test_0 = bubblesort [] = []
val test_1 = bubblesort [1,2,3] = [1, 2, 3]
val test_2 = bubblesort [1,3,2] = [1, 2, 3]
val test_3 = bubblesort [6,2,7,5,8,1,3,4] = [1, 2, 3, 4, 5, 6, 7, 8]
