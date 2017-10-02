/* Part of Cosmos by OpenGenus Foundation */

class SinglyLinkedList{

	private Node head;

	public SinglyLinkedList(){
		head = null;
	}

	public void insertHead(int x){
		Node newNode = new Node(x); //Create a new link with a value attached to it
		newNode.next = head; 		//Set the new link to point to the current head
		head = newNode; 			//Now set the new link to be the head
	}

    Node InsertNth(Node head, int data, int position) {
        
        Node newNode = new Node();
        newNode.data = data;
        
        if (position == 0) {
            newNode.next = head;
            return newNode;
        }

        Node current = head;

        while (--position > 0) {
            current = current.next;
        }
        
        newNode.next = current.next;
        current.next = newNode;
        return head;
    }
    
	public Node deleteHead(){
		Node temp = head;
		head = head.next; //Make the second element in the list the new head, the Java garbage collector will later remove the old head
		return temp;
	}

	public boolean isEmpty(){
		return(head == null);
	}

	public void display(){
		Node current = head;
		while(current!=null){
			System.out.print(current.getValue()+" ");
			current = current.next;
		}
		System.out.println();
	}
	
	public static void main(String args[]){
		SinglyLinkedList myList = new SinglyLinkedList();

		System.out.println(myList.isEmpty()); //Will print true

		myList.insertHead(5);
		myList.insertHead(7);
		myList.insertHead(10);

		myList.display(); // 10(head) --> 7 --> 5

		myList.deleteHead();

		myList.display(); // 7(head) --> 5
	}
}

class Node{
	/** The value of the node */
	public int value;
	/** Point to the next node */
	public Node next; //This is what the link will point to

	public Node(int valuein){
		value = valuein;
	}

	public int getValue(){
		return value;
	}

}
