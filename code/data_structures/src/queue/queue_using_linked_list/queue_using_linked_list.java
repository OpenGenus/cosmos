class Node<T> //NODE CLASS
{
    T data;
    Node<T> next;
}
// Part of Cosmos by OpenGenus Foundation
//Queue Using linked list
public class QueueUsingLL<T> {

	private Node<T> front; // Front Node
	private Node<T> rear;  // Rear Node
	private int size;


	public int size(){
		return size;
	}

    //Returns TRUE if queue is empty
	public boolean isEmpty(){
		return size() == 0;
	}

	public T front() {

		return front.data;
	}

	public void enqueue(T element){     //to add an element in queue
		Node<T> newNode = new Node<>();
		newNode.data = element;
		if(rear == null){
			front = newNode;
			rear = newNode;
		}
		else{
			rear.next = newNode;
			rear = newNode;
		}
		size++;

	}

	public T dequeue() {    //to remove an element from queue

		T temp = front.data;
		if(front.next == null){
			front = null;
			rear = null;
		}
		else{
			front = front.next;
		}
		size--;
		return temp;

	}

	public static class QueueUse
    {
        //Main Function to implement Queue
        public static void main(String[] args) {
            QueueUsingLL<Integer> queueUsingLL=new QueueUsingLL<>();
            for(int i=1;i<=10;i++) // Creates a dummy queue which contains integers from 1-10
            {
             queueUsingLL.enqueue(i);
            }

            System.out.println("QUEUE :");

            while (!queueUsingLL.isEmpty())
            {
                System.out.println(queueUsingLL.dequeue());
            }
        }
    }


}
