/*
Problem Statement :
Clear all MSB's except for the first i LSB's of a number n.
MSB -> Most Significant Bit
LSB -> Most Significant Bit 
*/

import java.util.*;

class ClearBitsFromMsb
{ 
    static int clearBitsFromMsb(int n, int i)
    {
        int mask = (1 << i) - 1;
        return n & mask;
    }

    public static void main(String args[])
    { 
        Scanner sc = new Scanner(System.in); 

        System.out.print("Enter n and i : ");
        int n = sc.nextInt(); 
        int i = sc.nextInt();

        n = clearBitsFromMsb(n, i);
        System.out.println("\nResult : " + n); 
    } 
} 

/*
Enter n and i : 14 3

Result : 6
*/
