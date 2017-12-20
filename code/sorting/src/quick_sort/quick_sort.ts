// Part of Cosmos by OpenGenus Foundation
function quicksort(A: number[]): number[]  {
 
  let stack = [{ lo: 0, hi: A.length - 1 }];
 
  while (stack.length > 0) {
 
    let { lo, hi } = stack.pop();
    if (lo >= hi) {
      continue;
    }
 
    let pivot = A[lo];
    let i = lo;
    let j = hi;
    let p: number;
 
    while (true) {
 
      while (A[i] <= pivot && i <= j) { i++; }
      while (A[j] >= pivot && j >= i) { j--; }
 
      if (j <= i) {
        let tmp = A[lo];
        A[lo] = A[j];
        A[j] = A[lo];
        p = j;
        break;
      }
 
      let tmp = A[i];
      A[i] = A[j];
      A[j] = A[i];
 
      i++;
      j--;
    }
    stack.push({ lo: lo, hi: p - 1});
    stack.push({ lo: p + 1, hi: hi });
  }
 
  return A;
}
