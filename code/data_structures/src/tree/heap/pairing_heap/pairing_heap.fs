module PairHeap

type Heap<'a> =
    | Empty
    | Heap of 'a * (Heap<'a> list)

let findMin =
    function
    | Empty -> failwith "empty"
    | Heap (c, _) -> c

let merge heap1 heap2 =
    match heap1, heap2 with
    | Empty, _ -> heap2
    | _, Empty -> heap1
    | Heap (c1, sub1), Heap (c2, sub2) ->
        if c1 > c2 then
            Heap (c1, heap2::sub1)
        else
            Heap (c2, heap1::sub2)

let insert c heap =
    merge (Heap (c, [])) heap

let rec mergePairs =
    function
    | [] -> Empty
    | [sub] -> sub
    | sub1::sub2::rest -> merge (merge sub1 sub2) (mergePairs rest)

let deleteMin =
    function
    | Empty -> failwith "empty"
    | Heap (_, sub) -> mergePairs sub