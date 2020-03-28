/*
    Pancake Sorting Algorithm
*/

#include <stdio.h>

// Print the sorted array

    void print_ans (int a[] , int n)
{
        printf("Sorted Array\n");
    
        for(int i = 0 ; i < n ; ++i)
      {
            printf("%d ",a[i]);   
      }
}

  // finding the index of largest number in the given array size

    int find_index (int a[] , int size)
{
        int max = 0;
    
        for(int i = 1 ; i < size ; ++i)
    {
            if( a[i] > a[max] )
          {
                max = i;
          }
    }
        return max;   
}

  // Reversing the array from 0 to index

    void flip_arr(int a[], int index)
{
        int begin = 0;
    
        while( begin < index )
    {
            int temp = a[begin];
            a[begin] = a[index];
            a[index] = temp;
       
            ++begin;
            --index;
    }
}

    void pancake_sort(int a[] ,int n)
{
        int max_i;
    
        for(int cur_size = n ; cur_size > 1 ; --cur_size )
    {
             max_i = find_index(a, cur_size);
    
             if(max_i != cur_size-1)
        { 
                flip_arr(a, max_i);
        
                flip_arr(a, cur_size-1);
        }
    }    
}

    int main()
{
        int n;
    
        scanf("%d",&n);
    
        int arr[n];
    
        for(int i = 0 ; i < n ; ++i)
     {
            scanf("%d",&arr[i]);
     }
        pancake_sort(arr,n);
    
        print_ans(arr,n);
    
        return 0;
  }

/*
    __INPUT__
    
    n-->6
    arr:5 9 4 8 1 6
    
    __OUTPUT__
    
    Sorted Array
    1 4 5 6 8 9
    
*/    
