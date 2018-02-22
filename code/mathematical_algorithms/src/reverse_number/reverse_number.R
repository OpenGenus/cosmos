library(Rcpp)
cppFunction('int Reverse_CPP(int x) {
  int reverse = 0;
  while(x != 0) {
        int remainder = x%10;
        reverse = reverse*10 + remainder;
        x/= 10;
    }
  return reverse ; 
}')

Reverse_CPP(1234)
# [1] 4321