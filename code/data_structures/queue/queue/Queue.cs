using System;

namespace Cosmos_Data_Structures
{
    public class Queue<T>
    {
        //Node is a element that holds the data of the current element plus a reference to the next element.
        //Used to implement the singly-linked list.
        private class Node
        {
            public T data;
            public Node next;

            public Node(T data, Node next)
            {
                this.data = data;
                this.next = next;
            }
        }

        private Node front;
        private Node rear;
        public int Size { get; private set; }

        public Queue()
        {
            front = null;
            rear = null;
            Size = 0;
        }

        public void Enqueue(T element)
        {
            Node tmp = new Node(element, null);

            if(IsEmpty())
            {
                front = tmp;
                rear = tmp;
            }
            else
            {
                rear.next = tmp;
                rear = tmp;
            }

            Size++;
        }

        public T Dequeue()
        {
            Node tmp = front;
            front = tmp.next;
            Size--;

            if(front == null)
            {
                rear = null;
            }

            return tmp.data;
        }

        public bool IsEmpty()
        {
            return front == null && rear == null;
        }

        public override string ToString()
        {
            return "";
        }
    }

    public class QueueTest
    {
        static void Main(string[] args)
        {
            var strQueue = new Queue<string>();

            strQueue.Enqueue("Marth");
            strQueue.Enqueue("Ike");
            strQueue.Enqueue("Meta Knight");

            strQueue.Dequeue();
        }
    }
}
