// Part of Cosmos by OpenGenus Foundation

public class two_sum {
    private static int[] two_sum(int[] arr, int target) {
        if (arr == null || arr.length < 2) return new int[]{0, 0};

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])) {
                return new int[]{map.get(arr[i]), i};
            } else {
                map.put(target - arr[i], i);
            }
        }
        return new int[]{0, 0};
    }

    public static void main(String[] args) {
        int[] arr1 = {3, 5, 7, 0, -3, -2, -3};
        int[] arr2 = {3, 5, 0, -3, -2, -3};

        System.out.println(Arrays.toString(two_sum(arr1, 4)));
        System.out.println(Arrays.toString(two_sum(arr2, 4)));
    }
}