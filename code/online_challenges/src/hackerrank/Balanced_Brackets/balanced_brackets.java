import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Main
{
    static String isBalanced(String s)
    {
        Stack<Character> st = new Stack<Character>();
        for (int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{')
            {
                st.push(s.charAt(i));
            }
            else if(st.isEmpty() && (s.charAt(i) == ')' || s.charAt(i) == ']' || s.charAt(i) == '}'))
            {
                return "NO";
            }
            else if(s.charAt(i) == ')')
            {
                if(st.peek()=='(')
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            else if(s.charAt(i) == ']')
            {
                if(st.peek()=='[')
                st.pop();
                else
                break;
            }
            else if(s.charAt(i) == '}')
            {
                if(st.peek() == '{')
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
        }
        if(st.isEmpty())
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    
    private static final Scanner scanner = new Scanner(System.in);
   
    public static void main(String[] args) throws IOException
    {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
        
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        
        for (int tItr = 0; tItr < t; tItr++)
        {
            String s = scanner.nextLine();
            String result = isBalanced(s);
            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }
        bufferedWriter.close();
        scanner.close();
    }
}