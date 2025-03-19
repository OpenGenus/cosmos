import java.util.Scanner;
class BinarySearchExample
{
   public static void main(String args[])
   {
      int counter, num, item, array[], first, last, middle;
      Scanner input = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      num = input.nextInt(); 

      //Creating array to store the all the numbers
      array = new int[num];

      System.out.println("Enter " + num + " integers");
      //Loop to store each numbers in array
      for (counter = 0; counter < num; counter++)
          array[counter] = input.nextInt();

      System.out.println("Enter the search value:");
      item = input.nextInt();
      first = 0;
      last = num - 1;
      middle = (first + last)/2;

      while( first <= last )
      {
         if ( array[middle] < item )
           first = middle + 1;
         else if ( array[middle] == item )
         {
           System.out.println(item + " found at location " + (middle + 1) + ".");
           break;
         }
         else
         {
             last = middle - 1;
         }
         middle = (first + last)/2;
      }
      if ( first > last )
          System.out.println(item + " is not found.\n");
   }
}
