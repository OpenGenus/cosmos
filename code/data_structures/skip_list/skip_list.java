// Part of Cosmos by OpenGenus Foundation
import java.util.*;
public class SkipList<E> {
    /** Initialize the random variable */
    static private Random value = new Random(); // Hold the Random class object
    
    /** Create a random number function from the standard Java Random
      class. Turn it into a uniformly distributed value within the
      range 0 to n-1 by taking the value mod n.
      @param n The upper bound for the range.
      @return A value in the range 0 to n-1.
    */
    static int random(int n) {
        return Math.abs(value.nextInt()) % n;
    }
    
    // SkipNode class is a fairly passive data structure
    // that holds the key and value of a dictionary entry
    // and an array of pointers to help implement the skip list.
    private class SkipNode<E> {
        private int key;
        private E element;
        private SkipNode<E>[] forward;
        
        // make a skip node with data, but don't wire it in yet
        public SkipNode( int key, E element, int levels ) {
            this.key = key;
            this.element = element;
            this.forward = (SkipNode<E>[]) new SkipNode[levels+1];
            for (int i = 0; i <= levels; i++)
                this.forward[i] = null;
        }
        
        // make a skip node without data (designed for head node)
        public SkipNode( int levels ) {
            this.key = 0;
            this.element = null;
            this.forward = new SkipNode[levels+1];
            for (int i = 0; i <= levels; i++)
                this.forward[i] = null;
        }
        
        // adjust this node to have newLevel forward pointers.
        // assumes newLevel >= this.forward.length
        public void adjustLevel( int newLevel ) {
            SkipNode[] oldf = this.forward;
            this.forward = new SkipNode[newLevel+1];
            for (int i = 0; i < oldf.length; i++)
                this.forward[i] = oldf[i];
            for (int i = oldf.length; i <= newLevel; i++)
                this.forward[i] = null; // there aren't any nodes this tall yet, so there is nothing to point to
        }

        // Print the contents of the forward vector (I.e. write out who
        // each level is pointing to).
        public void printForward( ) {
            for (int i = this.forward.length-1; i >= 0; i--) {
                if (this.forward[i] == null)
                    System.out.println( "level : " + i + " ----> null" );
                else
                    System.out.println( "level : " + i + " ----> (" + this.forward[i].key() + " : " + this.forward[i].element() + ")");
            }
        }

        // accessors        
        public int key() { return this.key; }
        public E element() { return this.element; }
    }
    
    // Fields!
    private SkipNode head; // first node
    private int level;  // max number of levels in the list
    private int size; // number of data elements in list
    
    public SkipList() {
        // it will start life as a humble linked list.
        this.level = 1;
        // make the head. It will contain no data
        this.head = new SkipNode( this.level );
        this.size = 0;
    }
    
    /** Pick a level using a geometric distribution */
    int randomLevel() {
        //return 1;
      int lev;
      for (lev=0; random(2) == 0; lev++); // Do nothing
      return lev;
    }
    
    // adjust the head to have an array of newLevel levesl
    public void adjustHead(int newLevel) {  
        this.head.adjustLevel( newLevel );
    }
    
    /** Insert a record into the skiplist */
    public void insert(int k, E newValue) {
      int newLevel = randomLevel();  // New node’s level
      if (newLevel > level)          // If new node is deeper
        adjustHead(newLevel);        //   adjust the header
      this.level = newLevel;         // and record new distance.
      // Track end of level
      SkipNode<E>[] update = (SkipNode<E>[]) new SkipNode[level+1];
      SkipNode<E> x = this.head;        // Start at header node
      for (int i=level; i>=0; i--) { // Find insert position
        while((x.forward[i] != null) &&
              (k > x.forward[i].key()))
          x = x.forward[i];
        update[i] = x;               // Track end at level i
      }
      x = new SkipNode<E>(k, newValue, newLevel);
      for (int i=0; i <= newLevel; i++) {      // Splice into list
        x.forward[i] = update[i].forward[i]; // Who x points to
        update[i].forward[i] = x;            // Who y points to
      }
      this.size++;                    // Increment dictionary size
    }

    /** Skiplist Search */
    public E find(int searchKey) {
      SkipNode<E> x = this.head;          // Dummy header node
      for (int i=level; i>=0; i--)       // For each level...
        while ((x.forward[i] != null) && // go forward
               (searchKey > x.forward[i].key()))
          x = x.forward[i];              // Go one last step
      x = x.forward[0];  // Move to actual record, if it exists
      if ((x != null) && (searchKey == x.key()))
        return x.element();              // Got it
      else return null;                  // Its not there
    }
        
    public void printContents() {
        SkipNode ptr = this.head;
        while (true) {
            if (ptr.forward[0] == null)
                break;
            ptr = ptr.forward[0];
            System.out.println( ptr.key() + " : " + ptr.element() );
        }
    }
    
    public void printEverything() {
        SkipNode ptr = this.head;
        System.out.println( "Head Node " );
        ptr.printForward();
        ptr = ptr.forward[0];
        while (ptr != null) {
            System.out.println( "Node (" + ptr.key() + " : " + ptr.element() + ")" );
            ptr.printForward();
            ptr = ptr.forward[0];
        }
    }
    
    public static void main( String[] args ) {
        SkipList<String> sl = new SkipList<String>();
        sl.insert( 1, "One" );
        System.out.println( "\nPrinting the list ");
        //System.out.println( "Printing the header array: ");
        //sl.head.printForward();
        sl.printEverything();
        sl.insert( 4, "Four" );
        sl.insert( 10, "Ten" );
        sl.insert( 3, "Three" );
        sl.insert( 11, "Eleven" );
        System.out.println( "\nPrinting the list ");
        sl.printEverything();
        
        System.out.println( "\nPrinting just the traversal" );
        sl.printContents();
    }

}
