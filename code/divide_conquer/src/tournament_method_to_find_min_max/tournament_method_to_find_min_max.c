#include<stdio.h>

struct pair
{
  int min;
  int max;
};  
 
struct pair 
getMinMax(int arr[], int low, int high)
{
  struct pair minmax, mml, mmr;       
  int mid;

  if (low == high) {
     minmax.max = arr[low];
     minmax.min = arr[low];     
     return (minmax);
  }    

  if (high == low + 1) {
     if (arr[low] > arr[high]) {  
        minmax.max = arr[low];
        minmax.min = arr[high];
     }  
     else {
        minmax.max = arr[high];
        minmax.min = arr[low];
     }  
     return (minmax);
  }

  mid = (low + high) / 2;  
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid + 1, high);  

  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;     

  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;     
  
  return (minmax);
}

int 
main()
{
  int arr_size;
  printf("Enter size of the Array: \n");
  scanf("%d", &arr_size);
  int arr[arr_size];
  printf("Enter %d Integers:- \n", arr_size);
  int i;
  for (i = 0; i < arr_size; ++i)
    scanf("%d", &arr[i]);

  struct pair minmax = getMinMax(arr, 0, arr_size - 1);
  printf("Minimum element is %d \n", minmax.min);
  printf("Maximum element is %d \n", minmax.max);
  
  return (0);
}
