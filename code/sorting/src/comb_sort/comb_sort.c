#include <stdio.h>

int
updateGap(int gap)
{
    gap = (gap * 10) / 13;
    
    return (gap < 1 ? 1 : gap);
}

void 
combSort(int ar[], int n)
{
    int gap = n;
    int flag = 0;
    while (gap > 1 || flag == 1) {
        gap = updateGap(gap);
        flag = 0;
        for (int i = 0; i < (n - gap); i++) {
            int x;
            if (ar[i] > ar[i + 1]) {
               x = ar[i];
               ar[i] = ar[i + 1];
               ar[i + 1] = x;
               flag = 1;
            }
        }
    }
}

int 
main()
{
    int n;
    printf("Enter size of Array \n");
    scanf("%d", &n);
    int ar[n];
    printf("Enter %d Integers \n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    combSort(ar, n);
    printf("Sorted Array:- \n");
    for(int i = 0; i < n; i++)
        printf("%d \n", ar[i]);

    return (0);
}