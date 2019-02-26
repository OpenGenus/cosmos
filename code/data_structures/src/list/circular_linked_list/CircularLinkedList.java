import java.util.Scanner;

// Part of Cosmos by OpenGenus Foundation
public class CircularLinkedList {

    Node head, tail;

    // Node Class
    class Node {
        int value;
        Node next;

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    // Manipulation Methods
    public void Add(int value) {
        Node n = new Node(value, head);
        if (head == null) {
            head = n;
            tail = n;
            n.next = n;
        }
        else {
            tail.next = n;
            tail = n;
        }
    }

    public void Remove(int value) {
        Node aux = head;
        Node prev = tail;
        boolean found = false;

        // Find the node with the value
        if (aux == null) return;
        if (aux == head && aux.value == value) { found = true; }
        else {
            prev = aux;
            aux = aux.next;
            while (aux != head) {
                if (aux.value == value) {
                    found = true;
                    break;
                }
                prev = aux;
                aux = aux.next;
            }
        }

        // If found, remove it
        if (!found) return;
        if (aux == head && aux == tail) { head = tail = null; }
        else {
            if (aux == head) head = aux.next;
            if (aux == tail) tail = prev;
            prev.next = aux.next;
        }
    }

    public void Print() {
        if (head == null) return;
        System.out.print(head.value + " ");
        Node aux = head.next;
        while (aux != head) { System.out.print(aux.value + " "); aux = aux.next; }
        System.out.println();
        System.out.println("HEAD is " + head.value);
        System.out.println("TAIL is " + tail.value);
    }

    // Example Usage
    public static void main(String[] args) {
        int selection = 0;
        Scanner input = new Scanner(System.in);
        CircularLinkedList list = new CircularLinkedList();

        do {
            System.out.print("1. Insert\n2. Remove\n3. Print\n> ");
            selection = input.nextInt();

            if (selection == 1) {
                System.out.print("Enter Value to Insert: ");
                int value = input.nextInt();
                list.Add(value);
                list.Print();
                System.out.print("\n");
            }
            else if (selection == 2) {
                System.out.print("Enter Value to Remove: ");
                int value = input.nextInt();
                list.Remove(value);
                list.Print();
                System.out.println("\n");
            }
            else if (selection == 3) {
                list.Print();
                System.out.println("\n");
            }
            else {
                System.out.println("Invalid Selection. Exiting");
            }
        }
        while (selection > 0 && selection < 4);
        input.close();
    }
}
