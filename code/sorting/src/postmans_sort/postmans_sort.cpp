#include <stdio.h>
void arrange(int,int);
int array[100], array1[100];
int i, j, temp, max, count, maxdigits = 0, c = 0;
 
int main()
{
    int t1, t2, k, t, n = 1;
 	printf("Enter size of array :");
    scanf("%d", &count);
    printf("Enter elements into array :"); 
    // inputing array elements
    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
        array1[i] = array[i];            
    }
    //determining significant digits in all the elements
    for (i = 0; i < count; i++) 
    {
        t = array[i];        
        while(t > 0)
        {
            c++;
            t = t / 10;        
        }
        //maximium significant digits
        if (maxdigits < c) 
            maxdigits = c;  
        c = 0;
    }
    //setting the base
    while(--maxdigits) 
        n = n * 10;      
 
    // elements arranged on the  basis of MSD
    for (i = 0; i < count; i++)
    {
        max = array[i] / n;        
        t = i;
        for (j = i + 1; j < count;j++)    
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;   
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }
    //elements arranged according to the next MSD
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
                arrange(i, j);
            i = j;
        }
        n = n / 10;
    }
    printf("\nSorted Array (Postman sort) :");    
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
    printf("\n");
    return 0;
}
// function to arrange the intergers having same bases
void arrange(int k,int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

