#include<stdio.h>
void main()
{
 int a[]={ 1,3,5,7,9,11,13,15,17,19,21,23,25 }, mid,l=0,u=13,s,flag=0;
 printf("\n Enter the element to search ");
 scanf("%d", &s);
 while( l<=u )
 {
    mid=(l+u)/2;
    if(a[mid]>s)
        u=mid-1;
    else if(a[mid]<s)
        l=mid+1;
    else
        {
	  printf("\n Element found at Index %d ",mid+1);
	  flag=1;
	  break;
	  }
}
if(flag==0)
  printf("\n Element Not found ");
  }
  
