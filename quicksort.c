#include<bits/stdc++.h>
using namespace std;
int partition1(int a[],int l,int r)
{
   int temp,i;
    int pivot=a[r];
    int p=l;
    for(i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
           //swap(a[i],a[p])
           temp=a[i];
           a[i]=a[p];
           a[p]=temp;
            p++;
        }

    }
    //swap(a[p],pivot);
    temp=a[p];
    a[p]=a[r];
    a[r]=temp;
    return p;
}
void quicksort(int a[],int l,int r)
{
    if(l>=r)
        return;
    int p=partition1(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);

}

int main()
{
    int i,j,k,l,m,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

return 0;
}

