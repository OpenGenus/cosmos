import java.util.*;

public class sum_binary_numbers {
    public static void main(String[] args) {
        System.out.println(add_binary_return_binary("1010", "10"));
        System.out.println(add_binary_return_dec("1010", "10"));
    }

    public static String add_binary_return_binary(String input1, String input2) {
         
        int a = Integer.parseInt(input1, 2);
        int b = Integer.parseInt(input2, 2);

        int sum = a + b;
        String sum_binary = Integer.toBinaryString(sum);
        
        return sum_binary;
    }
    
    
    public static int add_binary_return_dec(String input1, String input2) {
         
        int a = Integer.parseInt(input1, 2);
        int b = Integer.parseInt(input2, 2);

        int sum = a + b;
        
        return sum;
    }
}