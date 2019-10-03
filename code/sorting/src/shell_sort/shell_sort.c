#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
void shell_sort(int *a, int n)
{
  int i, j, gap, temp;

  /* Assess the array in gaps starting at half the array size - Each gap is a sublist of 2 values */
  for(gap = n/2 ; gap > 0 ; gap /= 2)
  {
    /* Index at the right value of each gap */
    for(i = gap ; i < n ; i++)
    {
      /* Take a copy of the value under inspection */
      temp = a[i];
      for(j = i ; j >= gap ; j-= gap)
      {
        /* Compare the values in the sub lists and swap where necessary */
        if(temp < a[j-gap])
          a[j] = a[j-gap];
        else
          break;
      }
      a[j] = temp;
    }
  }
}

int main(void)
{
  int i;
  int a[10] = { 5 , 211 , 66 , 7 , 12 , 2, 76 , 134 , 99 , 9 };

  printf("In: ");
  for(i = 0 ; i < 10 ; i++)
  {
    printf("%d ", a[i]);
  }
  shell_sort(a, 10);
  printf("\nOut: ");
  for(i = 0 ; i < 10 ; i++)
  {
    printf("%d ", a[i]);
  }

  return 0;
}
