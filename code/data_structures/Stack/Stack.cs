using System;

namespace Cosmos_Data_Structures
{
    public class Stack<T>
    {
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

        public void push(T element)
        {
            var newNode = new Node(element, top);
            top = newNode;
            Size++;
        }

        public T peek()
        {
            if (top == null)
            {
                throw new InvalidOperationException("Cannot peek on an empty stack!");
            }

            return top.data;
        }

        public T pop()
        {
            if(top == null)
            {
                throw new InvalidOperationException("Cannot pop on an empty stack!");
            }

            var oldTop = top;
            top = top.next;
            Size--;
            return oldTop.data;
        }

        public bool isEmpty()
        {
            return top == null;
        }

        public override string ToString()
        {
            Node tmp = top;
            string result = "Stack(";

            while(tmp != null)
            {
                result += tmp.data;
                tmp = tmp.next;

                if(tmp != null)
                {
                    result += ",";
                }
            }

            result += ")";
            return result;
        }
    }

    public class StackTest
    {
        static void Main(string[] args)
        {
            Console.Write("Creating stack...");
            var intStack = new Stack<int>();

            for (int i = 0; i < 10; i++)
            {
                intStack.push(i);
            }
            Console.WriteLine("done");

            Console.WriteLine(intStack.ToString());
            Console.WriteLine("Size of stack: " + intStack.Size);
            Console.WriteLine("Topmost element is " + intStack.peek() + ".\n");

            Console.Write("Removing elements...");
            for (int i = 0; i < 3; i++)
            {
                intStack.pop();
            }
            Console.WriteLine("done");

            Console.WriteLine(intStack.ToString());
            Console.WriteLine("Size of stack: " + intStack.Size);
            Console.WriteLine("Topmost element is " + intStack.peek() + ".\n");

            Console.WriteLine("Press any key to continue.");
            Console.ReadKey();
        }
    }
}
