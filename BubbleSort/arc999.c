#include<stdio.h>
int  main()
   {

         int a[10000],i,j,n,t;
         printf("Enter the no. of numbers to be sorted :");
         scanf("%d",&n);
         for(i=0;i<n;i++)
           {
              printf("Enter Elements:");
              scanf("%d",&a[i]);
           }
        for(i=0;i< n-1;i++)
          {
              for(j=0;j< n-i-1 ; j++)
                {
                       if(a[j]>a[j+1])
                         {
                            t=a[j];
                            a[j]=a[j+1];
                            a[j+1]=t;
                        }
                 }
         }
      printf("\nThe sorted numbers are :"); 
      for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    return 0;
 }
         
