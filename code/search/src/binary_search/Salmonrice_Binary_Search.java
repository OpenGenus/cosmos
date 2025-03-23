class Salmonrice_Binary_Search{
    public static void main(String[] args) {

        int arr[] = {1,2,3,4,5,6,7,8,9};
        System.out.println("5 is at index : "+runBinarySearchRecursively(arr, 5, 1, 9));
    }


    public static int runBinarySearchRecursively(int[] sortedArray, int key, int low, int high) {
        int middle = low  + ((high - low) / 2);

        if (high < low) {
            return -1;
        }

        if (key == sortedArray[middle]) {
            return middle;
        } else if (key < sortedArray[middle]) {
            return runBinarySearchRecursively(
                    sortedArray, key, low, middle - 1);
        } else {
            return runBinarySearchRecursively(
                    sortedArray, key, middle + 1, high);
        }
    }


}