import java.util.Scanner;
import java.util.Stack;
 
public class InfixToPostfix {
 
 /**
  * Checks if the input is operator or not
  * @param c input to be checked
  * @return true if operator
  */
 private boolean isOperator(char c){
  if(c == '+' || c == '-' || c == '*' || c =='/' || c == '^')
   return true;
  return false;
 }
  
 /**
  * Checks if c2 has same or higher precedence than c1
  * @param c1 first operator
  * @param c2 second operator
  * @return true if c2 has same or higher precedence
  */
 private boolean checkPrecedence(char c1, char c2){
  if((c2 == '+' || c2 == '-') && (c1 == '+' || c1 == '-'))
   return true;
  else if((c2 == '*' || c2 == '/') && (c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/'))
   return true;
  else if((c2 == '^') && (c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/'))
   return true;
  else
   return false;
 }
  
 /**
  * Converts infix expression to postfix
  * @param infix infix expression to be converted
  * @return postfix expression
  */
 public String convert(String infix){
  System.out.printf("%-8s%-10s%-15s\n", "Input","Stack","Postfix");
  String postfix = "";  //equivalent postfix is empty initially
  Stack<Character> s = new Stack<>();  //stack to hold symbols
  s.push('#');  //symbol to denote end of stack
 
  System.out.printf("%-8s%-10s%-15s\n", "",format(s.toString()),postfix);  
 
  for(int i = 0; i < infix.length(); i++){
   char inputSymbol = infix.charAt(i);  //symbol to be processed
   if(isOperator(inputSymbol)){  //if a operator
    //repeatedly pops if stack top has same or higher precedence
    while(checkPrecedence(inputSymbol, s.peek()))
     postfix += s.pop();
    s.push(inputSymbol);
   }
   else if(inputSymbol == '(')
    s.push(inputSymbol);  //push if left parenthesis
   else if(inputSymbol == ')'){
    //repeatedly pops if right parenthesis until left parenthesis is found
    while(s.peek() != '(') 
     postfix += s.pop();
    s.pop();
   }
   else
    postfix += inputSymbol;
   System.out.printf("%-8s%-10s%-15s\n", ""+inputSymbol,format(s.toString()),postfix);  
  }
 
  //pops all elements of stack left
  while(s.peek() != '#'){
   postfix += s.pop();
   System.out.printf("%-8s%-10s%-15s\n", "",format(s.toString()),postfix);  
 
  }
   
  return postfix;
 }
  
 /**
  * Formats the input  stack string
  * @param s It is a stack converted to string
  * @return formatted input
  */
 private String format(String s){
  s = s.replaceAll(",","");  //removes all , in stack string
  s = s.replaceAll(" ","");  //removes all spaces in stack string
  s = s.substring(1, s.length()-1);  //removes [] from stack string
   
  return s;
 }
  
 public static void main(String[] args) {
  InfixToPostfix obj = new InfixToPostfix();
  Scanner sc = new Scanner(System.in);
  System.out.print("Infix : \t");
  String infix = sc.next();
  System.out.print("Postfix : \t"+obj.convert(infix));
 }
}
