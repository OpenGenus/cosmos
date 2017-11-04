#include <stdio.h>
int main()
{
    int n , max , tmp;
    printf("Enter numbers of elements : ");
    scanf("%d",&n);
    printf("Enter numbers\n");
    scanf("%d",&tmp);
    max = tmp;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d",&tmp);
        if (max<tmp)
        {
            max = tmp;
        }
    }
    printf("Maximum is %d\n",max);
    return 0;
}
