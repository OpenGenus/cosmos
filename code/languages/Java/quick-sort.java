class quick_sort {
    public static void quickSort(int[] array, int startIndex, int endIndex) {   
        if (startIndex < endIndex) {
            int pivot = partition(array, startIndex, endIndex);
            quickSort(array, startIndex, pivot - 1); 
            quickSort(array, pivot + 1, endIndex);
        }
    }

    public static int partition (int[] array, int startIndex, int endIndex) {
        int pivot = array[endIndex];
        int left = startIndex;
        int right = endIndex - 1;
        
        while (left <= right) {
          if (array[left] <= pivot){
            left++;
          } else if (array[right] >= pivot){
            right--;
          } else{
            swap(array, left, right);
          }
        }
        swap(array, left, endIndex);
        return left; 
    }

    public static void swap(int[] array, int indexOne, int indexTwo){
        int temp = array[indexOne];
        array[indexOne] = array[indexTwo];
        array[indexTwo] = temp;  
    }

    public static void testingInts() {
        /* This function tests quick sort on an array of 10 
           non repeating integers */
        int[] intArray = {2, 50, 10, 31, 3, 7, 8, 1, 4, 98};
        String beforeSort = ""; 
        String afterSort = ""; 
        for (int i = 0; i < intArray.length; i++) {
            beforeSort = beforeSort + " " + intArray[i];  
        }
        System.out.println("Before:" + beforeSort); 
        quickSort(intArray, 0, 9);
        for (int i = 0; i < intArray.length; i++) {
            afterSort = afterSort + " " + intArray[i]; 
        }
        System.out.println("After:" + afterSort); 
    }

    public static void testingRepeats() {
        /* This function tests quick sort on an array of 10 
           integers, some of which repeat */
        int[] intArray = {10, 2, 1, 19, 8, 7, 2, 4, 76, 2};
        String beforeSort = ""; 
        String afterSort = ""; 
        for (int i = 0; i < intArray.length; i++) {
            beforeSort = beforeSort + " " + intArray[i];  
        }
        System.out.println("Before:" + beforeSort); 
        quickSort(intArray, 0, 9);
        for (int i = 0; i < intArray.length; i++) {
            afterSort = afterSort + " " + intArray[i]; 
        }
        System.out.println("After:" + afterSort); 
    }
    
    public static void main(String[] args) {
        testingInts(); 
        System.out.println(" ");
        testingRepeats(); 
    }
}
