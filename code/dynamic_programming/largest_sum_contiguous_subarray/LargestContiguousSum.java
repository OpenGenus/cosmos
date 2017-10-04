public class Main {

    public static void main(String[] args) {
        int[] test_1 = {-1, 3, 5, -11, 10,};
        int max_test_1 = maxContigiousSumArray(test_1);
        System.out.println("The max is : " + max_test_1);
    }

    public static int maxContigiousSumArray(int[] p_array) {
        int max = p_array[0]; // Set the max to the 0th index of the array
        int sum[] = new int[p_array.length]; // Create a new array to store the current biggest
        sum[0] = p_array[0];

        for (int i = 1; i < p_array.length; i++) {
            sum[i] = Math.max(p_array[i], sum[i - 1] + p_array[i]);
            max = Math.max(max, sum[i]);
        }

        return max;
    }
}
