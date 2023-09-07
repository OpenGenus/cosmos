# Given an integer A, this program swaps the Bth and Cth bit from the right in the binary representation of A.
#include<bits/stdc++.h>
using namespace std;
int swap_bit(int A, int B, int C) {
    int b=(A>>(B-1))&1;
    int c=(A>>(C-1))&1;
    if(b==c){
        return A;
    }
    else{
        A^=(1<<(B-1));
        A^=(1<<(C-1));
        return A;
    }
}
int main(){
  int A;
  int B,C;
  cin>>A>>B>>C;
  A=swap_bit(A,B,C);
  cout<<A;
}
