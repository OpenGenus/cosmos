#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int li, int ri)
{
  int i= li, mid=(li+ri)/2, j=mid+1, k=0, b[ri-li+1];
  while(i<=mid && j<=ri)
  {
    if(a[i]<a[j])
      b[k++]=a[i++];
    else
      b[k++]=a[j++];
  }
  while(i<=mid)
    b[k++]= a[i++];
  while(j<=ri)
    b[k++]=a[j++];
  k=0;
  for(i=li; i<=ri; i++)
    a[i] = b[k++];
}

void merge_sort(int a[], int li,int ri)
{
  if(li>=ri)
    return;
  int mid=(li+ri)/2;
  merge_sort(a, li, mid);
  merge_sort(a, mid+1, ri);
  merge(a, li, ri);
}

int main()
{
   int n, front, end, total, k=0;
   scanf("%d", &n);
   int A[n], S[n];
   for(int i=0; i<n; i++)
       scanf("%d", &A[i]);
   merge_sort(A, 0, n-1);
   front=0; end=n-1;
   while(front<end)
   {
       S[k++]= A[front++];
       S[k++]= A[end--];
   }
   if(front == end)
       S[k]= A[front];
   for(int i=0; i<n; i++)
   {
       printf("%d ",S[i]);
       total+=abs(S[i] - S[(i+1)%n]);
   }
   printf("\n%d",total);
   return 0;
}