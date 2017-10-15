// Part of Cosmos by OpenGenus Foundation
import java.util.Stack;
// Assuming that you already know how the Stack works,
// if not, see here (code/data_structures/stack/stack)


class reverseStack{
	public static void main(String[] args){
		// Examples
		Integer[] intArr = {1, 3, 2, 5, 4};
		String[] stringArr = {"alpha", "beta", "gamma", "echo", "delta"};
		Double[] doubleArr = {1.1, 3.2, 1.2, 4.3, 5.4};
		Character[] charArr = {'D', 'E', 'L', 'T', 'A'};
		Object[] mixArr = {1, "alpha", 2.1, 'D', true};
		
		// Collecting all examples in single array
		Object[][] examples = {intArr, stringArr, doubleArr, charArr, mixArr};
		
		// Convert each array of examples to stack
		// and store them in single stack
		Stack<Stack<Object>> stacks = new Stack<Stack<Object>>();
		for(int i=examples.length-1; i>=0; i--)
			stacks.push(arrayToStack(examples[i]));
		
		// Print formatted output for each example
		while(!stacks.isEmpty())
			print(stacks.pop());
		
		// Print each example without storing it first
		System.out.println("\nWithout Storing:");
		for(Object[] item: examples)
			print(arrayToStack(item));
	}
	
	public static <T> void print(Stack<T> stack){
		System.out.println("Original stack: "+stack);
		// Print stack after reverse
		System.out.println("Reversed stack: "+reverse(stack)+"\n");
	}
	
	public static <T> Stack<T> arrayToStack(T[] arr){
		// Push each item into stack
		Stack<T> stack = new Stack<T>();
		for(T item: arr)
			stack.push(item);
		return stack;
	}
	
	public static <T> Stack<T> reverse(Stack<T> ori){
		// Push each item from last to first item of ori into rev
		Stack<T> rev = new Stack<T>();
		while(!ori.isEmpty())
			rev.push(ori.pop());
		return rev;
	}
}
