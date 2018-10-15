package linkedlist;

class LinkedList {
    Node head;
    
    static class Node {
        int data;
        Node next;
        
        Node(int data) {
            this.data = data;
            next = null;
        }
    }
    
    public void printList() {
        Node n = head;
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
    }
    
    public void delete(int key) {
        Node temp = head,prev = null;
        while(temp!=null && temp.data == key) {
            head = temp.next;
            return;
        }
        while(temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        
        if(head == null)return;
        
        prev.next = temp.next;
    }
    
    public void push(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }
    
    public static void main(String args[]) {
        LinkedList ll = new LinkedList();
        ll.push(1);
        ll.push(2);
        ll.printList();
        System.out.println();
        ll.delete(1);
        ll.printList();
    }
}
