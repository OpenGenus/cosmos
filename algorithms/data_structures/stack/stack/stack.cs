/**
 * Stack implementation using a singly-linked link.
 * Part of the OpenGenus/cosmos project. (https://github.com/OpenGenus/cosmos)
 * 
 * A stack is a first-in first-out (FIFO) data structure.
 * Elements are manipulated by adding and removing elements of the top of the stack.
 */
using System;

namespace Cosmos_Data_Structures
{
    public class Stack<T>
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

        private Node top;
        public int Size { get; private set; }

        public Stack()
        {
            top = null;
            Size = 0;
        }

        //Add element to the top of the stack.
        public void Push(T element)
        {
            var newNode = new Node(element, top);
            top = newNode;
            Size++;
        }

        //Gets element at the top of the stack.
        //Throws an exception if the stack is empty.
        public T Peek()
        {
            if(IsEmpty())
            {
                throw new InvalidOperationException("Cannot peek on an empty stack!");
            }

            return top.data;
        }

        //Removes and returns the element at the top of the stack.
        //Throws an exception if the stack is empty.
        public T Pop()
        {
            if(IsEmpty())
            {
                throw new InvalidOperationException("Cannot pop on an empty stack!");
            }

            var oldTop = top;
            top = top.next;
            Size--;
            return oldTop.data;
        }

        //Returns true if stack contains no elements, false otherwise.
        public bool IsEmpty()
        {
            return top == null;
        }

        //Returns a string representation of the stack.
        public override string ToString()
        {
            Node tmp = top;
            string result = "Stack([Top] ";

            while(tmp != null)
            {
                result += tmp.data;
                tmp = tmp.next;

                if(tmp != null)
                {
                    result += " -> ";
                }
            }

            result += ")";
            return result;
        }
    }

    //Stack testing methods/class.
    public class StackTest
    {
        static void Main(string[] args)
        {
            Console.Write("Creating stack...");
            var intStack = new Stack<int>();

            for (int i = 0; i < 10; i++)
            {
                intStack.Push(i);
            }
            Console.WriteLine("done");

            Console.WriteLine(intStack.ToString());
            Console.WriteLine("Size of stack: " + intStack.Size);
            Console.WriteLine("Topmost element is " + intStack.Peek() + ".\n");

            Console.Write("Removing elements...");
            for (int i = 0; i < 3; i++)
            {
                intStack.Pop();
            }
            Console.WriteLine("done");

            Console.WriteLine(intStack.ToString());
            Console.WriteLine("Size of stack: " + intStack.Size);
            Console.WriteLine("Topmost element is " + intStack.Peek() + ".\n");

            Console.WriteLine("Press any key to continue.");
            Console.ReadKey();
        }
    }
}
