public class array_Merging {

    public static int[] mergeArray(int[] array1, int[] array2) {
        int length1 = array1.length;
        int length2 = array2.length;
        int[] mergeArray = new int[length1 + length2];

        for (int i = 0; i < length1; i++) {
            mergeArray[i] = array1[i];
        }
        for (int i = 0; i < length2; i++) {
            mergeArray[i+length1] = array2[i];
        }

        return mergeArray;
    }

    public static void main(String[] args) {
        int [] array1={1,2,3,4};
        int [] array2={5,6,7,8};
        int [] mergeArray=mergeArray(array1,array2);
        for(int i=0;i<mergeArray.length;i++){
            System.out.println(mergeArray[i]);
        }

    }
}