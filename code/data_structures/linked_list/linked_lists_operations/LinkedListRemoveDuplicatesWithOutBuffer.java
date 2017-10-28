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

class LinkedListRemoveDuplicatesWithOutBuffer {

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

        if (list.head==null)
            return;

        DoublyNode j;
        DoublyNode tail = list.head.next;

        for (DoublyNode i = list.head.next; i!=null; i = i.next) {
            for (j = list.head; j!=i; j = j.next) {
                if (j.getdata()==i.getdata())
                    break;
            }
            if (j==i) {
                tail.setData(i.getdata());
                tail = tail.next;
            }
        }
        
        tail.prev.next=null;

        System.out.println("After removing duplicates, the list is :-");    
        list.print();
    }
    
}
