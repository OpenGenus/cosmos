#include<stdio.h>
/*Function for bubble sort*/
int 
bubblesort(int n,int a[n])
{
int i, j, temp;
for(i=0; i<n-1; i++)
{
    for(j=0; j<n-i-1; j++)
    {
        if( a[j] > a[j+1])
        {
        temp = a[j]; 
        a[j] = a[j+1];
        a[j+1] = temp;
        }}} 
        printf("\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
 
}
/*main program*/
int main(){
    int n;
    printf("Enter number of elements in an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(n,a);
    return (0);
}
