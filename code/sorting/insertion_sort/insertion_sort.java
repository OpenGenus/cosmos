// Part of Cosmos by OpenGenus Foundation
class InsertionSort {
    void sort(int arr[]) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    // Driver method
    public static void main(String args[]) {
        int arr[] = {8, 2, 111, 3, 15, 61, 17};
        System.out.println("Before: " + Arrays.toString(arr));
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
        System.out.println("After:" + Arrays.toString(arr));
    }
}
