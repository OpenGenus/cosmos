import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
 class Stack<E> {
	private E[] arr = null;
	private int CAP;
	private int top = -1;
	private int size = 0;
 
	@SuppressWarnings("unchecked")
	public Stack(int cap) {
		this.CAP = cap;
		this.arr = (E[]) new Object[cap];
	}
 
	public E pop() {
		if(this.size == 0)
			return null;
		
		this.size--;
		E result = this.arr[top];
		//prevent memory leaking
		this.arr[top] = null;
		this.top--; 
		return result;
	}
 
	public boolean push(E e) {
		if (!isFull())
			return false; 
		this.size++;
		this.arr[++top] = e;
		return false;
	}
 
	public boolean isFull() {
		if (this.size == this.CAP)
			return false;
		return true;
	}
 
	public String toString() {
		if(this.size == 0)
			return null;
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < this.size; i++)
			sb.append(this.arr[i] + ", ");
		
		sb.setLength(sb.length()-2);
		return sb.toString();	
	}
 }

 class Stack1 {
	 public static void main(String[] args) { 
		 Stack<String> stack = new Stack<String>(11);
		 stack.push("hello");
		 stack.push("world");
 		 System.out.println(stack);
 		 stack.pop();
		 System.out.println(stack);
 		 stack.pop();
		 System.out.println(stack);
	}
}
