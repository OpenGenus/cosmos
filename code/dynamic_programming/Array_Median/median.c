#include <stdio.h>

void swap(float *p,float *q) {
   float t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(float a[],float n) { 
   int i,j;

   for(i=0;i<n-1;i++) {
      for(j=0;j<n-i-1;j++) {
         if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}

int main() {
	int i;
	int n;
	printf("please enter the size\n");
	scanf("%d",&n);
	float a[n];
	for(i=0;i<n;i++)
	{
		scanf("%f",&a[i]);
	}	
   /*float a[] = {6,3,8,5,1};
   float n = 5;
   float sum,i;*/

   sort(a,n);
   if(n%2==1)
   {
   
   n = (n+1) / 2 - 1;  // -1 as array indexing in C starts from 0

   printf("Median = %f ", a[n]);
	}
	else
	{
	 	n= n/2;
	 	//prfloatf("the m",a[]);
	 	float value = (a[n] + a[n-1])/2;
	 	printf("Median = %f",value);
	}

   return 0;
}
