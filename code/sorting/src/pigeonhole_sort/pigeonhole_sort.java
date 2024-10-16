/* Part of Cosmos by OpenGenus Foundation */

/* Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists 
of elements where the number of elements and the number of possible key values
are approximately the same. In principle, it resembles Counting Sort. 

While Counting Sort is a recursive algorithm, Pigeonhole Sort completes the sort
in a single iteration. It uses O(n) space and time.
*/



import java.util.ArrayList;

public class PigeonHoleSort {

	public static void pigeonholeSort(int[] arr, int n) {
		int min = arr[0];
		int max = arr[0];
		int range = 0;
		
		// Obtain the range of the elements, to set bounds for the #pigeonholes
		for(int i = 1;i<n;i++) {
			if(arr[i]>max)
				max = arr[i];
			else if(arr[i]<min)
				min = arr[i];
		}
		range = max-min+1;
		
		// For each value in the range, create one pigeonhole 
		ArrayList<Integer>[] holes = new ArrayList[range];
		for(int i = 0;i<range;i++) {
			holes[i] = new ArrayList<Integer>();
		}
		
		// Traverse the list to be sorted. Each element is places in the hole matching its value.
		for(int i = 0; i < n;i++) {
			holes[arr[i]-min].add(arr[i]);
		}
		
		// Repopulate the original array picking up elements from the pigeonholes in order
		int index = 0;
		for(int i = 0;i<range;i++) {
			for(int num : holes[i]) {
				arr[index++] = num;
			}
		}
	}
	
	public static void main(String args[]) {
        	int arr[] = {3, 5, 8, 5};
        	pigeonholeSort(arr, arr.length);
        	
        	for(int num : arr) {
        		System.out.println(num);
        	}
    	}
}
