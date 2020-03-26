/*
   Pancake Sorting Algorithm
*/
using System; 

class GFG { 

    // Print the sorted Array

    	static void print_ans(int[] a,	int n) 
	{ 
	    	Console.Write("Sorted Array\n"); 
	    
		for (int i = 0; i < n; ++i) 
			Console.Write(a[i] + " "); 
			
		Console.Write(""); 
	} 

 // Reversing the array from 0 to index
	
	static void flip_arr(int[] a, int index) 
	{ 
		int temp, begin = 0; 
		while (begin < index) 
		{ 
			temp = a[begin]; 
			a[begin] = a[index]; 
			a[index] = temp; 
			
			++begin; 
			--index; 
		} 
	} 

	//  finding the largest number in given array size
	
	static int find_index(int[] a, int n) 
	{ 
		int  max=0; 
		for (int i = 0; i < n; ++i) 
			if (a[i] > a[max]) 
				max = i; 
				
		return max; 
	} 

	 
	
	static void pancake_sort(int[] a, int n) 
	{ 
		
		 
		for (int cur_size = n; cur_size > 1; --cur_size) 
		{ 
			int max_i = find_index(a, cur_size); 

			if (max_i != cur_size - 1) 
			{ 
				flip_arr(a, max_i); 

				flip_arr(a, cur_size - 1); 
			} 
		}
	} 

	public static int Main () 
	{ 
		int []arr = {5, 9, 4, 8, 1, 6}; 
		
		int n = arr.Length; 

		pancake_sort(arr, n); 
		
		print_ans(arr, n); 
		
		return 0;
	} 
} 
/*
    __INPUT__
    
    arr:5 9 4 8 1 6
    
    __OUTPUT__
    
    Sorted Array
    1 4 5 6 8 9
    
*/  

