/**
 * Utility class for sorting an array using Selection Sort algorithm. Selection
 * Sort is a basic algorithm for sorting with O(n^2) time complexity. Basic idea
 * of this algorithm is to find a local minimum, which is the minimum value from
 * (i+1) to length of the array [i+1, arr.length), and swap it with the current
 * working index (i).
 *
 * Part of Cosmos by OpenGenus Foundation
 */
class SelectionSort {

  /**
   * Example usage.
   */
  public static void main(String[] args) {
		int[] arr = { 1, 5, 2, 5, 2, 9, 7 };
		SelectionSort.sort(arr);
		System.out.print(java.util.Arrays.toString(arr));
	}

	/**
	 * Sort an array using Selection Sort algorithm.
	 *
	 * @param arr
	 *            is an array to be sorted
	 */
	public static void sort(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			int min = i;
			for (int j = i + 1; j < arr.length; j++) {
				/* find local min */
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			swap(arr, i, min);
		}
	}

	/**
	 * Utility method for swapping elements in an array.
	 *
	 * @param arr
	 *            is an array to be swapped
	 * @param i
	 *            is index of first element
	 * @param j
	 *            is index of second element
	 */
	private static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
