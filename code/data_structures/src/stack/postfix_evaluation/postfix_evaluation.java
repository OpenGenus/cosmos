// Part of Cosmos by OpenGenus
// Java proram to evaluate value of a postfix expression 
  
import java.util.Scanner;
import java.util.Stack; 
  
public class Evaluate  
{ 
    // Method to evaluate value of a postfix expression 
    static int evaluatePostfix(String s) 
    { 
        //create a stack 
        Stack<Integer> stack=new Stack<>(); 
          
        // Scan all characters one by one 
        for(int i=0;i<s.length();i++) 
        { 
            char c=s.charAt(i); 
              
            // If the scanned character is an operand (number here), 
            // push it to the stack. 
            if(Character.isDigit(c)) 
            stack.push(c - '0'); 
              
            //  If the scanned character is an operator, pop two 
            // elements from stack apply the operator 
            else
            { 
                int a = stack.pop(); 
                int b = stack.pop(); 
                  
                switch(c) 
                { 
                    case '+': 
                    stack.push(b+a); 
                    break; 
                      
                    case '-': 
                    stack.push(b-a); 
                    break; 
                      
                    case '/': 
                    stack.push(b/a); 
                    break; 
                      
                    case '*': 
                    stack.push(b*a); 
                    break; 
              } 
            } 
        } 
        return stack.pop();     
    } 
      
    // Driver program to test above functions 
    public static void main(String[] args)  
    { 
        Scanner sc=new Scanner();
        String s=sc.next(); 
        System.out.println(evaluatePostfix(s)); 
    } 

    /* Input : 
     231*+9-

     Output :
     -4
     */
} 
