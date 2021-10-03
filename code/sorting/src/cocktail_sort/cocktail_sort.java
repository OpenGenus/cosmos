/**
 * Implements the cocktail sort sorting algorithm
 */
public class CocktailSort {

	static void cocktailSort(int[] array) {
        boolean isSwapped = false;
        int back_index = array.length - 1;
        int front_index = 0;

        do {
            for(int i=0;i<back_index;i++) {
                if(array[i] > array[i+1]) {
                    int temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    isSwapped = true;
                }
            }  

            // check if no swap happens then array is sorted
            if(isSwapped == false) {
                break;
            }
            // Now last element of array is already in his right position so decrement last index
            back_index--;
            // Again assume that no swaps happened
            isSwapped = false;

            for(int i=(back_index-1);i>front_index;i--) {
                if(array[i] < array[i-1]) {
                    int temp = array[i];
                    array[i] = array[i-1];
                    array[i-1] = temp;
                    isSwapped = true;
                }
            }
            // Now first element of array is already in right place so increment first index
            front_index++;

        } while(isSwapped == true);
	}


	public static void main(String[] args) {
        int array[] = new int[] { 1, 2, 3, 4, 0, 1, 3, 6, -1, -2, 8, 9, 10, 5, 7 };

        //calls the cocktail sort function with parameter array
        cocktailSort(array);
        System.out.println("Sorted Array : ");
        for(int i : array) {
            System.out.print(i + " ");
        }
        System.out.println();
	}
}
