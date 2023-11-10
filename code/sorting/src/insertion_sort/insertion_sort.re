let rec sort =
  fun
  | [] => []
  | [hd, ...tl] => insert(hd, sort(tl))
and insert = x =>
  fun
  | [] => [x]
  | [hd, ...tl] =>
    if (x < hd) {
      [x, hd, ...tl];
    } else {
      [hd, ...insert(x, tl)];
    };
