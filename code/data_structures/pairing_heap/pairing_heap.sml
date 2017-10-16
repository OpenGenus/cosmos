(* Pairing heap - http://en.wikipedia.org/wiki/Pairing_heap *)
functor PairingHeap(type t
                    val cmp : t * t -> order) =
struct
  datatype 'a heap = Empty
                   | Heap of 'a * 'a heap list;

  (* merge, O(1)
   * Merges two heaps *)
  fun merge (Empty, h) = h
    | merge (h, Empty) = h
    | merge (h1 as Heap(e1, s1), h2 as Heap(e2, s2)) =
        case cmp (e1, e2) of LESS => Heap(e1, h2 :: s1)
                            |   _ => Heap(e2, h1 :: s2)

  (* insert, O(1)
   * Inserts an element into the heap *)
  fun insert (e, h) = merge (Heap (e, []), h)

  (* findMin, O(1)
   * Returns the smallest element of the heap *)
  fun findMin Empty = raise Domain
    | findMin (Heap(e, _)) = e

  (* deleteMin, O(lg n) amortized
   * Deletes the smallest element of the heap *)
  local
    fun mergePairs [] = Empty
      | mergePairs [h] = h
      | mergePairs (h1::h2::hs) = merge (merge(h1, h2), mergePairs hs)
  in
    fun deleteMin Empty = raise Domain
      | deleteMin (Heap(_, s)) = mergePairs s
  end

  (* build, O(n)
   * Builds a heap from a list *)
  fun build es = foldl insert Empty es;
end

local
  structure IntHeap = PairingHeap(type t = int; val cmp = Int.compare);
  open IntHeap

  fun heapsort' Empty = []
    | heapsort' h = findMin h :: (heapsort' o deleteMin) h;
in
  fun heapsort ls = (heapsort' o build) ls

  val test_0 = heapsort [] = []
  val test_1 = heapsort [1,2,3] = [1, 2, 3]
  val test_2 = heapsort [1,3,2] = [1, 2, 3]
  val test_3 = heapsort [6,2,7,5,8,1,3,4] = [1, 2, 3, 4, 5, 6, 7, 8]
end;
