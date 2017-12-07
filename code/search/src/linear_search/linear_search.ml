(* Part of Cosmos by OpenGenus Foundation *)

let rec linear_search x = function
  | [] -> -1
  | hd :: tl when hd == x -> 0
  | hd :: tl -> 1 + (linear_search x tl);;
