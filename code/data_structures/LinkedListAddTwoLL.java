import java.io.*;
import java.util.*;

class SinglyLL {

    SinglyNode head = null;
    SinglyNode last = null;

    void add(SinglyNode n) {

        if (head==null) {
            head=n;
            last=n;
        }

        else {
            last.next = n;
            last=n;
        }
    }

    void print() {

        for (SinglyNode temp=head;temp!=null;temp=temp.next) {
            System.out.print(temp.getdata()+" -> ");
        }
        System.out.println("NULL");
    }
}

class SinglyNode {

    private int data;
    SinglyNode next;

    SinglyNode(int n) {
        data=n;
        next=null;
    }

    int getdata() {
        return this.data;
    }

    void setData(int n) {
        this.data = n;
    }
}

class LinkedListAddTwoLL {

	public static void main(String args[]) {

        SinglyLL dlist1 = new SinglyLL();
        SinglyLL dlist2 = new SinglyLL();

        int input=1;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter -1 to stop input");

        while (input!=-1) {
            System.out.print("Enter value to add to first linked list : ");
            input = in.nextInt();
            if (input!=-1) {
                dlist1.add(new SinglyNode(input));
            }
        }

        System.out.print("First linked list : ");
        dlist1.print();
        System.out.println();

        input=1;
        while (input!=-1) {
            System.out.print("Enter value to add to second linked list : ");
            input = in.nextInt();
            if (input!=-1) {
                dlist2.add(new SinglyNode(input));
            }
        }

        System.out.print("Second linked list : ");
        dlist2.print();
        System.out.println();

        SinglyLL result = new SinglyLL();
        int carry=0;
        for (SinglyNode temp1 = dlist1.head, temp2 = dlist2.head;temp1!=null && temp2!=null;
             temp1=temp1.next,temp2=temp2.next) {

            int sum = carry+temp1.getdata()+temp2.getdata();

            if (sum >= 10) {
                carry=1;
                SinglyNode value = new SinglyNode(sum-10);
                result.add(value);
            }

            else {
                carry=0;
                SinglyNode value = new SinglyNode(sum);
                result.add(value);
            }

        }

        System.out.println("Result of the addition is :-");
        result.print();

	}
}
