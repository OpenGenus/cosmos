/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h> //Built in Library

int
main()
{
    int n, i, j, min, temp; //Initialization of variables
    
    printf("\n Enter the number of Elements: ");  //Printf function
    scanf("%d",&n); //Taking input from user
    int a[n];
    printf("\n Enter the %d Elements: ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]); //Taking input from user
     
    for (i = 0; i < n - 1; i++) //For loop till n-1
    {
        min = i;
        for (j = i + 1; j < n; j++)   //For loop till n
        {
            if (a[min] > a[j])  //condition to check if element is greater than min
                min = j;
        }
        if (min != i)   //Condition to check if min is not equal to i
        {
            temp = a[i];   //swap using  a variable  temp
            a[i] = a[min];
            a[min] = temp;
        }
    }
     
    printf("\n The Sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return (0);
}
