//  divide conquer | inversion count | C
//  Part of Cosmos by OpenGenus Foundation

#include <stdlib.h>
#include <stdio.h>


int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}


int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {

    mid = (right + left)/2;


    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);


    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}


int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];


      inv_count = inv_count + (mid - i);
    }
  }


  while (i <= mid - 1)
    temp[k++] = arr[i++];


  while (j <= right)
    temp[k++] = arr[j++];


  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}


int main(int argc, char** argv)
{
  printf("Number of elements in array : ");
  int n;
  scanf("%d", &n);
  int arr[n];
  printf("elements in array:\n");
  for (int x=0; x<n; x++)
  {
    scanf("%d", &arr[x]);
  }
  printf("Number of inversions are %d \n", mergeSort(arr, n));
  getchar();
  return 0;
}
