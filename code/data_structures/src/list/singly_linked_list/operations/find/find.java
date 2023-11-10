package linkedlist;

class LinkedList {
    Node head;
    static class Node {
        int data;
        Node next;
        
        Node(int data)  {
            this.data = data;
            next = null;
        }
    }
    
    public void push(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }
    public void printList() {
        Node n = head;
        while(n != null) {
            System.out.print(n.data+" ");
            n = n.next;
        }
    }
    public boolean search(Node head, int x) {
        Node current = head;
        while(current != null) {
            if(current.data == x) {
                return true;
            }
            current = current.next;
        }
        return false; // not found
    }
    public static void main(String args[]) {
        LinkedList ll = new LinkedList();
        ll.push(5);
        ll.push(4);
        ll.push(3);
        ll.push(2);
        if(ll.search(ll.head,1)) {
            System.out.print(" Yes ");
        } else {
            System.out.print(" No ");
        }
        
    }
}
