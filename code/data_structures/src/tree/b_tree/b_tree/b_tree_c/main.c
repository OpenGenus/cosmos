// Part of Cosmos by OpenGenus Foundation
// Author : ABDOUS Kamel
// Implementation of a disk-stored B-Tree

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
    BTree* bt = OpenBTree("btree.bin", 'N');
    btree_ins(bt, 5);
    btree_ins(bt, 10);
    btree_ins(bt, 1);
    btree_ins(bt, 2);
    btree_ins(bt, 20);
    btree_ins(bt, 15);
    inordre(bt, BTreeRoot(bt));
    CloseBTree(bt);

    return 0;
}
