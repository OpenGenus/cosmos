class SingleNumber {

    public static int getNumberWithCountOne(int[] arrayOfNumbers) {
        int result = 0;
        int i;

        if(arrayOfNumbers == null || arrayOfNumbers.length == 0) 
            return -1;

        for (i = 0; i < arrayOfNumbers.length; i++) 
            result ^= arrayOfNumbers[i];
            
        return result;
    }

    public static void main(String[] args) {
        int[] arrayToTest = new int[] { 1, 2, 3, 1, 2, 3, 4, 5, 6, 5, 6 };

        int res = getNumberWithCountOne(arrayToTest);
        System.out.println(res);
    }
}
