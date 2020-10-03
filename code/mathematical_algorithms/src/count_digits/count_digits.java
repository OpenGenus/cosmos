/* Part of Cosmos by OpenGenus Foundation */
public class CountDigits {

    public static void main(String args[]) {
        System.out.println(countDigits(0)); // => 1
        System.out.println(countDigits(2)); // => 1
        System.out.println(countDigits(337)); // => 3
    }
    
    public static int countDigits(int n)
    {
        if (n == 0) 
            return 1;
    	
        int count = 0;
        while (n != 0) {
            count++;
            n /= 10;
        }
        return count;
    }
}