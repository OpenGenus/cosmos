class BinarySearch {
    public static int binarySearchInt(int[] arr, int x) {
        // Initialize the variables. start and end define our search space
        int start = 0;
        int end = arr.length - 1;
        int midpoint;
        // The main loop. Each iteration we cut our search space in half
        while (start <= end) {
            // Check the midpoint of the search space
            midpoint = start + ((end - start)/2);
            // If the midpoint is what we're looking for, return
            if (arr[midpoint] == x) {
                return midpoint;
            }
            // If the midpoint is too large, search the first half
            if (arr[midpoint] > x) {
                end = midpoint - 1;
            }
            // If the midpoint is too small, search the second half
            else {
                start = midpoint + 1;
            }
        }
        // If we never find the element, it is not in the array. In that case return -1
        return -1;
    }
    
    public static void intTester() {
        int i;
        int x;
        // The sorted array we will search
        int[] sortedArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        // A list of numbers not in the array, to see if our function correctly returns -1
        int[] extras = {12, -2, 34};
        
        for (i = 0; i < sortedArr.length + extras.length; i += 1) {
            if (i < sortedArr.length) {
                x = sortedArr[i];
            } else {
                x = extras[i - sortedArr.length];
            }
            
            System.out.print("Searching for element: " + x + "; ");
            int result = binarySearchInt(sortedArr, x);
            if (result != -1) {
                System.out.println("Element found at index: " + result);
            } else {
                System.out.println("Element not found");
            }
        }
    }
    
    public static void main(String[] args) {
        intTester();
    }
}
