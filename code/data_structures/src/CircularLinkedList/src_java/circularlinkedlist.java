class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    private Node head;

    // Constructor to create an empty circular linked list
    CircularLinkedList() {
        head = null;
    }

    // Function to insert a node at the end of the circular linked list
    void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head; // Point back to itself for a single node circular list
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
    }

    // Function to delete a node by value from the circular linked list
    void delete(int data) {
        if (head == null)
            return;

        // If the head node contains the value to be deleted
        if (head.data == data) {
            Node temp = head;
            while (temp.next != head)
                temp = temp.next;
            if (head == head.next) {
                head = null; // If there is only one node
            } else {
                head = head.next;
                temp.next = head;
            }
            return;
        }

        // Search for the node to delete
        Node current = head;
        Node prev = null;
        while (current.next != head && current.data != data) {
            prev = current;
            current = current.next;
        }

        // If the node with the given data was found
        if (current.data == data) {
            prev.next = current.next;
        } else {
            System.out.println("Node with data " + data + " not found in the list.");
        }
    }

    // Function to display the circular linked list
    void display() {
        if (head == null)
            return;

        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) {
        CircularLinkedList cll = new CircularLinkedList();
        cll.append(1);
        cll.append(2);
        cll.append(3);

        System.out.print("Circular Linked List: ");
        cll.display(); // Output: 1 2 3

        cll.delete(2);
        System.out.print("After deleting 2: ");
        cll.display(); // Output: 1 3
    }
}
