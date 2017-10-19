/**
 * Queue implementation using a singly-linked link.
 * Part of the OpenGenus/cosmos project. (https://github.com/OpenGenus/cosmos)
 * 
 * A queue is a first-in first-out (FIFO) data structure.
 * Elements are manipulated by adding elements to the back of the queue and removing them from 
 * the front.
 */
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

        //Queue variables
        //This queue is implemented as a singly-linked list, where the
        //front of the queue is the first element of the linked list, 
        //and the back of the queue is the last element of the linked list.
        private Node front;
        private Node rear;
        public int Size { get; private set; }

        public Queue()
        {
            front = null;
            rear = null;
            Size = 0;
        }

        //Adds an element to the back of the queue.
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

        //Removes and returns the element at the front of the queue.
        //Throws an exception if the queue is empty.
        public T Dequeue()
        {
            if(IsEmpty())
            {
                throw new InvalidOperationException("Cannot dequeue on an empty queue!");
            }

            Node tmp = front;
            front = tmp.next;
            Size--;

            if(front == null)
            {
                rear = null;
            }

            return tmp.data;
        }

        //Returns the element at the front of the queue.
        //Throws an exception if the queue is empty.
        public T Front()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException("The queue is empty!");
            }

            return front.data;
        }

        //Returns true if queue contains no elements, false otherwise.
        public bool IsEmpty()
        {
            return front == null && rear == null;
        }

        //Returns a string representation of the queue.
        public override string ToString()
        {
            Node tmp = front;
            string result = "Queue([Front] ";

            while(tmp != null)
            {
                result += tmp.data;
                tmp = tmp.next;

                if (tmp != null)
                {
                    result += " -> ";
                }
            }

            result += " [Back])";
            return result;
        }
    }

    //Stack testing methods/class.
    public class QueueTest
    {
        static void Main(string[] args)
        {
            var strQueue = new Queue<string>();

            Console.WriteLine("Setting up queue...");
            strQueue.Enqueue("Marth");
            strQueue.Enqueue("Ike");
            strQueue.Enqueue("Meta Knight");
            Console.WriteLine(strQueue.ToString());

            Console.WriteLine("Removing first element...");
            strQueue.Dequeue();
            Console.WriteLine(strQueue.ToString());
            Console.ReadKey();
        }
    }
}
