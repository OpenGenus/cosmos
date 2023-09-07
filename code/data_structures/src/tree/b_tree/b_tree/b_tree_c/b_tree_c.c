// Part of Cosmos by OpenGenus Foundation
// Author : ABDOUS Kamel
// Implementation of a disk-stored B-Tree

#include "btree.h"
#include <stdlib.h>

/*
 * Binary search in a node.
 * Returns 1 in success and stores the position in i.
 * Otherwise returns 0 and i contains the position where the value is supposed to be.
 */
int bnode_search(TVal v, int* i, BNode* n)
{
    int bi = 0, bs = n->nb_n - 1;

    while(bi <= bs)
    {
        *i = (bi + bs) / 2;
        if(n->vals[*i] == v)
            return 1;

        else if(n->vals[*i] < v)
            bi = *i + 1;

        else
            bs = *i - 1;
    }

    *i = bi;
    return 0;
}

/*
 * Inserts v in n and keeps the values sorted.
 * rc is the right child of the value (-1 if it hasn't).
 */
void bnode_ins(TVal v, int rc, BNode* n)
{
    if(n->nb_n == MAX_N)
        return ;

    int i = n->nb_n - 1;

    while(i >= 0 && n->vals[i] > v)
    {
        n->vals[i + 1] = n->vals[i];
        n->childs[i + 2] = n->childs[i + 1];
        i--;
    }

    n->vals[i + 1] = v;
    n->childs[i + 2] = rc;

    n->nb_n++;
}

/*
 * Deletes v from the node n.
 */
void bnode_del(TVal v, BNode* n)
{
    int i = 0;

    if(!bnode_search(v, &i, n))
        return;

    n->nb_n--;
    while(i < n->nb_n)
    {
        n->vals[i] = n->vals[i + 1];
        n->childs[i + 1] = n->childs[i + 2];
    }
}

void inordre(BTree* f, int i)
{
    BNode buff;
    ReadBlock(f, &buff, i);

    int j;
    for(j = 0; j < buff.nb_n; ++j)
    {
        if(buff.childs[j] != -1)
            inordre(f, buff.childs[j]);

        printf("%d ", buff.vals[j]);
    }

    if(buff.childs[j] != -1)
        inordre(f, buff.childs[j]);
}

/*
 * Returns 1 and the block that contains c in buff, and its num in i, and the position of c in j.
 * If the value doesn't exist, returns 0.
 */
int btree_find(BTree* bt, TVal c, int* i, int* j, BNode* buff)
{
    *i = BTreeRoot(bt);
    *j = 0;

    initStack(&bt->stack);

    while(*i != -1)
    {
        ReadBlock(bt, buff, *i);
        if(bnode_search(c, j, buff))
            return 1;

        pushStack(&bt->stack, *i, buff);
        *i = buff->childs[*j];
    }

    if(bt->stack.head != -1)
        popStack(&bt->stack, i, buff);

    return 0;
}

void btree_ins(BTree* bt, TVal c)
{
    int i, j, k, median;
    BNode buff, brother;

    if(btree_find(bt, c, &i, &j, &buff))
        return;

    bt->fileHeader.nbVals++;

    if(i == -1)
    {
        bt->fileHeader.root = AllocBlock(bt);
        buff.vals[0] = c;
        buff.nb_n = 1;

        buff.childs[0] = buff.childs[1] = -1;
        WriteBlock(bt, &buff, BTreeRoot(bt));
    }

    int stop = 0, rc = -1;
    while(!stop)
    {
        if(buff.nb_n != MAX_N)
        {
            stop = 1;
            bnode_ins(c, rc, &buff);
            WriteBlock(bt, &buff, i);
        }

        else
        {
            for(j = MAX_N / 2 + 1, k = 0; j < MAX_N; ++j, ++k)
            {
                brother.vals[k] = buff.vals[j];
                brother.childs[k] = buff.childs[j];
            }

            brother.childs[k] = buff.childs[j];
            brother.nb_n = buff.nb_n = MAX_N / 2;

            median = buff.vals[MAX_N / 2];

            if(c < median)
                bnode_ins(c, rc, &buff);

            else
                bnode_ins(c, rc, &brother);

            rc = AllocBlock(bt);

            WriteBlock(bt, &buff, i);
            WriteBlock(bt, &brother, rc);

            if(bt->stack.head != -1)
            {
                c = median;
                popStack(&bt->stack, &i, &buff);
            }

            else
            {
                bt->fileHeader.height++;
                bt->fileHeader.root = AllocBlock(bt);
                buff.childs[0] = i;
                buff.childs[1] = rc;
                buff.vals[0] = median;
                buff.nb_n = 1;

                WriteBlock(bt, &buff, BTreeRoot(bt));
                stop = 1;
            }
        }
    }
}

// ------------------------------------------------------------------------ //
void initStack(BStack* stack)
{
    stack->head = -1;
}

void pushStack(BStack* stack, int adr, BNode* n)
{
    if(stack->head == MAX_S - 1)
        return;

    stack->head++;
    stack->adrs[stack->head] = adr;
    stack->nodes[stack->head] = *n;
}

void popStack(BStack* stack, int* adr, BNode* n)
{
    if(stack->head == -1)
        return;

    *adr = stack->adrs[stack->head];
    *n = stack->nodes[stack->head];

    stack->head--;
}

void getStackHead(BStack* stack, int* adr, BNode* n)
{
    if(stack->head == -1)
        return;

    *adr = stack->adrs[stack->head];
    *n = stack->nodes[stack->head];
}

/*
 * Function to call to open a disk-stored b-tree.
 * if mode = 'N' : it creates a new btree.
 * else (you can put 'O') : it reads the btree stored in fpath.
 */
BTree* OpenBTree(char* fpath, char mode)
{
    BTree* bt = malloc(sizeof(BTree));

    if(mode == 'N')
    {
        bt->treeFile = fopen(fpath, "wb+");
        if(bt->treeFile == NULL)
        {
            free(bt);
            return NULL;
        }

        bt->fileHeader.root = bt->fileHeader.freeBlocksHead = -1;
        bt->fileHeader.nbNodes = bt->fileHeader.nbVals = bt->fileHeader.height = 0;

        fwrite(&(bt->fileHeader), sizeof(FileHeader), 1, bt->treeFile);
    }

    else
    {
        bt->treeFile = fopen(fpath, "rb+");
        if(bt->treeFile == NULL)
        {
            free(bt);
            return NULL;
        }

        fread(&(bt->fileHeader), sizeof(FileHeader), 1, bt->treeFile);
    }

    return bt;
}

/*
 * Close the btree.
 * Writes the tree header in the file.
 */
void CloseBTree(BTree* f)
{
    fseek(f->treeFile, 0, SEEK_SET);
    fwrite(&(f->fileHeader), sizeof(FileHeader), 1, f->treeFile);

    fclose(f->treeFile);
    free(f);
}

void ReadBlock(BTree* f, BNode* buff, int i)
{
    fseek(f->treeFile, sizeof(FileHeader) + i * sizeof(BNode), SEEK_SET);
    fread(buff, sizeof(BNode), 1, f->treeFile);
}

void WriteBlock(BTree* f, BNode* buff, int i)
{
    fseek(f->treeFile, sizeof(FileHeader) + i * sizeof(BNode), SEEK_SET);
    fwrite(buff, sizeof(BNode), 1, f->treeFile);
}

/*
 * If the freeBlocks list isn't empty, takes the head of the list as a new block.
 * Else, it allocs a new block on the disk.
 */
int AllocBlock(BTree* f)
{
    int i = f->fileHeader.freeBlocksHead;
    BNode buf;

    if(i != -1)
    {
        ReadBlock(f, &buf, i);
        f->fileHeader.freeBlocksHead = buf.childs[0];
    }

    else
    {
        i = f->fileHeader.nbNodes++;
        buf.nb_n = 0;
        WriteBlock(f, &buf, i);
    }

    return i;
}

/*
 * This function also adds the block to the freeBlocks list.
 */
void FreeBlock(BTree* f, BNode* buff, int i)
{
    buff->childs[0] = f->fileHeader.freeBlocksHead;
    f->fileHeader.freeBlocksHead = i;
    WriteBlock(f, buff, i);
}

int BTreeRoot(BTree* f)
{
    return f->fileHeader.root;
}
