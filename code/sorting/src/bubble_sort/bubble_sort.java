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
				//check if current element is greater than the next element
				if(array[j] > array[j + 1]) { 
					//if condition is satisfied, swap the elements
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					//set flag to 0
					flag = 0;
				}
			}
			
			//if the flag is still 1, it means the array is sorted 
			//and we exit from the loop.
			if (flag == 1) {
				break;
			}
		}
	}


	public static void main(String[] args) {
		int array[] = { 4, 2, 3, 1 };
		//calls the bubblesort function with parameter array
		bubbleSort(array);
		System.out.println("Sorted array: ");
		//Prints the sorted array
		System.out.println(Arrays.toString(array));
	}
}

