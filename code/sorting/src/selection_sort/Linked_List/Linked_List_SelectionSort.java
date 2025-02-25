import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}


class LinkedList
{
    public static void swap (Node ptr1, Node ptr2)
	{
    	int temp = ptr1.data;
    	ptr1.data = ptr2.data;
    	ptr2.data = temp;
	}

	public static void selectionSort(Node head)
	{
        if(head==null)
            return;

        Node ptr1 = head;
        Node ptr2,min;

        while(ptr1!=null)
        {
            min = ptr1;    // Initial the current node as minimum node
            ptr2 = ptrt1.next;

            // Traverse for the unsorted part of the linked list 
            while(ptr2)
            {
                if(min.data > ptr2.data)
                    min = ptr2;

                ptr2 = ptr2.next;
            }

            // Swap the minimum element with the current element
            swap(ptr1,min);
            ptr1 = ptr1.next;
        }
    	
	}

    public static void printList(Node head)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + "-->");
            temp = temp.next;
        }
        System.out.print("NULL");
    }

    /*
    Sample Input
    1 - Test cases
    5 - Total number of elements to be inserted in linked list
    23 2 34 5 1 - Adding the contents of the linked list

    Sample Output
    1 2 5 23 34
    */

    public static void main (String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();

        LinkedList l = new LinkedList();
        
        while(t!=0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node temp = head;

            n--;

            while(n!=0){
                temp.next = new Node(sc.nextInt());
                temp = temp.next;
                n--;
            }
           
            l.selectionSort(head);
            l.printList(head);
            t--;
        }
    }
}