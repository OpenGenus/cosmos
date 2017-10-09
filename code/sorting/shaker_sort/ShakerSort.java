/* Part of Cosmos by OpenGenus Foundation */

public class ShakerSort {

	static void sort(int[] arr) {
		boolean swapped;
		int llim = 0;
		int rlim = arr.length - 1;
		int curr = llim;
		int tmp;

		while (llim <= rlim) {
			swapped = false;
			while (curr + 1 <= rlim) {
				if (arr[curr] > arr[curr + 1]) {
					tmp  = arr[curr];
					arr[curr] = arr[curr + 1];
					arr[curr + 1] = tmp;
					swapped = true;
				}
				curr += 1;
			}
			if (!swapped){
				return;
			}
			rlim -= 1;
			curr = rlim;
			swapped = false;
			while (curr - 1 >= llim) {
				if (arr[curr] < arr[curr - 1]) {
					tmp  = arr[curr];
					arr[curr] = arr[curr - 1];
					arr[curr - 1] = tmp;
					swapped = true;
				}
				curr -= 1;
			}
			if (!swapped){
				return;
			}
			llim += 1;
			curr = llim;
		}
	}


	public static void main(String[] args) {
		int[][] testCases = {
			{},
			{1},
			{1, 2},
			{2, 1},
			{1, 2, 3},
			{3, 1, 2},
			{4, 3, 2, 1},
			{4, 5, 2, 1, 3},
			{2, 2, 3, 3, 1, 3},
		};
		for (int[] arr : testCases) {
			sort(arr);
			for (int a : arr)
				System.out.print(a + " ");
			System.out.println();
		}
	}
}


