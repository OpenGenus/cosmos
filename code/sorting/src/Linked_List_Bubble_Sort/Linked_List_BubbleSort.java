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

	public static void bubbleSort(Node head)
	{
    	if(head==null)
        	return;

   	 	bool flag = false;
    	Node ptr1;  //left pointer will always point to the start of the list
    	Node ptr2 = null;  //right pointer will always point to the end of the list

    	while(true)
    	{
        	flag = false;
        	ptr1 = head;

        	while(ptr1.next != ptr2)
        	{
            	if (ptr1.data > ptr1.next.data) 
            	{  
                	swap(ptr1, ptr1.next); 
                	flag = true; 
            	} 
            	ptr1 = ptr1.next;
        	}

        	//as the largest element is at the end of the list, assign that to ptr2 as there is no need to
        	//check already sorted list

        	ptr2 = ptr1;

        	if(flag == false)
        		break; 
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
           
            head = l.mergeSort(head);
            l.printList(head);
            t--;
        }
    }
}