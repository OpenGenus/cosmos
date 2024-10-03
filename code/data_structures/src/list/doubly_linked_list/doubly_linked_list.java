import java.util.*;

/* An implementation of Doubly Linked List of integer type */

/* Methods : 
   1. Insert a particular value at a particular position
   2. Delete node at a particular position
   3. Traverse the list in forward direction
   4. Traverse the list in reverse direction
   */


class Node {
	public Node next;
	public Node prev;
	int data;

	public Node(int data){
		this.data = data;
	}
}

class DoublyLinkedList {
	private Node first;
	private Node last;
	private int n = 0;  //size

	/*-----Insert Method-----*/
	public void insert(int pos, int data){
		if (pos > n + 1){
			pos = n + 1;
		}

		Node newNode = new Node(data);

		if (first == null) {
			first = newNode;
			last = first;
			n++;
			return;
		}

		if (pos == 1){
			newNode.next = first;
			first.prev = newNode;
			first = newNode;
			n++;
			return;
		}

		if (pos == n + 1){
			newNode.prev = last;
			last.next = newNode;
			last = newNode;
			n++;
			return;
		}

		int c = 1;
		Node cur = first;

		while (c != pos){
			c++;
			cur = cur.next;
		}

		newNode.next = cur;
		newNode.prev = cur.prev;
		cur.prev.next = newNode;
		cur.prev = newNode;
		n++;

	}

	/*-----Delete Method-----*/
	public void delete(int pos){
		if (n == 0) {
			System.out.println("List is Empty!");
			return;
		}

		if(pos > n) {
			pos = n;
		}

		if (pos == 1) {
			first = first.next;
			first.prev = null;
			return;
		}

		int c = 1;
		Node cur = first;

		while (c != pos) {
			c++;
			cur = cur.next;
		}

		if (cur.prev != null) {
			cur.prev.next = cur.next;
		}
		if (cur.next != null) {
			cur.next.prev = cur.prev;
		}
		n--;
	}

	/*-----Print in forward direction-----*/
	public void display() {
		Node cur = first;

		while (cur != null) {
			System.out.print(cur.data + "->");
			cur = cur.next;
		}

		System.out.println("null");
	}

	/*-----Print in reverse direction-----*/
	public void reverseDisplay() {
		Node cur = last;

		while (cur != null) {
			System.out.print(cur.data + "->");
			cur = cur.prev;
		}

		System.out.println("null");
	}
}

class App {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		DoublyLinkedList l = new DoublyLinkedList();

		while (true) {
			System.out.println("1.Insert");
			System.out.println("2.Delete");
			System.out.println("3.Print");
			System.out.println("4.Print in reverse order");
			System.out.println("5.Exit");

			int c = sc.nextInt();

			switch(c) {
				case 1:
					System.out.println("Enter insertion position");
					int pos = sc.nextInt();
					System.out.println("Enter value");
					int val = sc.nextInt();
					l.insert(pos, val);
					break;
				case 2:
					System.out.println("Enter deletion position");
					pos = sc.nextInt();
					l.delete(pos);
					break;
				case 3:
					l.display();
					break;
				case 4:
					l.reverseDisplay();
					break;
				case 5:
					return;
				default:
					return;
			}
		}
	}
}



