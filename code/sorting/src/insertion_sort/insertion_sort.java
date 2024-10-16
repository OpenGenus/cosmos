// Part of Cosmos by OpenGenus Foundation
class InsertionSort {       
    void sort(int arr[]) {      // sort() performs the insertion sort on the array which is passed as argument from main() 
        for (int i = 0; i < arr.length; ++i) {
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {   // swapping of elements if j-1th element is greater than jth element 
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    // Driver method
    public static void main(String args[]) {
        int arr[] = {8, 2, 111, 3, 15, 61, 17};        // array to be sorted
        System.out.println("Before: " + Arrays.toString(arr));      // printing array before sorting
        InsertionSort ob = new InsertionSort();     // object of class InsertionSort is created
        ob.sort(arr);       // arr is passed as argument to the function sort() is called 
        System.out.println("After:" + Arrays.toString(arr));        // printing array after insertion sort is applied
    }
}
