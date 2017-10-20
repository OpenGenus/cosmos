/* Part of Cosmos by OpenGenus Foundation */

import java.util.Arrays;

/**
 * Implements the bubble sort sorting algorithm
 */
public class BubbleSort {

	static void bubbleSort(int[] array) {
		int flag = 1;
		for (int i = 0; i < array.length - 1; i++) {
			flag = 1;
			for (int j = 0; j < array.length - 1; j++) {
				if(array[j] > array[j + 1]) {
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					flag = 0;
				}
			}
			if (flag == 1) {
				break;
			}
		}
	}


	public static void main(String[] args) {
		int array[] = { 4, 2, 3, 1 };
		bubbleSort(array);
		System.out.println("Sorted array: ");
		System.out.println(Arrays.toString(array));
	}
}
