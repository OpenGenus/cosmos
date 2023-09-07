import java.util.Scanner;
class lapindrome_checker {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter String to be checked");
    String str = in.nextLine();
    if(isLapindrome(str))
      System.out.println(str+" is a Lapindrome string");
    else
      System.out.println(str+" is not a Lapindrome string");
  }
  static boolean isLapindrome(String s) {
    int[] count1 = new int[50];
    int[] count2 = new int[50];
    int n = s.length();
    if (n == 1)
      return true;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      count1[s.charAt(i) - 'a']++;
      count2[s.charAt(j) - 'a']++;
    }
    for (int i = 0; i < 50; i++)
      if (count1[i] != count2[i])
        return false;
        
        return true;
  }
}
