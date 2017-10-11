import java.io.*;
// Part of Cosmos by OpenGenus Foundation
class Main {
  
  static int counter = 2;
  
  static boolean isLucky(int n) {
    int next_position = n;
    if(counter > n) {
        return true;
    }
    if(n % counter == 0) {
        return false;    
    }
    next_position -= next_position/counter;
    counter++;
    return isLucky(next_position);
  }
 

  public static void  main(String args[]) throws IOException {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Enter a number");
    int x = Integer.parseInt(stdin.readLine());
    if( isLucky(x) ) {
        System.out.println(x + " is a lucky no.");
    } else {
        System.out.println(x + " is not a lucky no.");
    }
  }
  
}
