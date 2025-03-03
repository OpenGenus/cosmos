using System;

public class InsertionSort
{
	public static void Main()
	{
	        int[] arr = new int[6] { 26, 19, 4, 50, 85, 1 } ;
	        int i;
	        insertsort(arr, 6);
	        Console.WriteLine("The Sorted Array is :");
	        for (i = 0; i < 6; i++)
	            Console.WriteLine(arr[i]); 
	        Console.ReadLine();
	}        
	static void insertsort(int[] data, int n)
	{
	        int i, j;
	        for (i = 1; i < n; i++)
	        {
	            int item = data[i];
	            int ins = 0;
	            for (j = i - 1; j >= 0 && ins != 1; )
	            {
	                if (item < data[j])
	                {
	                    data[j + 1] = data[j];
	                    j--;
	                    data[j + 1] = item;
	                }
	                else 
	                	ins = 1;
	            }
	        }
	}
}