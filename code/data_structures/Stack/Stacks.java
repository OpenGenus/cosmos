/* Part of Cosmos by OpenGenus Foundation */

import java.util.ArrayList;
class Stack{
	private int maxSize;
	private int[] stackArray;
	private int top;

	public Stack(int size){
		maxSize = size;
		stackArray = new int[maxSize];
		top = -1;
	}

	public void push(int value){
		if(!isFull()){ //Checks for a full stack
			top++;
			stackArray[top] = value;
		}else{
			System.out.println("The stack is full, can't insert value");
		}
	}

	public int pop(){
		if(!isEmpty()){ //Checks for an empty stack
			return stackArray[top--];
		}else{
			System.out.println("The stack is already empty");
			return -1;
		}
	}

	public int peek(){
		if(!isEmpty()){ //Checks for an empty stack
			return stackArray[top];
		}else{
			System.out.println("The stack is empty, cant peek");
			return -1;
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

class Stack2{
		ArrayList<Integer> stackList;

		Stack2(){
			stackList=new ArrayList<>();
		}

		void push(int value){
			stackList.add(value);
		}

		int pop(){

			if(!isEmpty()){ // checks for an empty Stack

				int popValue=stackList.get(stackList.size()-1);
				stackList.remove(stackList.size()-1);  //removes the poped element from the list
				return popValue;
			}
			else{
				System.out.print("The stack is already empty  ");
				return -1;
			}

		}

		boolean isEmpty(){
			if(stackList.isEmpty())
				return true;

			else return false;

		}

		int peek(){
			return stackList.get(stackList.size()-1);
		}
	}

public class Stacks{
	/**
	 * Main method
	 *
	 * @param args Command line arguments
	 */
	public static void main(String args[]){
			Stack myStack = new Stack(4); //Declare a stack of maximum size 4
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

		Stack2 myStack2 = new Stack2(); //Declare a stack of maximum size 4
  		//Populate the stack
 		myStack2.push(5);
		myStack2.push(8);
 		myStack2.push(2);
 		myStack2.push(9);

 		System.out.println("*********************Stack List Implementation*********************");
 		System.out.println(myStack2.isEmpty()); //will print false
 		System.out.println(myStack2.peek()); //will print 9
 		System.out.println(myStack2.pop()); //will print 9
 		System.out.println(myStack2.peek()); // will print 2
 		System.out.println(myStack2.pop()); //will print 2
	}
}
