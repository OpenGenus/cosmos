// Part of Cosmos by OpenGenus Foundation

#include<stdio.h>

int hash_fn(int k, int i)
{
    int h1,h2;
    h1 = k % 9;
    h2 = k % 8;
    return ((h1 + (i*h2))% 9);
}

void insert(int arr[])
{
    int k,i=1,id;
    printf("Enter the element \n");
    scanf("%d",&k);
    id = k % 9;
    while(arr[id]!=-1)
    {
        id = hash_fn(k,i);
        i++;
    }
    arr[id] = k;    
}

void search(int arr[])
{
    int q;
    printf("Enter query\n");
    scanf("%d",&q);
    int id = q % 9 , i;
    for(i=0;i<9;i++)
    {
        if(arr[id] == q)
        {
            printf("Found\n");
            break;
        }
    }
    printf("Not Found\n");
}

void display(int arr[])
{
    int i ;
    for (i=0;i<9;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[9],i;
    for(i =0;i<9;i++)
    {
        arr[i] = -1;
    }

    for(i=0;i<9;i++)
    {
        insert(arr);
    }
    display(arr);
    search(arr);
}
