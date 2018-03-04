import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Scanner;


public class LinkedListeg {

	class Node {
		int value;
		Node next = null;
		Node(int value) {
			this.value = value;
		}
	}

	protected Node head = null;
	protected Node tail = null;

	public void addToFront(int value) {
		Node newNode = new Node(value);
		newNode.next = head;
		head = newNode;
		if(newNode.next == null)
		{
			tail = newNode;
		}
	}

	public void addToBack(int value) {
		Node newNode = new Node(value);
		if(tail == null)
		{
			head = newNode;
		}
		else
		{
			tail.next = newNode;
		}
		tail = newNode;
	}

	public void addAtIndex(int index,int value) {
		if(index < 0)
		{
			throw new IndexOutOfBoundsException();
		}
		else if(index == 0)
		{
			addToFront(value);
		}
		else
		{
			Node newNode = new Node(value);
			Node current = head;
			for(int i = 0; i < index-1; i++) {
				if(current == null)
				{
					throw new IndexOutOfBoundsException();
				}
			current = current.next;
		}
		if(current.next == null)
		{
			tail = newNode;
		}
		else
		{
			newNode.next = current.next;
			current.next = newNode;
		}
		}
	}

	public void removeFromFront() {
		if(head != null)
		{
			head = head.next;
		}
		if(head == null)
		{
			tail = null;
		}
	}

	public void removeFromBack() {
		if(head == null)
		{
			return;
		}
		else if(head.equals(tail))
		{
			head = null;
			tail = null;
		}
		else
		{
			Node current = head;
			while(current.next != tail) {
				current = current.next;
			}
			tail = current;
			current.next = null;
		}
	}

	public void removeAtIndex(int index) {
		if(index < 0)
		{
			throw new IndexOutOfBoundsException();
		}
		else if(index == 0)
		{
			removeFromFront();
		}
		else
		{
			Node current = head;
			for(int i = 0; i < index-1; i++) {
				if(current == null)
				{
					throw new IndexOutOfBoundsException();
				}
				current = current.next;
			}
			current.next = current.next.next;
			if(current.next == null)
			{
				tail = current;
			}
		}
	}

	public void printList() {
		Node newNode = head;
		if(head != null)
		{
			System.out.println("The Linked List contains :");
			while(newNode != null) {
				System.out.println(newNode.value);
				newNode = newNode.next;
			}
		}
		else
		{
			System.out.println("The list contains no elements");
		}
	}

	public void count() {
		Node newNode=head;
		int counter = 0;
		while(newNode != null ) {
			counter++;
			newNode = newNode.next;
		}
		System.out.println("The list contains "+counter+" elements");
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(new InputStreamReader(System.in));
		LinkedListeg list = new LinkedListeg();
		int ch = 0;
		do {
			System.out.println("Choose form the following");
			System.out.println("1.Add to Front\n2.Add to Back\n3.Add at index\n4.Remove from front");
			System.out.println("5.Remove from back\n6.remove at index\n7.Print elements in the Linked List");
			System.out.println("8.Count number of elements in the list\n9.Exit");
			ch = in.nextInt();
			int value = 0;
			int index = 0;
			switch (ch) {
			case 1:
				System.out.println("Enter a value");
				value = in.nextInt();
				list.addToFront(value);
				break;
			case 2:
				System.out.println("Enter a value");
				value = in.nextInt();
				list.addToBack(value);
				break;
			case 3:
				System.out.println("Enter a value");
				value = in.nextInt();
				System.out.println("Enter index");
				index = in.nextInt();
				list.addAtIndex(index,value);
				break;
			case 4:
				list.removeFromFront();
				break;
			case 5:
				list.removeFromBack();
				break;
			case 6:
				System.out.println("Enter the index");
				index = in.nextInt();
				list.removeAtIndex(index);
				break;
			case 7:
				list.printList();
				break;
			case 8:
				list.count();
				break;
			case 9:
				System.exit(0);
				break;
			default:
				System.out.println("Wrong Choice");
				break;
			}
			System.out.println();
		} while (ch != 9);
	}
}
