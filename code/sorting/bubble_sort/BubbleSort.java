
public class BubbleSort {

	static void bubbleSort(int [] array) {
		for (int i = 0; i < array.length-1; i++) {
			for (int j = 0; j < array.length-1; j++) {
				if(array[j] > array[j+1]) {
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
	
	
	public static void main(String[] args) {
		int array[] = {4,2,3,1};
		bubbleSort(array);
		System.out.println("Sorted array: ");
		for (int i = 0; i < array.length; i++) {
			
			if (i != array.length-1) {
				System.out.print(array[i]+", ");
			} else {
				System.out.println(array[i]);
			}
		}
	}
}
