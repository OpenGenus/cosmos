// To include java library
import java.util.*;

public class infixPrefix {

    /**
      * This method checks if given character is
      * an operator or not.
      * @param c character input
      */
    static boolean isOperator(char c) {
        return (!(c >= 'a' && c <= 'z') &&
               !(c >= '0' && c <= '9') &&
               !(c >= 'A' && c <= 'Z'));
    }

    /**
      * This method checks priority of given operator.
      * @param c character input
      */
    static int getPriority(char C) {
        if (C == '-' || C == '+')
            return 1;
        else if (C == '*' || C == '/')
            return 2;
        else if (C == '^')
            return 3;
        return 0;
    }

    /**
      * This method converts infix
      * expression to prefix expression.
      * @param infix string input
      */
    static String infixToPrefix(String infix) {
        // stack for operators.
        Stack<Character> operators = new Stack<Character>();

        // stack for operands.
        Stack<String> operands = new Stack<String>();
        for (int i = 0; i < infix.length(); i++) {
            // If current character is an
            // opening bracket, then
            // push into the operators stack.
            if (infix.charAt(i) == '(') {
                operators.push(infix.charAt(i));
            }

            // If current character is a
            // closing bracket, then pop from
            // both stacks and push result
            // in operands stack until
            // matching opening bracket is
            // not found.
            else if (infix.charAt(i) == ')') {
                while (!operators.empty() && operators.peek() != '(') {
                    // operand 1
                    String op1 = operands.peek();
                    operands.pop();
                    // operand 2
                    String op2 = operands.peek();
                    operands.pop();
                    // operator
                    char op = operators.peek();
                    operators.pop();
                    // Add operands and operator
                    // in form operator +
                    // operand1 + operand2.
                    String tmp = op + op2 + op1;
                    operands.push(tmp);
                }
                // Pop opening bracket
                // from stack.
                operators.pop();
            }

            // If current character is an
            // operand then push it into
            // operands stack.
            else if (!isOperator(infix.charAt(i))) {
                operands.push(infix.charAt(i) + "");
            }

            // If current character is an
            // operator, then push it into
            // operators stack after popping
            // high priority operators from
            // operators stack and pushing
            // result in operands stack.
            else {
                while (!operators.empty() && getPriority(infix.charAt(i)) <= getPriority(operators.peek())) {
                    String op1 = operands.peek();
                    operands.pop();
                    String op2 = operands.peek();
                    operands.pop();
                    char op = operators.peek();
                    operators.pop();
                    String tmp = op + op2 + op1;
                    operands.push(tmp);
                }
                operators.push(infix.charAt(i));
            }
        }

        // Pop operators from operators
        // stack until it is empty and
        // operation in add result of
        // each pop operands stack.
        while (!operators.empty()) {
            String op1 = operands.peek();
            operands.pop();
            String op2 = operands.peek();
            operands.pop();
            char op = operators.peek();
            operators.pop();
            String tmp = op + op2 + op1;
            operands.push(tmp);
        }

        // Final prefix expression is
        // present in operands stack.
        return operands.peek();
    }

}

// Driver Code
public class infixConversion {
    public static void main(String args[]) {
        infixPrefix g = new infixPrefix();
        // Using Scanner for Getting Input from User
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        // String s = "(A-B/C)*(A/K-L)";
        System.out.println(g.infixToPrefix(s));
    }
}

// Input - (A-B/C)*(A/K-L)
// Output -  *-A/BC-/AKL
