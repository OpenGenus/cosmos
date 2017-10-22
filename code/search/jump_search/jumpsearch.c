#include <stdio.h>
#include <math.h>
#define MAX 100
int find_element(int element);
int arr[MAX],n;
int main()
{

   int i,element,result;
   printf("\nEnter the number of elements: ");
   scanf("%d",&n);
   printf("\nEnter the elements of array: \n");
   for(i=0;i<n;i++)
   {
         scanf("%d",&arr[i]);
   }
      printf("\n\nEnter the element you want to search: ");
      scanf("%d",&element);
      result=find_element(element);
      if(result==-1)
      {
            printf("\nElement is not found in the array !\n");
      }
      else
      {
            printf("\nElement %d is present at position %d",element,result);
      }
      return 0;
}
int find_element(int element)
{
   int jump_step,prev=0;
   jump_step=floor(sqrt(n));

   /* Finding block in which element lies, if it is present */

   while(arr[prev]<element)
   {
       if(arr[jump_step]>element || jump_step>=n)
       {
            break;
       }
       else
       {
                prev=jump_step;
                jump_step=jump_step+floor(sqrt(n));
       }
   }

   /*Finding the element in the identified block */

   while(arr[prev]<element)
   {
        prev++;
   }

   if(arr[prev]==element)
   {
        return prev+1;
   }
   else
   {
        return -1;
   }

}
