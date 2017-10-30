/* Part of Cosmos by OpenGenus Foundation */
import java.util.*;
public class Greatest_digit_in_number{
    public static void main(String args[]) {
        int num = 23238934;
        System.out.println(greatest_digit(num));
    }
    
    // returns greatest digit in a given number
    public static int greatest_digit(int n)
    {
        int max = 0;
        while(n != 0)
        {
            if(max<n%10) max=n%10;
            n/=10;
        }
        return max;
    }
}