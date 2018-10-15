import java.util.*;

class BalancedExpression {
	public static void main(String args[]) {
		System.out.println("Balanced Expression");
		Scanner in = new Scanner(System.in);
		String input = in.next();
		if (isExpressionBalanced(input)) {
			System.out.println("The expression is balanced");
		}
		else {
			System.out.println("The expression is not balanced");
		}

		static boolean isExpressionBalanced(String input) {
			Stack stack = new Stack();
			for (int i=0; i<input.length(); i++) {
				if (input.charAt(i) == '(' || input.charAt(i) == '{'|| input.charAt(i) == '[') {
					stack.push(input.charAt(i));
				}
				if (input.charAt(i) == ')' || input.charAt(i) == '}'|| input.charAt(i) == ']') {
					if (stack.empty()) {
						return false;
					}
					char top_char = (char) stack.pop();
					
					if ( (top_char == '(' && input.charAt(i) != ')') || (top_char == '{' && input.charAt(i) != '}') || (top_char == '[' && input.charAt(i) != ']') ) {
						return false;
					}	  
				}
			}
			return stack.empty();
		}
	}
}

