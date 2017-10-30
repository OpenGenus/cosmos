/* Part of Cosmos by OpenGenus Foundation */

import java.util.ArrayList;
class Stack<T>{
	private int maxSize;
	private ArrayList<T> stackArray;
	private int top;

	public Stack(int size){
		maxSize = size;
		stackArray = new ArrayList<>();
		top = -1;
	}

	public void push(T value){
		if(!isFull()){ //Checks for a full stack
			top++;
			if(stackArray.size() <= top)
				stackArray.add(top, value);
			else
				stackArray.set(top, value);
			//stackArray[top] = value;
		}else{
			System.out.println("The stack is full, can't insert value");
		}
	}

	public T pop(){
		if(!isEmpty()){ //Checks for an empty stack
			return stackArray.get(top--);
		}else{
			throw new IndexOutOfBoundsException();
		}
	}

	public T peek(){
		if(!isEmpty()){ //Checks for an empty stack
			return stackArray.get(top);
		}else{
			throw new IndexOutOfBoundsException();
		}
	}

	public boolean isEmpty(){
		return(top == -1);
	}

	public boolean isFull(){
		return(top+1 == maxSize);
	}

	public void makeEmpty(){ //Doesn't delete elements in the array but if you call
		top = -1;			 //push method after calling makeEmpty it will overwrite previous values
	}
}

public class Stacks{
	/**
	 * Main method
	 *
	 * @param args Command line arguments
	 */
	public static void main(String args[]){
		Stack<Integer> myStack = new Stack<>(4); //Declare a stack of maximum size 4
 		//Populate the stack
 		myStack.push(5);
 		myStack.push(8);
  		myStack.push(2);
  		myStack.push(9);

		System.out.println("*********************Stack Array Implementation*********************");
  		System.out.println(myStack.isEmpty()); //will print false
  		System.out.println(myStack.isFull()); //will print true
  		System.out.println(myStack.peek()); //will print 9
  		System.out.println(myStack.pop()); //will print 9
  		System.out.println(myStack.peek()); // will print 2
	}
}
