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
	public Node(int data)
	{
		this.data=data;
	}
}

class LinkedList{
	Node head;                    //head denotes the starting node
	public void insertatpos(int p, int data){
  
  //In case the list is empty, insert the value as the first element
		if(head == null){
			head = new Node(data);
			return;
		}
		int pos = 0;
		Node current = head;        //Initialize current as the first element
		Node h;
    
    //Traversing the entire list
		while(current.next != null){
			pos++;
			if(pos == p-1){
				h = current.next;                      //Temporary object that points to the next node
				current.next = new Node(data);
				current.next.next = h;
			}
			current = current.next;
		}
	}
	public void append(int data){
		if(head == null){
			head = new Node(data);
			return;
		}
		Node current = head;
		while(current.next != null){
			current = current.next;
		}
		current.next = new Node(data);
	}
	public void prepend(int data)
	{
		Node nHead = new Node(data);
		nHead.next = head;
		head = nHead;
	}	
	public void delval(int data){
		if(head == null)
			return;
		Node current = head;
		while(current.next != null){
			if(current.next.data == data)
				current.next = current.next.next;
			current = current.next;
		}
	}
	public void delatpos(int p){
		if(head == null)
			return;
		Node current = head;
		int pos = 0;
		while(current.next != null){	
			pos++;	
			if(pos == p-1){
				current.next = current.next.next;
				return;
			}
			current = current.next;
		}
	}
	public void display(){
		Node current = head;
		while(current != null){
			System.out.print(current.data+" ->");
			current = current.next;
		}
	}
}

class linked_list
{	
	public static void main(String[] args)throws IOException{
		Scanner sc = new Scanner(System.in);
		LinkedList obj = new LinkedList();
		while(true) {
			System.out.println("\n******MENU******");
			System.out.println("\n1.Append");
			System.out.println("\n2.Prepend");
			System.out.println("\n3.Insert at a position");
			System.out.println("\n4.Delete a value");
			System.out.println("\n5.Delete at a position");
			System.out.println("\n6.Display List");
			System.out.println("\n7.Exit");
			int ch = sc.nextInt();
			int x, pos;
			switch(ch){
				case 1:
					System.out.println("\nEnter the value to append");
					x = sc.nextInt();
					obj.append(x);
					break;
				case 2:
					System.out.println("\nEnter the value to prepend");
					x = sc.nextInt();
					obj.prepend(x);
					break;
				case 3:
					System.out.println("Enter the position and value to be inserted");
					pos = sc.nextInt();
					x = sc.nextInt();
					obj.insertatpos(pos,x);
					break;

				case 4:
					System.out.println("\nEnter the value to be deleted");
					x = sc.nextInt();
					obj.delval(x);
					break;
				case 5:
					System.out.println("\nEnter the position at which data is to be deleted");
					pos = sc.nextInt();
					obj.delatpos(pos);
					break;
				case 6:
					obj.display();
					break;
				case 7:
					return;
				default:
					return;
			}
		}
	}
}
	

	


					
