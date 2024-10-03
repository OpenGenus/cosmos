class SelectionSort {
    void sort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {	// iterate over the array
            int min_idx = i;
            for (int j = i+1; j < n; j++) {	// find the minimum element starting from the i'th element
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Swap the found minimum element with the i'th element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
 
    void printArray(int arr[]) {
        for (int i = 0; i < arr.length; ++i) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
 
    public static void main(String args[]) {
        SelectionSort sob = new SelectionSort();	// create object
        int arr[] = {64, 25, 12, 22, 11};
        sob.sort(arr);								// call method
        System.out.println("Sorted array");
        ob.printArray(arr);							// print sorted array
    }
}
