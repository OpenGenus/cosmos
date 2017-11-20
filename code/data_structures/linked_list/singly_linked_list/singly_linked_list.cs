namespace LinkedList
{
    class Node<T>
    {
        // properties
        private T value;
        private Node<T> nextNode;


        // constructors
        public Node(T value, Node<T> nextNode)
        {
            this.value = value;
            this.nextNode = nextNode;
        }

        public Node(T value)
        {
            this.value = value;
            this.nextNode = null;
        }

        public Node()
        {
            this.value = default(T);
            this.nextNode = null;
        }


        // getters
        public T getValue()
        {
            return this.value;
        }

        public Node<T> getNextNode()
        {
            return nextNode;
        }


        // setters
        public void setValue(T value)
        {
            this.value = value;
        }

        public void setNextNode(Node<T> nextNode)
        {
            this.nextNode = nextNode;
        }


        // sets the current object to the next node
        // in the linked list
        public void setNext()
        {
        	if(this.nextNode == null)
				throw new Exception("Trying to move to null node");
			else
			{
				this.value = nextNode.value;
				this.nextNode = nextNode.nextNode;
			}
        }

        public override string ToString()
        {
            return value.ToString();
        }
    }

    class LinkedList<T>
    {
        // properties
        private Node<T> head = null;

        // constructors
        public LinkedList()
        {
            // empty
        }

        // random access
        public T getValue(int index)
        {
            Node<T> node = head;

            for(int i = 0 ; i < index ; i++)
            {
                node.setNext();
            }

            return node.getValue();
        }

		// overriding the index operator
        public T this[int index]
        {
            get{return getValue(index);}
        }

        // the amount of items in the list
        public int count()
        {
            int counter = 0;
            Node<T> node = head;

            while(node.getNextNode() != null)
            {
                node.setNext();
                counter++;
            }

            return counter;

        }

        // removes a node from the list
        public void remove(int index)
        {
			Node<T> node = head;

            for(int i = 0 ; i < index - 1 ; i++)
            {
                node.setNext();
            }

            node.setNextNode(node.getNextNode().getNextNode());
        }

        // ToString method
        public override string ToString()
        {
            string s = "";
            Node<T> node = head;

            while(node != null || node.getNextNode() != null)
            {
                s += node.getValue().ToString() + '\n';
                node.setNext();
            }

            return s;
        }

        // returns the head node
        public Node<T> getHeadNode()
        {
            return head;
        }


        // add a value to the end
        public void append(T value)
        {
            Node<T> node = head;
            Node<T> newNode = new Node<T>(value);

			if(head == null)
			{
				head = newNode;
			}
			else
			{
				while(node.getNextNode() != null)
					node.setNext();
				node.setNextNode(node);
			}
        }

        // insert a node in the middle
        public void insert(int index, T value)
        {
            Node<T> node = head;
            Node<T> newNode = new Node<T>(value);

            for(int i = 0 ; i < index - 1; i++)
            {
                node.setNext();
            }

            newNode.setNextNode(node.getNextNode());
            node.setNextNode(newNode);
        }
    }
}
