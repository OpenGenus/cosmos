
#include<stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
 
    printf ("Following activities are selected n");

    i = 0;
    printf("%d ", i);
 
    for (j = 1; j < n; j++)
    {
      
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}
 
int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}