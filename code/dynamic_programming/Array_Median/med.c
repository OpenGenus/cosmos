#include<stdio.h>

#define N 10                                                
                                                               
  int main( )                                                     
   {                                                           
       int i,j,n;                                              
       float median,a[N],t;                                    
                                                               
       printf("Enter the number of items\n");                  
       scanf("%d", &n);                                        
    /* Reading items into array a  */
 
       printf("Input %d values \n",n);                         
       for (i = 1; i <= n ; i++)                               
           scanf("%f", &a[i]);                                 
    /* Sorting begins */
for (i = 1 ; i <= n-1 ; i++)                            
       {     /* Trip-i begins  */
for (j = 1 ; j <= n-i ; j++)                         
          {                                                    
              if (a[j] <= a[j+1])                              
              { /* Interchanging values */
                     
                t = a[j];                                      
                a[j] = a[j+1];                                 
                a[j+1] = t;                                    
              }                                                
              continue ;                                     
          }                                                    
       } /* sorting ends */
/* calculation of median  */
if ( n % 2 == 0)                                        
          median = (a[n/2] + a[n/2+1])/2.0 ;                   
       else                                                    
          median = a[n/2 + 1];                                 
                                                               
    /*  Printing */
for (i = 1 ; i <= n ; i++)                              
           printf("%f  ", a[i]);                               
       printf("\n\nMedian is %f\n", median);                   
                                                               
   }    
                        
