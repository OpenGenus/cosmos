#include<stdio.h>
int main(){
int i,n,a[50],temp=-32768;
printf("\nEnter number of inputs:");
scanf("%d",&n);
printf("Enter %d values\n",n);
for (i = 0; i < n; i++)
{
	scanf("%d",&a[i]);
	if(a[i]>temp){
		temp=a[i];
	}
}
printf("Max value = %d\n",temp);
return 0;
}
