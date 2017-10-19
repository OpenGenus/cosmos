function maxDigit(n){
  n= 0 | n ;
  var max=-1, remainder=-1;
  do {
    remainder = n % 10;
    max = (max > remainder ) ? max : remainder ;
    n=(n-remainder)*1e-1;
  } while (n!=0);
  return max;
}