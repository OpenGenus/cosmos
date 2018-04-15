#include <stdio.h>
#include <stdlib.h>

struct AVLNode
{
    int value;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

struct AVLTree
{
    struct AVLNode *root;
    int size;
};

void 
AVLTreeInit(struct AVLTree *tree)
{
    tree->root = NULL;
    tree->size = 0;
}

struct AVLTree *AVLTreeNew()
{
    struct AVLTree *tree = (struct AVLTree *)malloc(sizeof(struct AVLTree));

    AVLTreeInit(tree);

    return tree;
}

void 
AVLNodeFree(struct AVLNode *current)
{
    if (current != NULL)
    {
        AVLNodeFree(current->left);
        AVLNodeFree(current->right);
        free(current);
        current = NULL;
    }
}

void 
AVLTreeClear(struct AVLTree *tree)
{
    AVLNodeFree(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

void 
AVLTreeDelete(struct AVLTree *tree)
{
    AVLTreeClear(tree);
    free(tree);
    tree = NULL;
}

int 
AVLTreeSize(struct AVLTree *tree)
{
    return tree->size;
}

int 
AVLTreeHeight(struct AVLTree *tree)
{
    return tree->root->height;
}

int 
_h(struct AVLNode *current)
{
    if (current == NULL)
        return -1;
    return current->height;
}

void 
_setHeight(struct AVLNode *current)
{
    int leftHeight = _h(current->left);
    int rightHeight = _h(current->right);

    if (leftHeight < rightHeight)
        current->height = 1 + rightHeight;
    else
        current->height = 1 + leftHeight;
}

struct AVLNode *_rotateLeft(struct AVLNode *current)
{
    struct AVLNode *newTop = current->right;
    current->right = newTop->left;
    newTop->left = current;

    _setHeight(current);
    _setHeight(newTop);

    return newTop;
}

struct AVLNode *_rotateRight(struct AVLNode *current)
{
    struct AVLNode *newTop = current->left;
    current->left = newTop->right;
    newTop->right = current;

    _setHeight(current);
    _setHeight(current);

    return newTop;
}

int 
_bf(struct AVLNode *current)
{
    return _h(current->right) - _h(current->left);
}

struct AVLNode *_balance(struct AVLNode *current)
{
    int cbf = _bf(current);

    if (cbf < -1)
	{
        if (_bf(current->left) > 0)
            current->left = _rotateLeft(current->left);
        return _rotateRight(current);
	}
    else if (cbf > 1)
    {
        if (_bf(current->right) < 0)
            current->right = _rotateRight(current->right);
        return _rotateLeft(current);
    }

    _setHeight(current);

    return current;
}

struct AVLNode *_AVLNodeAdd(struct AVLNode *current, int newValue)
{
    struct AVLNode *newNode;

    if (current == NULL)
    {
        newNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));

        newNode->value = newValue;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }
    else if (newValue < current->value)
        current->left = _AVLNodeAdd(current->left, newValue);
   
    else
        current->right = _AVLNodeAdd(current->right, newValue);

    return _balance(current);
}

void 
AVLTreeAdd(struct AVLTree *tree, int newValue)
{
    tree->root = _AVLNodeAdd(tree->root, newValue);
    tree->size++;
}

int 
AVLTreeContains(struct AVLTree *tree, int value)
{
    struct AVLNode *current = tree->root;

    while (current != NULL)
    {
        if (value == current->value)
            return 1;

        else if (value < current->value)
            current = current->left;
  
        else
            current = current->right;
    }

    return 0;
}

int 
_leftMost(struct AVLNode *current)
{
    while (current->left != NULL)
           current = current->left;
   
    return current->value;
}

struct AVLNode *_removeLeftMost(struct AVLNode *current)
{
    struct AVLNode *temp;

    if (current->left != NULL)
    {
        current->left = _removeLeftMost(current->left);
        return _balance(current);
    }

    temp = current->right;
    free(current);
    current = NULL;
    return temp;
}

struct AVLNode *_AVLNodeRemove(struct AVLNode *current, int value)
{
    if (value == current->value)
    {
        if (current->right == NULL)
        {
            struct AVLNode *temp = current->left;
            free(current);
            current = NULL;
            return temp;
        }
        else
        {
            current->value = _leftMost(current->right);
            current->right = _removeLeftMost(current->right);
        }
    }
    else if (value < current->value)
        current->left = _AVLNodeRemove(current->left, value);
   
    else
        current->right = _AVLNodeRemove(current->right, value);
    
    return _balance(current);
}

void 
AVLTreeRemove(struct AVLTree *tree, int value)
{
    if (AVLTreeContains(tree, value))
    {
        tree->root = _AVLNodeRemove(tree->root, value);
        tree->size--;
    }
}

int 
AVLTreeGetSmallest(struct AVLTree *tree)
{
        return _leftMost(tree->root);
}

void 
AVLTreeRemoveSmallest(struct AVLTree *tree)
{
    tree->root = _removeLeftMost(tree->root);
    tree->size--;
}

void 
AVLNodePrint(struct AVLNode *current)
{
    if (current == NULL)
        return;
  
    printf("(");
    AVLNodePrint(current->left);

    printf("%d", current->value);

    AVLNodePrint(current->right);
    printf(")");
}

void 
AVLTreePrint(struct AVLTree *tree)
{
    if (tree == NULL)
        return;
    
    AVLNodePrint(tree->root);
    printf("\n");
}

int 
main()
{
    struct AVLTree *tree = AVLTreeNew();

    AVLTreeAdd(tree, 4);
    AVLTreeAdd(tree, 7);
    printf("Contains 4: %d\n", AVLTreeContains(tree, 4));
    printf("Contains 9: %d\n", AVLTreeContains(tree, 9));
    AVLTreePrint(tree);

    AVLTreeAdd(tree, 3);
    AVLTreePrint(tree);

    AVLTreeAdd(tree, 2);
    AVLTreePrint(tree);
    printf("Smallest  : %d\n", AVLTreeGetSmallest(tree));
    AVLTreeRemoveSmallest(tree);
    AVLTreePrint(tree);

    AVLTreeAdd(tree, 23);
    AVLTreePrint(tree);
    printf("Smallest  : %d\n", AVLTreeGetSmallest(tree));
    printf("Size      : %d\n", AVLTreeSize(tree));
    printf("Height    : %d\n", AVLTreeHeight(tree));

    AVLTreeRemove(tree, 3);
    AVLTreePrint(tree);
    printf("Size      : %d\n", AVLTreeSize(tree));
    printf("Height    : %d\n", AVLTreeHeight(tree));

    AVLTreeAdd(tree, 3);
    AVLTreePrint(tree);
    AVLTreeAdd(tree, 1);
    AVLTreePrint(tree);
    AVLTreeAdd(tree, 0);
    AVLTreePrint(tree);

    AVLTreeDelete(tree);

    return 0;
}
