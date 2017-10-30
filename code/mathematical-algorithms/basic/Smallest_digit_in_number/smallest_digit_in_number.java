/* Part of Cosmos by OpenGenus Foundation */
import java.util.*;
class smallest_digit_in_number{
    public static void main(String args[]) {
        int num = 238493;
        System.out.println(smallest_digit(num));
    }

    // returns the smallest integer of a given number.
    public static int smallest_digit(int n)
    {
        int min = n%10;
        n/=10;
        while(n!=0)
        {
            if(min>n%10)
                min=n%10;
            n/=10;
        }
        return min;
    }
}