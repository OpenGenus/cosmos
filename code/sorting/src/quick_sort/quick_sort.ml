(* Part of Cosmos by OpenGenus Foundation *)

let rec quick_sort = function
  | [] -> []
  | hd :: tl ->
    let lower, higher = List.partition (fun x -> x < hd) tl in
    quick_sort lower @ (hd :: quick_sort higher);;
