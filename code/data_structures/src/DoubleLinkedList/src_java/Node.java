/*

// data structures | DoubleLinkedList | src java | Node | JAVA
// Part of Cosmos by OpenGenus Foundation

*/


public class Node{
    int data;
    Node prev, next;
    Node(Node prev, int data, Node next){
        this.prev= prev;
        this.data= data;
        this.next= next;
    }
}
