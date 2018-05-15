/* Part of Cosmos by OpenGenus Foundation */
public class CountDigits {
    public static void main(String args[]) {
        int num = 12345678;
        System.out.println(count_digits(num));
    }
    
    public static int count_digits(int n)
    {
    	if(n == 0) return 1;
    	
        int count = 0;
        while(n != 0){
            count++;
            n /= 10;
        }
        return count;
    }
}