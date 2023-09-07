# Given an integer A, this program swaps the Bth and Cth bit from the right in the binary representation of A.
A=int(input())
B=int(input())
C=int(input())
x=(A>>(B-1))&1
y=(A>>(C-1))&1
if(x!=y):
    A^=(1<<(B-1))
    A^=(1<<(C-1))
print(A) 
