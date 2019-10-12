import java.util.*;
public class LinkedList {
    private static final Scanner sc = new Scanner(System.in);

    Node head;

    class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public void push(int new_data) {
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }

    public void insertAfter(Node prev_node, int new_data) {
        if (prev_node == null) {
            System.out.println("The previous node cannot be NULL");
            return;
        }
        Node new_node = new Node(new_data);
        new_node.next = prev_node.next;
        prev_node.next = new_node;
    }

    public void append(int new_data) {
        Node new_node = new Node(new_data);
        if(head == null) {
            head = new Node(new_data);
            return;
        }
        new_node.next = null;
        Node last = head;
        while(last.next != null)
            last = last.next;
        last.next = new_node;
        return;
    }

    public void printList() {
        Node tnode = head;
        while (tnode != null) {
            System.out.print(tnode.data + " ");
            tnode = tnode.next;
        }
    }

    public void deleteNode(int key) {
        //Store head node
        Node temp_node = head;
        Node prev_node = null;

        //If head has the key to be deleted
        if(temp_node != null && temp_node.data == key) {
            head = temp_node.next;
            return;
        }

        //Search for key to be deleted
        while (temp_node != null && temp_node.data != key) {
            prev_node = temp_node;
            temp_node = temp_node.next;
        }

        //If key is not present in LL
        if(temp_node == null)
            return;

        prev_node.next = temp_node.next;
    }

    public void deleteNodeAtPos(int position) {
        //If LL is empty
        if(head == null)
            return;
        //Store head node
        Node temp_node = head;

        //If head needs to be removed
        if(position == 0) {
            head = temp_node.next;
            return;
        }

        //Find previous node of the node to be deleted
        for (int i=0; temp_node!=null && i<position-1; i++)
            temp_node = temp_node.next;

        //If position is more than number of nodes
        if(temp_node == null || temp_node.next == null)
            return;

        Node next_node = temp_node.next.next;
        temp_node.next = next_node;
    }

    public boolean search(Node head, int x) {
        Node current_node = head;
        while(current_node!=null) {
            if(current_node.data == x)
                return true;
            current_node = current_node.next;
        }
        return false;
    }

    public static void main(String[] args) {
        LinkedList lllist = new LinkedList();
    }
}
