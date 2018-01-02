    /* Part of cosmos by OpenGenus Foundation  */

    /*
    * bogo_sort.c
    * created by Riya
    */

    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int num[]= {3,6,1,8,2,9,5,4,0,7};
        int i;    
        
        bogosort(num, s);
             printf("The array after sorting is:");
             for (i = 0;i < s;i++)  {
                    printf("%d\n", num[i]);
             }   printf("\n");
    }
     
    int is_sorted(int *a, int n)
    {
        while ( --n >= 1 )  {
            if ( a[n] < a[n-1] ) return 0;
        }  return 1;
    }

    void shuffle(int *a, int n)
    {
        int i, t, temp;
        for (i = 0;i < n;i++)   {
            t = a[i];
            temp = rand() % n; 
            a[i] = a[temp];
            a[temp] = t;
        }
    }

    void bogosort(int *a, int n)
    {
        while ( !is_sorted(a, n) ) 
            shuffle(a, n);
    }
