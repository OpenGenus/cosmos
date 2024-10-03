#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, front, end, total, k=0;
   cin>> n;
   vector<int> A(n), S(n);
   for(int i=0; i<n; i++)
       cin>> A[i];
   sort(A.begin(), A.end());
   front=0; end=n-1;
   while(front<end)
   {
       S[k]= A[front];
       k++;
       S[k]= A[end];
       k++; front++; end--;
   }
   if(front == end)
       S[k]= A[front];
   for(int i=0; i<n; i++)
   {
       cout<<S[i]<<" ";
       total+=abs(S[i] - S[(i+1)%n]);
   }
   cout<<"\n"<<total;
   return 0;
}