/* Part of Cosmos by OpenGenus Foundation */

import java.util.Scanner;

class STACK{
    private int top, MAX;
    private String a[] = new String [1000];
    public STACK(){
        top = -1;
        MAX = 1000;
        a[0] = "";
    }
    public void push(String x){
        if (top <= MAX-1){
            a[++top] = x;
        }
        else{
            System.out.println("Stack overflow");
        }
    };
    public String pop(){
        if (top == -1){
            System.out.println("\nStack empty!");
            return "\n";
        }
        else{
            return a[top--];
        }
    };
    public int getTop(){
        return top;
    };
}

public class Prefix2Postfix_STACK{
    static boolean isOperator (char ch){
        switch (ch){
            case '+':
            case '-':
            case '*':
            case '/':
            case '$':
                        return true;
            default :
                        return false;
        }
    }
    public static void main(String[] args) {
        //declarations
        Scanner in = new Scanner (System.in);
        String exp;
        int i;
        STACK s = new STACK ();
        String exp_str[] = new String[100];
        String postfix_exp = "\n";

        //input
        System.out.println("Enter prefix expression (No spaces or brackets) : ");
        exp = in.next();

        //create a string array of all characters but in reverse
        for(i=0; i<=exp.length()-1; i++){
            exp_str[exp.length()-1-i]=Character.toString(exp.charAt(i));
        }

        //computing postfix:
        i=0;
        do{ 
            if (!isOperator(exp_str[i].charAt(0)))
                s.push(exp_str[i]);
            else{
                String str1 = s.pop();
                String str2 = s.pop();
                str1 = str1 + str2 + exp_str[i];
                postfix_exp = str1;
                s.push(str1);
            }
            i++;
        }while(s.getTop()>=0 && i!=exp.length());

        //Output
        System.out.println("After converting to postfix : " + postfix_exp);
        in.close();
    }
}
