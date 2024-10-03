import java.util.*;

public class Pallindrome {

    public static boolean checkPallindrome(String s) {
        int count = 0;

        Stack <Character> stack = new Stack<Character>();
        for(char i=0; i<s.length(); i++)
            stack.push(s.charAt(i));

        int j = 0;
        while(!stack.empty() && j<s.length()) {
            if(s.charAt(j++) == stack.pop())
                count++;
        }

        if(count == s.length())
            return true;
        else
            return false;
    }
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        String s = sc.nextLine();
        boolean b = checkPallindrome(s);
        if(b == true)
            System.out.print("Pallindrome");
        else
            System.out.print("Not a Pallindrome");
    }
}
