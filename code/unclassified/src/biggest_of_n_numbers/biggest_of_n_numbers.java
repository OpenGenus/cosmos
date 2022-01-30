import java.util.Scanner;

public class BiggestOfNNumbers
{
       public static void main(String[] args)
       {
            Scanner data = new Scanner(System.in);
            System.out.print("Enter numbers of elements");
            int n = data.nextInt();
            System.out.println("Enter " + n + " numbers");
            int max = data.nextInt();
         
            for (int i = 1; i < n; ++i)
            { 
                  int temp = data.nextInt();
                  if(temp < max)
                        continue;
                  else
                        max = temp;
            }
            System.out.println("Maximum is "+ max);
        }
 }
