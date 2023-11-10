public class Main {
    public static void main(String[] args) {
        int number = 16; // Change this number to check if it's a power of 4
        boolean result = isPowerOfFour(number);
        if (result) {
            System.out.println(number + " is a power of 4.");
        } else {
            System.out.println(number + " is not a power of 4.");
        }
    }

    public static boolean isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        // A number is a power of 4 if it is a power of 2 and has only one set bit in its binary representation.
        // Count the number of set bits and check if it's odd.
        int countSetBits = 0;
        int temp = num;
        while (temp > 0) {
            temp = temp >> 1;
            countSetBits++;
        }
        // Check if there is only one set bit and it's at an odd position (0-based index)
        return (countSetBits == 1) && ((countSetBits - 1) % 2 == 0);
    }
}
