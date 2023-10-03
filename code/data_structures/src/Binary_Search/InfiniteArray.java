package array;

public class InfiniteArray {
    public static void main(String[] args) {
        int[] arr = {20, 30, 60, 80, 100, 102, 104, 900, 1000, 1100, 1200};
        int target = 1000;
        System.out.println(ans(arr, target));
    }

    static int ans(int[] arr, int target) {
        int start = 0;
        int end = 1;

        while (end < arr.length && target > arr[end]) {
            int temp = end + 1;
            end = end + (end - start + 1) * 2;
            start = temp;
        }
        return binarySearch(arr, target, start, end);
    }

    static int binarySearch(int[] arr, int target, int start, int end) {
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
