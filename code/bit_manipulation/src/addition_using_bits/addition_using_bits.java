/*
Problem Statement : 
Add two numbers using bitwise operators
(i.e without using arithmetic operators)
*/

import java.util.Scanner;

class Addition_Using_Bits
{
    // iterative function
    static int bitwiseAddition(int n, int m)
    {
        while (m != 0)
        {
            int carry = n & m;  
            n = n ^ m;      
            m = carry << 1; 
        }
        return n;
    }
    
    // recursive function
    static int bitwiseAdditionRecursive(int n, int m)
    {
        if (m == 0)
            return n;
        else
        {
            int carry = n & m;
            return bitwiseAdditionRecursive(n ^ m, carry << 1);
        }
    }
    
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        
        int a, b;
        System.out.print("Enter two numbers : ");
        a = in.nextInt();
        b = in.nextInt();
        
        System.out.println("\nBitwise addition using iterative function : " + bitwiseAddition(a, b));
        System.out.println("Bitwise addition using recursive function : " + bitwiseAdditionRecursive(a, b));
    }
}

/*
Enter two numbers : 3 5

Bitwise addition using iterative function : 8
Bitwise addition using recursive function : 8
*/
