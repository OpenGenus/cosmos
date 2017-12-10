/*
  Part of Cosmos by OpenGenus Foundation
  This is a C program that forms a max heap.
  The following queries can be used:
  0 - Print the max-heap
  1 - Heapsort, then print the sorted array
  2 [element] - Insert element into max-heap, then print the heap
  3 - Remove/extract maximum element in max-heap, then print the heap
  4 - Print maximum element of max-heap 
*/

# include <stdio.h>
  int n = 0; // global variable for maintaining the sixe of the heap
  int size = 0; // global array used for heapsort

/*
  The function down() is used for building the heap
  and for deleting the maximum element from the heap
  The parameters are:
  1. pos - index of the element to be inserted
  2. val - value to be compared with
  3. heap - the heap array
*/
int down(int pos, int val, int heap[n])
{
  int target = 0;
  while(2*pos<=n)
  {
    int left = 2*pos;
    int right = left + 1;
    if(right<=n && heap[right]>heap[left])
    {
      target = right;
    }
    else
    {
      target = left;
    }
    if(heap[target]>val)
    {
      heap[pos] = heap[target];
      pos = target;
    }
    else
    {
      break;
    }
  }
  return pos;
}

/*
  The function down2() is used for heapsort's
  delete functinality
  The parameters are:
  1. pos - index of the element to be inserted
  2. val - value to be compared with
  3. heap - the heap array
*/
int down2(int pos, int val, int heap[size])
{
  int target = 0;
  while(2*pos<=size)
  {
    int left = 2*pos;
    int right = left + 1;
    if(right<=size && heap[right]>heap[left])
    {
      target = right;
    }
    else
    {
      target = left;
    }
    if(heap[target]>val)
    {
      heap[pos] = heap[target];
      pos = target;
    }
    else
    {
      break;
    }
  }
  return pos;
}

/*
  The function buildheap() is used for constructing
  the max heap which uses the percolatedown method
  The parameters are:
  1. heap - the heap array
*/
void builheap(int heap[n])
{
  for(int i = n/2 ; i>0 ; i--)
  {
    int node = heap[i];
    int position = percolatedown(i, heap[i], heap);
    heap[position] = node;
  }
}

/*
  The function printheap() is used for printing
  the max heap
  The parameters are:
  1. heap - the heap array
*/
void printheap(int heap[n])
{
  for(int i = 1 ; i<=n ; i++)
  {
    printf("%d ", heap[i]);
  }
}

/*
  The function deletemax is used for deleting
  the maximum element from the heap
  The parameters are:
  1. heap - the heap array
*/
void deletemax(int heap[n])
{
  int newpos = down(1, heap[n+1], heap);
  heap[newpos] = heap[n+1];
}

/*
  The function deletemax2 is used for deleting
  the maximum element from the heap
  The parameters are:
  1. heap - the heap array
*/
void deletemax2(int heap[size])
{
  int newpos = down2(1, heap[size+1], heap);
  heap[newpos] = heap[size+1];
}

/*
  The function heapsort() is used for sorting
  the heap array
  The parameters are:
  1. heap - the heap array
  2. arr - it stores the sorted elements of the heap
*/
void heapsort(int heap[n+1], int arr[n+1])
{
  size = n;
  int heapsortarr[100];
  for(int i = 1 ; i<=n ; i++)
  {
    heapsortarr[i] = heap[i];
  }
  for(int i = 1 ; i<=n ; i++)
  {
    arr[n-i+1] = heapsortarr[1];
    size--;
    deletemax2(heapsortarr);
  }
}

int main()
{
  scanf("%d", &n);
  int heaparr[100];
  for(int i = 0 ; i<n ; i++)
  {
    scanf("%d", &heaparr[i+1]);
  }
  builheap(heaparr);
  int t = 0;
  scanf("%d", &t);
  for(int j = 0 ; j<t ; j++)
  {
    int q = 0;
    scanf("%d", &q);
    if(q==0)       // Print the max-heap
    {
      printheap(heaparr);
      printf("\n");
    }
    else if(q==1) // Heapsort, then print the sorted array
    {
      int arr[n+1];
      heapsort(heaparr, arr);
      printheap(arr);
      printf("\n");
    }
    else if(q==2) // Insert element into max-heap, then print the heap
    {
      int a = 0;
      scanf("%d", &a);
      n++;
      heaparr[n] = a;
      builheap(heaparr);
      printheap(heaparr);
      printf("\n");
    }
    else if(q==3) // Remove/extract maximum element in max-heap, then print the heap
    {
      n--;
      deletemax(heaparr);
      printheap(heaparr);
      printf("\n");
    }
    else if(q==4) // Print maximum element of max-heap
    {
      printf("%d\n", heaparr[1]);
    }
  }
}
