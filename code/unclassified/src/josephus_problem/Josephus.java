import java.util.Scanner;
class Josephus {
 public int safePlace(int n, int steps) {
    if(n == 1)
      return 0;
  
    return (safePlace(n - 1, steps) + steps) % n;
  }

  public static void main(String args[]) {
    Scanner in = new Sanner(System.in);
    System.out.println("Enter number of elements");
    int n = in.nextInt();
    System.out.println("Enter number of people to skip");
    int k = in.nextInt();
    System.out.println("Safe place to stand is : "+safePlace(n , k));
    in.close();
  }
}
