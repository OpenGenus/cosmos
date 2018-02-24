//  data_structures|queue|dequeue|Java
//  Part of Cosmos by OpenGenus Foundation

// Implementation using doubly linked list

public class Dequeue {
    
    private Node front = null;
    private Node rear = null;
    
    public void insertAtFront(int d) {
        Node n = new Node(d);
        n.setNext(front);
        
        if (front == null) {  
            front = n;
            rear = n;
        } else {
            front.setPrevious(n);
            front = n;
        }
    }
    
    public void insertAtRear(int d) {
        Node n = new Node(d);

        if (rear == null) {
            front = n;
            rear = n;
        } else {
            rear.setNext(n);
            n.setPrevious(rear);
            rear = n;

        }
    }
    
    public int removeFront() {
        if (front == null) {
            System.out.println("Underflow");
            return -1;
        }
        int frontValue = front.getValue();
        Node newFront = front.getNext();

        if(newFront!=null)  {
             newFront.setPrevious(null);
        }
   
        front = newFront;
        return frontValue;
    }
    
    public int removeRear() {
        if (front == null) {
            System.out.println("Underflow");
            return -1;
        }

        int rearValue =  rear.getValue();
        Node newRear = rear.getPrevious();

        if(newRear!=null){
             newRear.setNext(null);  
        }
        rear = newRear;
        return rearValue;
    }   
    
    public static void main(String args[]) {
        Dequeue dq = new Dequeue();
        for(int i = 1; i <= 10; ++i){
            dq.insertAtFront(i);
            dq.insertAtRear(-1*i);
        }

         for(int i = 1; i <= 10; ++i) {
             System.out.println(dq.removeFront());
             System.out.println(dq.removeRear());
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

