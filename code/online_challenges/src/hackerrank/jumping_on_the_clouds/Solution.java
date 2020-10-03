import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int c[] = new int[n];
    int zero = 0;
    int jump = 0;
    for(int c_i=0; c_i < n; c_i++){
        c[c_i] = in.nextInt();
        if(c[c_i]==1) {
            jump += zero/2+1;
            zero = 0;
        }
        else
            zero ++;
    }
    jump += zero/2;
    System.out.print(jump);
}
}
