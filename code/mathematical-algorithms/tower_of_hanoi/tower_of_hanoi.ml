(* Part of Cosmos by OpenGenus Foundation *)

let tower_of_hanoi n =
	let rec move n from dest other =
		if n <= 0 then () else (
		move (n-1) from other dest;
		print_endline (from ^ " -> " ^ dest);
		move (n-1) other dest from)
	in
	move n "L" "R" "C"
;;

tower_of_hanoi 5;;
