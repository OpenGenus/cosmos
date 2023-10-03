public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {20, 30, 60, 80, 100, 102, 104, 900};
        int target = 900;
        System.out.println(binarySearch(arr, target));
    }

    static int binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + end >>> 1;

            if (target < arr[mid]) {
                end = --mid;
            } else if (target > arr[mid]) {
                start = ++mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
