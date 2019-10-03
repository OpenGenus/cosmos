(* Part of Cosmos by OpenGenus Foundation *)

let rec sort = function
	| [] -> []
	| hd :: tl -> insert hd (sort tl)
and insert x = function
	| [] -> [x]
	| hd :: tl -> if x < hd then x :: hd :: tl else hd :: insert x tl
;;

sort [];;
sort [1];;
sort [1; 2];;
sort [2; 1];;
sort [4; 3; 2; 1];;
sort [2; 5; 4; 3; 1];;
