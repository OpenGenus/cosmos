import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
// Part of Cosmos by OpenGenus Foundation
public class Pangram {
    public static void main(String args[]) throws Exception {
	
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the String to check for Pangram : ");
        String sm = s.nextLine();
        int count = 0 , k = 0;
      
        for(int i = 65 , j = 97 ; (i <= 90 && j <= 122) ; i++ , j++)
        {
            k = 0;
            while(k < sm.length())
               {
                if(sm.charAt(k) != ' ')
                {
                    if((sm.charAt(k) == (char)i) || (sm.charAt(k) == (char)j)){               
                        count++;
                        break;
                    }
                }
                k++;
            }
            
        }
        if(count == 26)
            System.out.println("Pangram");
        else
            System.out.println("Not Pangram");
        
        
    }
}
