#include<iostream>
using namespace std;
int main() {
   int product[10][10], r1=3, c1=3, r2=3, c2=3, i, j, k;
   int a[3][3] = { {2, 4, 1} , {2, 3, 9} , {3, 1, 8} };
   int b[3][3] = { {1, 2, 3} , {3, 6, 1} , {2, 4, 7} };
   if (c1 != r2) {
      cout<<"Column of first matrix should be equal to row of second matrix";
   } else {
      cout<<"The first matrix is:"<<endl;
      for(i=0; i<r1; ++i) {
         for(j=0; j<c1; ++j)
         cout<<a[i][j]<<" ";
         cout<<endl;
      }
      cout<<endl;
      cout<<"The second matrix is:"<<endl;
      for(i=0; i<r2; ++i) {
         for(j=0; j<c2; ++j)
         cout<<b[i][j]<<" ";
         cout<<endl;
      }
      cout<<endl;
      for(i=0; i<r1; ++i)
      for(j=0; j<c2; ++j) {
         product[i][j] = 0;
      }
      for(i=0; i<r1; ++i)
      for(j=0; j<c2; ++j)
      for(k=0; k<c1; ++k) {
         product[i][j]+=a[i][k]*b[k][j];
      }
      cout<<"Product of the two matrices is:"<<endl;
      for(i=0; i<r1; ++i) {
         for(j=0; j<c2; ++j)
         cout<<product[i][j]<<" ";
         cout<<endl;
      }
   }
   return 0;
}
