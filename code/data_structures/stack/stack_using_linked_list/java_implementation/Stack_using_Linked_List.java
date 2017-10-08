class StackUsingLinkedList<T extends Comparable<T>>{
	
	//created a variable list of Linked_List of generic type
	private Linked_List<T> list;
	
	public StackUsingLinkedList() {
		this.list = new Linked_List<>(); 
	}
	
	//method to push data in stack
	public void push(T item) {
		list.addFirst(item);
	}

	//method to pop data from stack
	public T pop() throws Exception {
		T retval = list.removeFirst();
		return retval;
	}

	//method to peek top element of stack
	public T peek() throws Exception {
		return list.getFirst();
	}

	//method to check size of stack
	public int size() {
		return list.size();
	}

	//method to check if stack is empty
	public boolean isEmpty() {
		return this.size()==0;
	}

	//method to display stack from top to bottom
	public void display() {
		System.out.print("(stack top) ");
		System.out.print(this);
		System.out.println(" (stack bottom)");
	}
	
	public String toString(){		
		return list.toString();		
	}
}

public class Stack_using_Linked_List {

	public static void main(String[] args) throws Exception {
		 	StackUsingLinkedList<Integer> stack = new StackUsingLinkedList<>();
		
			stack.push(5);
			stack.push(20);
			stack.push(8);
			stack.push(-1);
			stack.push(3);
			stack.display();
			
			stack.pop();
			stack.display();
		}
}