/**
 * Ugly numbers are positive numbers whose only prime factors are 2,3,5.
 * First 5 ugly numbers are 1 , 2 , 3 , 4 , 5.
 */
package cosmos;

/**
 *
 * @author Pranay Chatterjee
 * @Without using Dynamic Programming
 * 
 */

import java.util.Scanner;   //for using Scanner User Input

public class ugly_number {

    /**
     * @param args the command line arguments
     */
    
    
    //ugly number function starts
    static int find_ugly( int number)
    {
        int x = 0;
        while (number <= 1) 
        {
            if (number % 5 == 0) 
            {
                number /= 5;
            } 
            else if (number % 3 == 0) 
            {
                number /= 3;
            } 
            else if (number % 2 == 0) 
            {
                number /= 2;
            } 
            else 
            {
                System.out.print("It is not an ugly number.");
		x = 1;
		break;
            }
        }
        if (x==0)
        {
		System.out.print("It is an ugly number.");
		System.out.print("\n");
	}
    }
    //ugly number function ends    
       
    public static void main(String[] args) {
        // TODO code application logic here
        //declare object
        //describe few examples
        //Good comments
        
        Scanner value = new Scanner(System.in);
        
        System.out.print("Input an integer number: ");
        int n = 0;
        n = value.nextInt(); //User Input
        find_ugly(n); //Find ugly number by invoking the function.
        
        
        
        
    }
    
}
