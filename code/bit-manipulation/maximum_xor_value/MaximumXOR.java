

import java.util.Scanner;

// To maximize A xor B, we want A and B to differ as much as possible at every bit index.
// We first find the most significant bit that we can force to differ by looking at L and R.
// For all of the lesser significant bits in A and B, we can always ensure that they differ 
// and still have L <= A <= B <= R. Our final answer will be the number represented by all
// 1s starting from the most significant bit that differs between A and B

// Example:
//  L = 10111   
//  R = 11100
//      _X___  <-- that's most significant differing bit
//      01111  <-- here's our final answer
//
// Notice that we never directly calculate the values of A and B

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int L = scan.nextInt();
        int R = scan.nextInt();
        scan.close();
        
        int xored  = L ^ R;
        int significantBit = 31 - Integer.numberOfLeadingZeros(xored);
        int result = (1 << (significantBit + 1)) - 1;

        System.out.println(result);
    }
}
