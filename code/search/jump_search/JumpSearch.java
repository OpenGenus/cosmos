

public class JumpSearch {
	// Java program to implement Jump Search.
	public static int SearchJump(int[] arr, int x) {
		int n = arr.length;

		// block size through which jumps take place
		int step = (int) Math.floor(Math.sqrt(n));

		// search in the block
		int prev = 0;
		while (arr[Math.min(step, n) - 1] < x) {
			prev = step;
			step += (int) Math.floor(Math.sqrt(n));
			if (prev >= n)
				return -1;
		}

		// Doing a linear search for x in block

		while (arr[prev] < x) {
			prev++;

			/*
			 * If we reached next block or end of array, element is not present.
			 */
			if (prev == Math.min(step, n))
				return -1;
		}

		// If element is found
		if (arr[prev] == x)
			return prev;
		// element not found
		return -1;
	}

	// Driver program to test function
	public static void main(String[] args) {
		int arr[] = { 0, 1, 1, 2, 3, 5, 9, 13, 21, 34, 55, 89, 145, 237, 377, 610 };
		int x = 55;

		// Find the index of 'x' using Jump Search
		int index = SearchJump(arr, x);

		// Print the index where 'x' is located
		if (x != -1)
			System.out.println("Number " + x + " is found at index " + index);
		else {
			System.out.println("Number " + x + " not found");
		}

	}
}
