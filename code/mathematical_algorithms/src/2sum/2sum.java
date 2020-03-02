// Part of Cosmos by OpenGenus Foundation

public class two_sum {
    private static int[] two_sum(int[] arr, int target) {//function decleration
        if (arr == null || arr.length < 2) return new int[]{0, 0};//Condition to be checked

        HashMap<Integer, Integer> map = new HashMap<>();//Map Interface
        for (int i = 0; i < arr.length; i++) {//Loop till total number of arr elements
            if (map.containsKey(arr[i])) {//Checking condition for a definite key
                return new int[]{map.get(arr[i]), i};
            } else {
                map.put(target - arr[i], i);
            }
        }
        return new int[]{0, 0};
    }
//Driver's code
    public static void main(String[] args) {//Main function
        int[] arr1 = {3, 5, 7, 0, -3, -2, -3};//Initialization of arr1
        int[] arr2 = {3, 5, 0, -3, -2, -3};//Initialization of arr2

        System.out.println(Arrays.toString(two_sum(arr1, 4)));//Output condititon
        System.out.println(Arrays.toString(two_sum(arr2, 4)));//Output condititon
    }
}
