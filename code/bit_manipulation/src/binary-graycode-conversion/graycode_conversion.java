public class graycode_conversion {
    // Binary to Gray
    public static int binaryToGray(int n) {
        return n ^ (n >> 1);
    }

    // Gray to Binary
    public static int grayToBinary(int n) {
        int binary = n;
        while (n > 0) {
            n >>= 1;
            binary ^= n;
        }
        return binary;
    }

    public static void main(String[] args) {
        int num = 7;
        int gray = binaryToGray(num);
        System.out.println("Gray Code: " + gray); // Output: 4
        System.out.println("Binary Code: " + grayToBinary(gray)); // Output: 7
    }
}
