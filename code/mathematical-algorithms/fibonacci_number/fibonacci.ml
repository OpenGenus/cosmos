(* Part of Cosmos by OpenGenus Foundation *)

let rec fibonacci n =
  if n <= 1 then n
  else fibonacci (n-2) + fibonacci (n-1);;
