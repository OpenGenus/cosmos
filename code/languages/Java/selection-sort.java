// Selection Sort Algorithm

// 1. Start with the first element as the initial position of the sorted 
//    portion.
// 2. For each unsorted portion of the array, find the smallest element.
// 3. Swap this smallest element with the first element of the unsorted
//    portion.
// 4. Move the boundary between the sorted and unsorted portions one element
//    forward.
// 5. Repeat the previous steps until the entire array is sorted, as desired.

class selection_sort {

    /**
     * Selection Sort for array of ints.
     */
    static void selection_sort_int(int[] arr){
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            // Assume the current position has the smallest element
            // The outer loop runs until index (n-2) because once the 
            //  second-to-last element is sorted, the last element will 
            //  automatically be in the correct position as the largest element.
            int min_idx = i;

            // Iterate through unsorted portion to find the actual smallest item.
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    // Update min_idx if a smaller element is found
                    min_idx = j;
                }
            }
            // If a new minimum is found, swap it with the element at index i
            if (min_idx != i) {
                int temp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = temp;
            }
        }
    }

    /**
     * Selection Sort for array of strings.
     */
    static void selection_sort_str(String[] arr) {
        int n = arr.length;
    
        for (int i = 0; i < n - 1; i++) {
            // Assume the current position has the smallest string
            int min_idx = i;
    
            // Iterate through the unsorted portion to find the actual smallest string.
            for (int j = i + 1; j < n; j++) {
                // Use compareTo to compare strings
                if (arr[j].compareTo(arr[min_idx]) < 0) {
                    // Update min_idx if a smaller string is found
                    min_idx = j;
                }
            }
    
            // If a new minimum is found, swap it with the element at index i
            if (min_idx != i) {
                String temp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = temp;
            }
        }
    }
    
    static void print_array(int[] arr){
        for (int val : arr) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
  
    public static void main(String[] args){
        int[] arr = { 1, 20, 3, 23, 4, 5, 10, 23, 100, -2 };

        System.out.print("Original array is: ");
        print_array(arr);

        selection_sort_int(arr);

        System.out.print("After selectionSort() called: ");
        print_array(arr);
    }
}