import java.util.Scanner;

public class Biggest_of_n_numbers
  {
  public static void main(String argn[]){
    Scanner data = new Scanner(System.in);
    int n, i, temp, max;
    System.out.print("Enter numbers of elements");
    n = data.nextInt();
    System.out.println("Enter " +n+ " numbers");
    max = data.nextInt();
    for (i = 1; i < n; ++i) 
{ 
    temp = data.nextInt();
    if(temp < max)
    continue;
    else
    max = temp;
}
   System.out.println("Maximum is "+max);
}
}