public class Linked_List<T extends Comparable<T>> {

	//class for node of a linked list
	private class Node implements Comparable<Node> {
		T data;
		Node next;

		//constructor
		Node(T data, Node next) {
			this.data = data;
			this.next = next;
		}

		public int compareTo(Linked_List<T>.Node node) {
			return this.data.compareTo(node.data);
		}	
	}

	private Node head;
	private Node tail;
	private int size;

	//constructor
	public Linked_List() {
		this.head = null;
		this.tail = null;
		size = 0;
	}

	//method to get size of the linked list
	public int size() {
		return this.size;
	}

	//method to check if linked list is empty
	public boolean isEmpty() {
		return size() == 0;
	}

	//method to get first element of the linked list
	public T getFirst() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		return this.head.data;
	}

	//method to add new element at beginning of the linked list
	public void addFirst(T data) {
		Node newNode = new Node(data, this.head);
		this.head = newNode;
		if (isEmpty()) {
			this.tail = newNode;
		}
		this.size++;
	}

	//method to remove element from beginning of the linked list
	public T removeFirst() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		T temp = this.head.data;
		this.head = this.head.next;

		if (this.size() == 1)
			this.tail = null;

		size--;
		return temp;
	}

	//method to display linked list from starting to end
	public void display() {
		System.out.println(this);
	}

	public String toString() {
		String retval = "";

		Node temp = this.head;
		while (temp != null) {
			retval += temp.data + " => ";
			temp = temp.next;
		}
		retval += "END";

		return retval;
	}
}
