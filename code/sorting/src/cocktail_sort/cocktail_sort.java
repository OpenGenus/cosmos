class CocktailSort {
    /** A method to sort the array. The array will be sorted inplace. 
    * @author KanakalathaVemuru (https://github.com/KanakalathaVemuru)
    * @param array an array which has to be sorted
    */
    public void sort(int[] array) {
        int n = array.length;

        int left = 0;
        int right = n - 1;

        Boolean swapped = true;

        while (swapped) {
            swapped = false;

            for (int i = left; i < right; i++) {
                if (array[i] > array[i + 1]) {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    swapped = true;
                }
            }

            if (swapped == false) {
                break;
            }

            right = right - 1;
            for (int i = right - 1; i >= left; i--) {
                if (array[i] > array[i + 1]) {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    swapped = true;
                }
            }

            left = left + 1;
        } 
    }

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Given Array");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        CocktailSort cs = new CocktailSort();
        cs.sort(arr);

        System.out.println("\nSorted array");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}