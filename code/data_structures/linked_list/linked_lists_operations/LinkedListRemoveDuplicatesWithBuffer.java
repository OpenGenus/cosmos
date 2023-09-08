import java.io.*;
import java.util.*;

class DoublyNode {
    private int data;
    DoublyNode next, prev;

    DoublyNode(int n) {
        data=n;
        next=null;
        prev=null;
    }

    int getdata() {
        return this.data;
    }

    void setData(int n) {
        this.data = n;
        return;
    }

    boolean equals(DoublyNode a) {
        if (this.getdata() == a.getdata())
            return true;
        else
            return false;
    }
}

class DoublyLL {
    DoublyNode head = null;
    DoublyNode last = null;

    void add(DoublyNode n) {

        if (head==null) {
            head=n;
            last=n;
        }

        else {
            last.next = n;
            n.prev = last;
            last=n;
        }
    }

    void print() {

        for (DoublyNode temp=head;temp!=null;temp=temp.next) {
            System.out.print(temp.getdata()+" -> ");
        }
        System.out.println("NULL");
    }
}

class LinkedListRemoveDuplicatesWithBuffer {

    public static void main(String args[]) {
        
        DoublyLL list = new DoublyLL();
        int input=1;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter 0 to stop input");

        while (input!=0) {
            System.out.print("Enter value to add to linked list : ");
            input = in.nextInt();
            if (input!=0) {
                list.add(new DoublyNode(input));
            }

        }

        HashSet<Integer> elements = new HashSet<>();

        for (DoublyNode temp = list.head;temp != null; temp = temp.next) {
            if (elements.contains(temp.getdata())) {
                temp.prev.next = temp.next;
                if (temp.next != null)
                    temp.next.prev = temp.prev;
            }
            else {
                elements.add(temp.getdata());
            }
        }

        System.out.println("After removing duplicates, the list is :-");
        list.print();
    }
    
}
