public class RedBlackTree {
// Part of Cosmos by OpenGenus Foundation
    public RedBlackTree( ) {
        header      = new RedBlackNode( null );
        header.left = header.right = nullNode;
    }

    private final int compare( Comparable item, RedBlackNode t ) {
        if( t == header )
            return 1;
        else
            return item.compareTo( t.element );
    }

    public void insert( Comparable item ) {
        current = parent = grand = header;
        nullNode.element = item;

        while( compare( item, current ) != 0 ) {
            great = grand; grand = parent; parent = current;
            current = compare( item, current ) < 0 ?
                current.left : current.right;

            if( current.left.color == RED && current.right.color == RED )
                handleReorient( item );
        }

        if( current != nullNode )
            throw new DuplicateItemException( item.toString( ) );
        current = new RedBlackNode( item, nullNode, nullNode );

        if( compare( item, parent ) < 0 )
            parent.left = current;
        else
            parent.right = current;
        handleReorient( item );
    }

    public void remove( Comparable x ) {
        throw new UnsupportedOperationException( );
    }

    public Comparable findMin( ) {
        if( isEmpty( ) )
            return null;

        RedBlackNode itr = header.right;

        while( itr.left != nullNode )
            itr = itr.left;

        return itr.element;
    }

    public Comparable findMax( ) {
        if( isEmpty( ) )
            return null;

        RedBlackNode itr = header.right;

        while( itr.right != nullNode )
            itr = itr.right;

        return itr.element;
    }

    public Comparable find( Comparable x ) {
        nullNode.element = x;
        current = header.right;

        for( ; ; ) {
            if( x.compareTo( current.element ) < 0 )
                current = current.left;
            else if( x.compareTo( current.element ) > 0 )
                current = current.right;
            else if( current != nullNode )
                return current.element;
            else
                return null;
        }
    }

    public void makeEmpty( ) {
        header.right = nullNode;
    }

    public void printTree( ) {
        printTree( header.right );
    }

    private void printTree( RedBlackNode t ) {
        if( t != nullNode ) {
            printTree( t.left );
            System.out.println( t.element );
            printTree( t.right );
        }
    }

    public boolean isEmpty( ) {
        return header.right == nullNode;
    }

    private void handleReorient( Comparable item ) {
        current.color = RED;
        current.left.color = BLACK;
        current.right.color = BLACK;

        if( parent.color == RED )
        {
            grand.color = RED;
            if( ( compare( item, grand ) < 0 ) !=
                    ( compare( item, parent ) < 0 ) )
                parent = rotate( item, grand );
            current = rotate( item, great );
            current.color = BLACK;
        }
        header.right.color = BLACK;
    }

    private RedBlackNode rotate( Comparable item, RedBlackNode parent ) {
        if( compare( item, parent ) < 0 )
            return parent.left = compare( item, parent.left ) < 0 ?
                rotateWithLeftChild( parent.left )  :
                rotateWithRightChild( parent.left ) ;
        else
            return parent.right = compare( item, parent.right ) < 0 ?
                rotateWithLeftChild( parent.right ) :
                rotateWithRightChild( parent.right );
    }

    private static RedBlackNode rotateWithLeftChild( RedBlackNode k2 ) {
        RedBlackNode k1 = k2.left;
        k2.left = k1.right;
        k1.right = k2;
        return k1;
    }

    private static RedBlackNode rotateWithRightChild( RedBlackNode k1 ) {
        RedBlackNode k2 = k1.right;
        k1.right = k2.left;
        k2.left = k1;
        return k2;
    }

    private static class RedBlackNode {
        RedBlackNode( Comparable theElement ) {
            this( theElement, null, null );
        }

        RedBlackNode( Comparable theElement, RedBlackNode lt, RedBlackNode rt ) {
            element  = theElement;
            left     = lt;
            right    = rt;
            color    = RedBlackTree.BLACK;
        }

        Comparable   element;
        RedBlackNode left;
        RedBlackNode right;
        int          color;
    }

    private RedBlackNode header;
    private static RedBlackNode nullNode;
    static
    {
        nullNode = new RedBlackNode( null );
        nullNode.left = nullNode.right = nullNode;
    }

    private static final int BLACK = 1;
    private static final int RED   = 0;


    private static RedBlackNode current;
    private static RedBlackNode parent;
    private static RedBlackNode grand;
    private static RedBlackNode great;


    // MAIN TO TEST FOR ERRORS
    public static void main( String [ ] args ) {
        RedBlackTree t = new RedBlackTree( );
        final int NUMS = 400000;
        final int GAP  =  35461;

        System.out.println( "Checking... (no more output means success)" );

        for( int i = GAP; i != 0; i = ( i + GAP ) % NUMS )
            t.insert( new Integer( i ) );

        if( ((Integer)(t.findMin( ))).intValue( ) != 1 ||
                ((Integer)(t.findMax( ))).intValue( ) != NUMS - 1 )
            System.out.println( "FindMin or FindMax error!" );

        for( int i = 1; i < NUMS; i++ )
            if( ((Integer)(t.find( new Integer( i ) ))).intValue( ) != i )
                System.out.println( "Find error1!" );
    }

    private class DuplicateItemException extends RuntimeException
    {
        public DuplicateItemException( )
        {
            super( );
        }

        public DuplicateItemException( String message )
        {
            super( message );
        }
    }
}
