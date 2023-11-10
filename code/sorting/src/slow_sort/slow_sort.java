import java.util.Arrays;

public class slow_sort {
	/*
	 * Function that implements the slow sort algorithm
	 * @param arr[]    Array of elements
	 * @param i        Recursion leftmost index
	 * @param j        Recursion rightmost index
	 */
	static void slowSort(int arr[], int i, int j)
	{
	    if (i >= j) { // Return on base case
	    	return;
	    }
	    int mid = (i + j) / 2; // Calculate midpoint of i and j
	    // Recursively find maximum with left half
	    slowSort(arr, i, mid);
	    // Recursively find maximum with right half
	    slowSort(arr, mid + 1, j);
	    if (arr[j] < arr[mid]){ // Swap to keep maximum at end of the array
	    	int temp = arr[j];
	        arr[j] = arr[mid];
	        arr[mid] = temp;
	    }
	    // Recursive call excluding the last element
	    slowSort(arr, i, j - 1);
	}
	/*
     * Main method to test slow sort method
     */
	public static void main(String[] args)
	{
	    int arr[] = {2, 3, 1, 8, 9, 4, 2, 7, 3};
	    int N = arr.length;
	    slowSort(arr, 0, N - 1);
	    System.out.println(Arrays.toString(arr));
	}
}
