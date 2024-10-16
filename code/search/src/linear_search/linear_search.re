let rec linearSearch = x =>
  fun
  | [] => (-1)
  | [hd, ...tl] when hd === x => 0
  | [hd, ...tl] => 1 + linearSearch(x, tl);
