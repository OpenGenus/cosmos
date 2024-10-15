// Insertion sort for integer and string arrays
class instertion_sort {
    // Integer version
    public static void insertion_sort_int(int[] arr) {
        int i, j, current;

        // Loops through array
        for (i = 1; i < arr.length; i++) {
            j = i - 1;
            current = arr[i];

            // Loops backward from current element to find its spot
            while (j >= 0 && current < arr[j]) {
                arr[j + 1] = arr[j];
                j--; 
            }
            // Inserts the number in its correct place within the sorted half
            arr[j + 1] = current;
        }
    }

    // String version
    public static void insertion_sort_str(String[] arr) {
        int i, j; 
        String current;
        
        // Loops through array 
        for (i = 1; i < arr.length; i++) {
            j = i - 1;
            current = arr[i];

            // Loops backward from current element to find its spot 
            while (j >= 0 && current.compareToIgnoreCase(arr[j]) < 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            // Inserts the string in its correct place within the sorted half
            arr[j + 1] = current;
        }

    }

    // Tests insertion_sort_int
    public static void int_tester() {
        int[] test_arr = {77, 52, -27, 1, 7, 0, 127, 45, 25};
       
        // Prints original array
        System.out.println("Original array: ");
        for (int i : test_arr) {
            System.out.println(i + " ");
        }

        // Sorting occurs
        insertion_sort_int(test_arr);

        // Prints results
        System.out.println("After sort: ");
        for (int i : test_arr) {
            System.out.println(i + " ");
        }
    }

    // Tests insertion_sort_string
    public static void str_tester() {
        String[] test_arr2 = {"hello", "hi", "tomorrow", "zoo", "kitten", "Help", "dog", "climb", "I"};
        
        // Prints original array
        System.out.println("Original array: ");
        for (String str : test_arr2) {
            System.out.println(str + " ");
        }

        // Sorting occurs
        insertion_sort_str(test_arr2);

        // Prints resulting array
        System.out.println("After sort: ");
        for (String str : test_arr2) {
            System.out.println(str + " ");
        }
    }

    // Main method calling test functions
    public static void main(String[] args) {
        int_tester();
        System.out.println();
        str_tester();
        System.out.println();
    }
}