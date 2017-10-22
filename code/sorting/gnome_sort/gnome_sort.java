// Java Program to implement Gnome Sort
 
import java.util.Arrays;
public class GnomeSort {
    private static void gnomeSort(int arr[]) {
        int index = 0;
        while (index < arr.length) {
            if ((index == 0) || (arr[index - 1] <= arr[index])) {
                index++;
            } else {
                int temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                index--;
            }
        }
    }

    // Driver program to test above functions.
    public static void main(String[] args) {
        int arr[] = {34, 2, 10, -9};
        System.out.println("Before: " + Arrays.toString(arr));
        gnomeSort(arr);
        System.out.println("After: " + Arrays.toString(arr));
    }
}