// Part of Cosmos by OpenGenus Foundation
// Author : ABDOUS Kamel
// Implementation of a disk-stored B-Tree

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <stdio.h>

#define MIN_DEGREE 2
#define MAX_N ((MIN_DEGREE * 2) - 1) /* Max nb of values stored in a node */
#define MAX_C (MIN_DEGREE * 2) /* Max nb of childs of a node */

#define MAX_S 20 /* Size of the stack */

typedef int TVal;

/* This struct contains information about the disk-stored b-tree */
typedef struct
{
    int root; /* Block num of the root */
    int nbNodes;
    int nbVals;
    int height;

    /* In the file that contains the b-tree, there's a list of the blocks
       that are no longer used by the tree. This field contains the block num
       of the head of this list. If this list is not empty, we use a block of the list
       when we need a new block instead of allocating a new one. */
    int freeBlocksHead;

} FileHeader;

typedef struct
{
    TVal vals[MAX_N];
    int childs[MAX_C];

    int nb_n; // Nb values stored in the node

} BNode;

/* That a static stack */
typedef struct
{
    int head;
    int adrs[MAX_S];
    BNode nodes[MAX_S];

} BStack;

/* That's the struct to use to manipulate a b-tree */
typedef struct
{
    FILE* treeFile;
    FileHeader fileHeader;
    BStack stack;

} BTree;

/*
 * Binary search in a node.
 * Returns 1 in success and stores the position in i.
 * Otherwise returns 0 and i contains the position where the value is supposed to be.
 */
int bnode_search(TVal v, int* i, BNode* n);

/*
 * Inserts v in n and keeps the values sorted.
 * rc is the right child of the value (-1 if it hasn't).
 */
void bnode_ins(TVal v, int rc, BNode* n);

/*
 * Deletes v from the node n.
 */
void bnode_del(TVal v, BNode* n);

void inordre(BTree* f, int i);

/*
 * Returns 1 and the block that contains c in buff, and its num in i, and the position of c in j.
 * If the value doesn't exist, returns 0.
 */
int btree_find(BTree* bt, TVal c, int* i, int* j, BNode* buff);
void btree_ins(BTree* bt, TVal c);

// ------------------------------------------------------------------- //
void initStack(BStack* stack);
void pushStack(BStack* stack, int adr, BNode* n);
void popStack(BStack* stack, int* adr, BNode* n);
void getStackHead(BStack* stack, int* adr, BNode* n);

/*
 * Function to call to open a disk-stored b-tree.
 * if mode = 'N' : it creates a new btree.
 * else (you can put 'O') : it reads the btree stored in fpath.
 */
BTree* OpenBTree(char* fpath, char mode);

/*
 * Close the btree.
 * Writes the tree header in the file.
 */
void CloseBTree(BTree* f);

void ReadBlock(BTree* f, BNode* buff, int i);
void WriteBlock(BTree* f, BNode* buff, int i);

/*
 * If the freeBlocks list isn't empty, takes the head of the list as a new block.
 * Else, it allocs a new block on the disk.
 */
int AllocBlock(BTree* f);

/*
 * This function also adds the block to the freeBlocks list.
 */
void FreeBlock(BTree* f, BNode* buff, int i);

int BTreeRoot(BTree* f);

#endif // BTREE_H_INCLUDED
