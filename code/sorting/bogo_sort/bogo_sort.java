public class Bogosort {
    public static void main(String[] args) {
        if (args.length == 1) {
            String[] arr = args[0].split(",");
            Integer[] intArr = new Integer[arr.length];

            for (int i = 0; i < arr.length; i++) {
                intArr[i] = Integer.parseInt(arr[i]);
            }

            intArr = sort(intArr);

            for (int i = 0; i < arr.length; i++) {
                arr[i] = intArr[i].toString();
            }

            System.out.println(String.join(", ", arr));
        } else {
            System.out.println("An array needs to be passed in!");
        }
    }

    public static boolean isSorted(Integer[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    };

    public static Integer[] shuffle(Integer[] arr) {
        String[] strArr = new String[arr.length];
        Integer count = arr.length, temp, index;

        while (count > 0) {
            index = (int)(Math.random() * count);
            count--;

            temp = arr[count];
            arr[count] = arr[index];
            arr[index] = temp;
        }

        for (int i = 0; i < arr.length; i++) {
            strArr[i] = arr[i].toString();
        }

        System.out.println(String.join(", ", strArr));

        return arr;
    }

    public static Integer[] sort(Integer[] arr) {
        boolean sorted = false;
        while (!sorted) {
            arr = shuffle(arr);
            sorted = isSorted(arr);
        }
        return arr;
    }
}
