/*
    Pancake Sorting Algorithm
*/
#include <iostream>
#include <vector>

// Print the sorted array

    void print_ans ( std::vector<int>& v , int n)
{
        std::cout<<"Sorted Array\n";
    
        for( int i=0 ; i < n ; ++i)
       {
            std::cout<< v[i] <<" ";  
       }
}

// finding the index of largest number in the given array size

    int find_index ( std::vector<int>& v , int size)
{
        int max = 0;
    
        for(int i = 1 ; i < size ; ++i)
     {
            if( v[i] > v[max] )
          {
                max = i;
          }
     }
        return max;   
}

// Reversing the array from 0 to index

    void flip_arr ( std::vector<int> v , int index )
{
        int begin = 0 ;
    
        while (begin < index)
      {
            int temp = v[begin];
            v[begin] = v[index];
            v[index] = temp;
       
            ++begin;
            --index;
       }
}

    void pancake_sort( std::vector<int> v , int n)
{
        int max_i;
    
        for(int cur_size = n ; cur_size>1 ; --cur_size )
    {
            max_i = find_index(v,cur_size);
    
            if(max_i != cur_size-1)
           {  
                flip_arr(v,max_i);
        
                flip_arr(v,cur_size-1);
            }
     }
}

    int main()
{
        int n;
    
        std::cin>>n;
    
        std::vector<int> vect;
    
        for(int i = 0 ; i < n ; ++i)
       {
            std::cin>>vect[i];
       }
        pancake_sort(vect,n);
    
        print_ans(vect,n);
    
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
