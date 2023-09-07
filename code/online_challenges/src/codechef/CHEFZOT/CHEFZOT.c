#include<stdio.h>

int main() 
{
    int n;
    scanf("%d", & n);
    int arr[n];
    int i;
    for (i = 0; i < n; ++i) 
    {
        scanf("%d", & arr[i]);
    }
    int flag = 0, c = 0;
    for (i = 0; i < n; ++i) 
    {
        for (; arr[i] != 0 && i < n; ++i) 
        {
            ++c;
        }
        if (flag < c) 
        {
            flag = c;
            c = 0;
        } else 
        {
            c = 0;
        }
    }
    printf("%d", flag);
}
