// Part of Cosmos by OpenGenus Foundation

public class two_sum {
    private static int[] two_sum(int[] arr, int target) {
        if (arr == null || arr.length < 2) return new int[]{0, 0};//Condition to check

        HashMap<Integer, Integer> map = new HashMap<>();//Map Interface
        for (int i = 0; i < arr.length; i++) {//Loop total total length of array
            if (map.containsKey(arr[i])) {//Checking for a definite key
                return new int[]{map.get(arr[i]), i};
            } else {
                map.put(target - arr[i], i);
            }
        }
        return new int[]{0, 0};
    }
//Driver's code
    public static void main(String[] args) {//Main method
        int[] arr1 = {3, 5, 7, 0, -3, -2, -3};//Initializing 
        int[] arr2 = {3, 5, 0, -3, -2, -3};//Initializing

        System.out.println(Arrays.toString(two_sum(arr1, 4)));//Output condition
        System.out.println(Arrays.toString(two_sum(arr2, 4)));//Output condition
    }
}
