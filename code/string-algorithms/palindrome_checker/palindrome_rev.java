//Not the best way of doing it, but it is easy to understand
import java.util.*;
 
class Palindrome
{
   public static void main(String args[])
   {
      String original, reverse="";
      Scanner in = new Scanner(System.in);
      //Take string as Input
      System.out.println("Enter a string to check if it is a palindrome");
      original = in.nextLine();
 
      int length = original.length();
      //Reverse the string
      for ( int i = length - 1 ; i >= 0 ; i-- )
         reverse = reverse + original.charAt(i);
      //Check if they are the same
      if (original.equals(reverse))
         System.out.println("Entered string is a palindrome.");
      else
         System.out.println("Entered string is not a palindrome.");
 
   }
}	
