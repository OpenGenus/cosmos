#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
static int binsrch_geq(const int *arr, int n, int val)
{
    register int low, high, mid;
    int geq;
 
    low=0;
    high=n-1;
    geq=-1;
 
    /* binary search for finding the element with value val */
    while(low<=high)
    {
        mid=(low+high)>>1; //(low+high)/2;
        if(val<arr[mid])
        {
            high=mid-1;
            geq=mid;
        }
        else if(val > arr[mid])
            low=mid+1;
        else
            return mid; /* found */
    }
 
    return geq; /* not found */
}
 
int fibsrch(const int *arr, int n, int val)
{
    register int k, idx, offs;
    static int prevn=-1, prevk=-1;
 
    const static int Fib[47+1]= {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
                                 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
                                 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
                                 433494437, 701408733, 1134903170, 1836311903, INT_MAX
                                };
 
    /* find the smallest fibonacci number that is greater or equal to n. Store this
     * number to avoid recomputing it in the case of repetitive searches with identical n.
     */
    if(n!=prevn)
    {
#if 1
        k=(n>1)? binsrch_geq(Fib, sizeof(Fib)/sizeof(int), n) : 1;
#else /* the above binary search call can be substituted by the following code fragment: */
        {
            register int f0, f1, t;
 
            for(f0=0, f1=1, k=1; f1<n; t=f1, f1+=f0, f0=t, ++k)
                ;
        }
#endif
        prevk=k;
        prevn=n;
    }
    else k=prevk;
 
    /* If the sought value is larger than the largest Fibonacci number less than n,
     * care must be taken top ensure that we do not attempt to read beyond the end
     * of the array. If we do need to do this, we pretend that the array is padded
     * with elements larger than the sought value.
     */
    for(offs=0; k>0;  )
    {
        idx=offs+Fib[--k];
 
        /* note that at this point k  has already been decremented once */
        if(idx>=n || val<arr[idx]) // index out of bounds or val in 1st part
            continue;
        else if (val >arr[idx])  // val in 2nd part
        {
            offs=idx;
            --k;
        }
        else // val==arr[idx], found
            return idx;
    }
 
    return -1; // not found
}
 
int main()
{
    int data[]= {1, 4, 5, 7, 9, 11, 13, 16, 18, 20, 25, 27, 30, 32, 33, 36, 39, 41, 44, 47, 51, 53, 55};
    int i, x, n;
 
    x = 30;
    n = sizeof(data)/sizeof(int);
    i = fibsrch(data, n, x);
    if(i>=0)
        printf("%d found at index %d\n", x, i);
    else
        printf("%d was not found\n", x);
 
    return 0;
}
