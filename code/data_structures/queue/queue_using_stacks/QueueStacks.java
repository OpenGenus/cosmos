import java.util.NoSuchElementException;
import java.util.Stack;

/**
 * Implements https://docs.oracle.com/javase/8/docs/api/java/util/Queue.html
 * Big O time complexity: O(n)
 * Part of Cosmos by OpenGenus Foundation
 */
class Queue<T> {
    Stack<T> temp = new Stack<>();
    Stack<T> value = new Stack<>();

    public Queue<T> enqueue(T element) {
        add(element);
        return this;
    }

    public T dequeue() {
        return remove();
    }

    /**
     *
     * Inserts the specified element into this queue if it is possible to do so immediately without violating capacity
     * restrictions, returning true upon success and throwing an IllegalStateException if no space is currently available.
     * @param item the element to add
     * @return  true upon success, throwing an IllegalStateException if no space is currently available.
     */
    public boolean add(T item) {
        if (value.isEmpty()) {
            value.push(item);
        } else {
            while (!value.isEmpty()) {
                temp.push(value.pop());
            }

            value.push(item);

            while (!temp.isEmpty()) {
                value.push(temp.pop());
            }
        }
        return true;
    }

    /**
     * Inserts the specified element into this queue if it is possible to do so immediately without violating capacity
     * restrictions.
     * @param element the element to add
     * @return true if the element was added to this queue, else false
     */
    public boolean offer(T element) {
        try {
            return add(element);
        } catch (Exception ex) {
            //failed to add, return false
            return false;
        }
    }

    /**
     * Retrieves and removes the head of this queue.
     * This method differs from poll only in that it throws an exception if this queue is empty.
     * @return the head of this queue.
     * @throws NoSuchElementException if this queue is empty
     */
    public T remove() throws NoSuchElementException{
        try {
            return value.pop();
        } catch (Exception ex) {
            throw new NoSuchElementException();
        }
    }

    /**
     * Retrieves and removes the head of this queue, or returns null if this queue is empty.
     * This method differs from peek only in that it throws an exception if this queue is empty.
     * @return the head of this queue, or returns null if this queue is empty.
     */
    public T poll() {
        try {
            return remove();
        } catch (Exception ex) {
            //failed to remove, return null
            return null;
        }
    }

    /**
     * Retrieves, but does not remove, the head of this queue.
     * @return the head of this queue
     * @throws NoSuchElementException if this queue is empty
     */
    public T element() throws NoSuchElementException{
        try {
            return value.peek();
        } catch (Exception ex) {
            throw new NoSuchElementException();
        }
    }

    /**
     * Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
     * @return the head of this queue, or returns null if this queue is empty.
     */
    public T peek() {
        try {
            return value.peek();
        } catch (Exception ex) {
            //failed to remove, return null
            return null;
        }
    }

    /**
     * Methods standard queue inherits from interface java.util.Collection
     */

    public boolean isEmpty() {
        return value.isEmpty();
    }
}

public class QueueStacks
{
    /**
     * Main function to show the use of the queue
     */
    public static void main(String[] args) {
        Queue<Integer> queueStacks = new Queue<>();
        for(int i=1; i<=10; i++) // Creates a dummy queue which contains integers from 1-10
        {
            queueStacks.enqueue(i);
        }

        System.out.println("QUEUE :");

        while (!queueStacks.isEmpty())
        {
            System.out.println(queueStacks.dequeue());
        }
    }
}

