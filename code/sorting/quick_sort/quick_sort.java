// Part of Cosmos by OpenGenus Foundation
class QuickSort {
	int partition(int arr[], int low, int high) {
		int pivot = arr[high]; // last element is the pivot
		int i = (low - 1); 
		for (int j = low; j < high; j++) {
			if (arr[j] <= pivot) {	// if j'th element is less than or equal to the pivot
				i++;				// then swap the i'th element with the j'th element
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// swap arr[i+1] and arr[high] (or pivot)
		int temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;

		return i + 1;	// return position of the pivot
	}

	void sort(int arr[], int low, int high) {
		if (low < high) {
			// after the following function call elemnt at positon pi
			// is at it's correct poition in the sorted array
			int piv = partition(arr, low, high);
			sort(arr, low, piv - 1);	// recursively sort
			sort(arr, piv + 1, high);	// rest of the array
		}
	}

	static void printArray(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; ++i) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String args[]) {
		int arr[] = {5, 7, 11, 56, 12, 1, 9};
		int n = arr.length;

		QuickSort qso = new QuickSort();
		qso.sort(arr, 0, n - 1);

		System.out.println("sorted array");
		printArray(arr);
	}
}
