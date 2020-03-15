import java.util.*;
import java.io.*;

//#######Linked-list########
/*Methods Used:
 1. Insert at a given position
 2. Append 
 3. Prepend
 4. Delete a value
 5. Delete at a position
 6. Display the linked-list*/
 
 //Each node is an instance of itself
class Node{
	Node next;        //next is the node pointed by 'this' node
	int data;         //value that the node contains
	public Node(int data)//Function containing the data
	{
		this.data=data;
	}
}

class LinkedList{
	Node head;                    //head denotes the starting node
	public void insertatpos(int p, int data){//Function for insertion at a defined position
  
  //In case the list is empty, insert the value as the first element
		if(head == null){
			head = new Node(data);
			return;
		}
		int pos = 0;
		Node current = head;        //Initialize current as the first element
		Node h;
    
    //Traversing the entire list
		while(current.next != null){//Condition for transversing
			pos++;
			if(pos == p-1){
				h = current.next;                      //Temporary object that points to the next node
				current.next = new Node(data);//Kind of swapping taking place
				current.next.next = h;
			}
			current = current.next;
		}
	}
	public void append(int data){//append function
		if(head == null){//condition for starting element
			head = new Node(data);
			return;
		}
		Node current = head;
		while(current.next != null){//condition check for the next element
			current = current.next;
		}
		current.next = new Node(data);//Assigning data to it
	}
	public void prepend(int data)//Prepend function
	{
		Node nHead = new Node(data);
		nHead.next = head;
		head = nHead;//Swapping done again as earlier
	}	
	public void delval(int data){//Delete function
		if(head == null)//Checking for null
			return;
		Node current = head;//Assigning current code as head
		while(current.next != null){//Condition check
			if(current.next.data == data)
				current.next = current.next.next;//Transversing the node from next method
			current = current.next;
		}
	}
	public void delatpos(int p){//Function for deleting at specified condition
		if(head == null)
			return;
		Node current = head;
		int pos = 0;
		while(current.next != null){//condition for checking position	
			pos++;	
			if(pos == p-1){
				current.next = current.next.next;
				return;
			}
			current = current.next;
		}
	}
	public void display(){//Display function
		Node current = head;
		while(current != null){
			System.out.print(current.data+" ->");//Successfully read output
			current = current.next;
		}
	}
}

class linked_list
{	
	public static void main(String[] args)throws IOException{Main function along with Precaution for exception
		Scanner sc = new Scanner(System.in);//Using Scanner Class
		LinkedList obj = new LinkedList();//Initializing a Linked List
		while(true) {
			System.out.println("\n******MENU******");
			System.out.println("\n1.Append");
			System.out.println("\n2.Prepend");
			System.out.println("\n3.Insert at a position");//Options available At the output screen to choose
			System.out.println("\n4.Delete a value");
			System.out.println("\n5.Delete at a position");
			System.out.println("\n6.Display List");
			System.out.println("\n7.Exit");
			int ch = sc.nextInt();
			int x, pos;
			switch(ch){
				case 1://Case for Append
					System.out.println("\nEnter the value to append");
					x = sc.nextInt();
					obj.append(x);//Using object
					break;
				case 2://Case for prepend
					System.out.println("\nEnter the value to prepend");
					x = sc.nextInt();
					obj.prepend(x);//Using object
					break;
				case 3:
					System.out.println("Enter the position and value to be inserted");//Specifies the value as well as position
					pos = sc.nextInt();
					x = sc.nextInt();
					obj.insertatpos(pos,x);//object used along with above function to reduce unnecessary steps
					break;

				case 4:
					System.out.println("\nEnter the value to be deleted");//Value to delete  
					x = sc.nextInt();
					obj.delval(x);//Object used
					break;
				case 5:
					System.out.println("\nEnter the position at which data is to be deleted");//position specifies for deletion
					pos = sc.nextInt();
					obj.delatpos(pos);//Object used calling above functions to maintain time complexity of a particular function
					break;
				case 6:
					obj.display();//display function called
					break;
				case 7:
					return;
				default:
					return;//default if user needs none of them
			}
		}
	}
}
	

	


					
