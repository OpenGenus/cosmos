// Part of Cosmos by OpenGenus Foundation
function range(x) {
  var res = [];
  for (var i = 0; i < x; i++) {
    res.push(i);
  }
  return res;
}

function determinePrev(arr, idx) {
  return arr
    .filter(function(x) {
      return x.length > idx;
    })
    .map(function() {
      return 1;
    })
    .reduce(function(p1, p2) {
      return p1 + p2;
    }, 0);
}

function beadsort(arr) {
  var ref = arr.map(function(x) {
    return range(x);
  });
  var inter = [];
  var idx = 0;
  var prev = determinePrev(ref, idx);
  while (prev) {
    inter.push(range(prev));
    idx++;
    prev = determinePrev(ref, idx);
  }
  idx = 0;
  prev = determinePrev(inter, idx);
  var out = [];
  while (prev) {
    out.push(prev);
    idx++;
    prev = determinePrev(inter, idx);
  }
  return out.reverse();
}

console.log(beadsort([4, 1, 6, 2, 40, 5, 3, 8, 7]));
