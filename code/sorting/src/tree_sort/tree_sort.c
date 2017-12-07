#include <stdio.h>
#include <alloc.h>
// Part of Cosmos by OpenGenus Foundation
struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;

void main( )
{
    struct btreenode *bt ;
    int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
    int i ;

    bt = NULL ;


    printf ( "Binary tree sort.\n" ) ;

    printf ( "\nArray:\n" ) ;
    for ( i = 0 ; i <= 9 ; i++ )
        printf ( "%d\t", arr[i] ) ;

    for ( i = 0 ; i <= 9 ; i++ )
        insert ( &bt, arr[i] ) ;

    printf ( "\nIn-order traversal of binary tree:\n" ) ;
    inorder ( bt ) ;

}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        printf ( "%d\t", sr -> data ) ;
        inorder ( sr -> rightchild ) ;
    }
}
