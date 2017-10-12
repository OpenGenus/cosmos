// Part of Cosmos by OpenGenus Foundation //
using System;
using System.Collections.Generic;

public class Program
{
	//Main entrypoint and test setup
	public static void Main()
	{
		int[] arr = new int[] {12, 11, 6, 2, 16, 7, 9, 18};
		
    	PigeonholeSort(ref arr);
		
    	Console.Write("Sorted order is: ");
    	for (int i = 0; i < arr.Length; i++)
      		Console.Write(arr[i] + " ");
	}						  
	
	// PigeonholeSort - Sorts the array using the pigeonhole algorithm.
	// ref int[] arr - Pass a reference to an integer array to be sorted.
	public static void PigeonholeSort(ref int[] arr)
    {
		// Initialise min and max to the same value
		int min = arr[0];
		int max = arr[0];
		
		// Then get the min and max values of the array
		for (int i = 1; i < arr.Length; i++)
		{
		    if (arr[i] < min)
		      min = arr[i];
		    if (arr[i] > max)
			  max = arr[i];
		}
		// Range is our total valuespace
		int range = max - min + 1;
		
		// Create our array of lists, and initialise them
		List<int>[] holes = new List<int>[range];
		for(int i = 0; i < holes.Length; i++) { holes[i] = new List<int>(); }
		
		// For every value in the array, put it in the corresponding pigeonhole
		for (int i = 0; i < arr.Length; i++)
		    holes[arr[i]-min].Add(arr[i]);
		
		// Finally, replace the values in the array with the values from each
		// pigeonhole in order
		int index = 0;
		for (int i = 0; i < range; i++)
		{
		    for (int j = 0; j < holes[i].Count; j++)
		        arr[index++] = holes[i][j];
		}
	}
}