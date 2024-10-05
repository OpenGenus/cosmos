// Building Bubble Sort for both strings and integer arrays
class bubble_sort {
    public static void bubble_sort_int(int[] arr1) {
        int i, j;
        boolean areSwapped;

        // Loops through to sort the array
        for (i = 0; i < arr1.length - 1; i++) {
            areSwapped = false;
            for (j = 0; j < arr1.length - i - 1; j++) {
                if (arr1[j] > arr1[j+1]) {

                    // swaps the two numbers if they are out of order
                    int temp = arr1[j];
                    arr1[j] = arr1[j+1];
                    arr1[j+1] = temp;
                    areSwapped = true;
                }
            }

            // ends the algorithm if it is in sorted order
            if (areSwapped == false) {
                break;
            }
        }
    }

    public static void bubble_sort_string(String[] arr1) {
        int i, j;
        boolean areSwapped;

        // Loops through to sort the array
        for (i = 0; i < arr1.length; i++) {
            areSwapped = false;
            for (j = 0; j < arr1.length - i - 1; j++) {

                // case doesn't matter for sorting, so we don't want an error
                String atJ = arr1[j].toLowerCase();
                String atJ1 = arr1[j+1].toLowerCase();
                if (atJ.compareTo(atJ1) > 0) {

                    // swaps the two strings if they are out of order
                    String temp = arr1[j];
                    arr1[j] = arr1[j+1];
                    arr1[j+1] = temp;
                    areSwapped = true;
                }
            }

            // ends the algorithm if it is in sorted order
            if (areSwapped == false) {
                break;
            }
        }
    }

    public static void intTester() {
        // Tests the integer array sort function
        int[] check = {3, 1, 4, 2, 43, 7, 9, 13, 0, 2, -1};
        int i;
        System.out.println("Before: ");
        for (i = 0; i < check.length; i++) {
            System.out.print(check[i] + " ");
        }

        bubble_sort_int(check);

        System.out.println("\nAfter: ");
        for (i = 0; i < check.length; i++) {
            System.out.print(check[i] + " ");
        }
    }

    public static void stringTester() {
        // Tests the string array sort function
        String[] check = {"Hi", "Bye", "Byex", "Alex", "Ale", "My", "Friend", "q", "Z"};
        System.out.println("Before: ");
        int i;
        for (i = 0; i < check.length; i++) {
            System.out.print(check[i] + " ");
        }

        bubble_sort_string(check);

        System.out.println("\nAfter: ");
        for (i = 0; i < check.length; i++) {
            System.out.print(check[i] + " ");
        }
    }

    public static void main(String[] args) {
        // Runs the functions
        intTester();
        System.out.println();
        stringTester();
        System.out.println();
    }
}