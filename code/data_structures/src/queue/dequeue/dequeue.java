//  data_structures|queue|dequeue|java
//  Part of Cosmos by OpenGenus Foundation

// Implementation using doubly linked list

public class Dequeue {
    
    private Node head = null;
    private Node tail = null;
    
    public void insertAtHead(int d) {
        Node n = new Node(d);
        n.setNext(head);
        if (head == null) {  
            head = n;
            tail = n;
        } else {
            head.setPrevious(n);
            head = n;
        }
    }
    
    public void insertAtTail(int d) {
        Node n = new Node(d);
        if (tail == null) {
            head = n;
            tail = n;
        } else {
            tail.setNext(n);
            n.setPrevious(tail);
            tail = n;
        }
    }
    
    public int removeHead() {
        if (head == null) {
        	throw new NullPointerException("Underflow");
        }
        int headValue = head.getValue();
        Node newHead = head.getNext();
        if (newHead != null) {
            newHead.setPrevious(null);
        }
        head = newHead;
        return headValue;   
    }
    
    public int removeTail() {
        if (head == null) {
        	throw new NullPointerException("Underflow");
        }
        int tailValue = tail.getValue();
        Node newTail = tail.getPrevious();
        if (newTail != null) {
            newTail.setNext(null);  
        }
        tail = newTail;
        return tailValue;
    }   
    
    public static void main(String args[]) {
        Dequeue dq = new Dequeue();
        for (int i = 1; i <= 10; ++i) {
            dq.insertAtHead(i);
            dq.insertAtTail(-1 * i);
        }

         for (int i = 1; i <= 10; ++i) {
             System.out.println(dq.removeHead());
             System.out.println(dq.removeTail());
             System.out.println("\n");
         }
    }
}

// Class Node 
class Node {
    private int value;
    private Node prev;
    private Node next;
    
    public Node(int data) {
        value = data;
        prev = null;
        next = null;
    }
    
    public Node getPrevious() {
        return prev;
    }
    
    public Node getNext() {
        return next;
    }
    
    public void setPrevious(Node n) {
        this.prev = n;
    }
    
    public void setNext(Node n) {
        this.next = n;
    }
    
    public int getValue() {
        return this.value;
    }
}

