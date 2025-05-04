#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

// defined to the arbitrary value 100
#define BUFLEN 100   // Buffer length 
//defined to the arbitrary value 10
#define ARY_SIZE 10 // initial dynamic array size

// dynamically allocated array
typedef struct dynarray_t {
    int* ary; // points to an array of ints; capacity is its dimension
    int capacity; // max capacity of the array
    int size; // the size of the array (maxes out at capacity)
} dynarray;

typedef enum {
    PREORDER,           // root then left subtree then right subtree
    INORDER,            // left subtree then root then right subtree
    POSTORDER           // left subtree then right subtree then root
} traversal_type_t;


// The structure of a single node in a tree
typedef struct Node_S {
    int value; // the integer that is stored in the tree
    struct Node_S* left; // a pointer to the node storing the next value less than this node
    struct Node_S* right; // a pointer to the node storing the next value greater than this node
}* Node;

// creates a Node to be filled with a value later
Node createNode() {
    Node node = (Node)malloc(sizeof(Node)); // allocates size for each node
    node->left = NULL;
    node->right = NULL;
    node->value = NULL;
    return node;
}

// deallocates the node and all children of the node recursively
void destroyNode(Node root) {
    if (!root) return;
    destroyNode(root->left);
    destroyNode(root->right);
    free(root);
}

//inserts data at the end of the array of data
void dynarrayInsert(dynarray * arr, int data) {
    if (arr->size >= arr->capacity) return; // if size is the same as capacity can't fit anymore data
    arr->ary[arr->size] = data;
    arr->size++;
}

//reads from a file and populates a dynamic array with the data in it
void dynarrayRead(dynarray* dp, FILE* fp) {
    char buffer[BUFLEN];
    int val;

    while (fgets(buffer, sizeof(buffer), fp)) {
        int i = 0;
        while (buffer[i] != '\0' && isspace((unsigned char)buffer[i])) {
            i++;
        }
        if (buffer[i] == '\0') {
            continue;
        }
        if (sscanf_s(buffer, "%d", &val) == 1) {
            dynarray_insert(dp, val);
        }
    }
}

//prints the contents of the dynamic array
void dynarrayPrint(const dynarray* dp) {
    if (!dp || !dp->ary) return;
    for (int i = 0; i < dp->size; i++) {
        printf("%d\n", dp->ary[i]);
    }
}

//frees the memory at dp.ary
void dynarrayFree(dynarray* dp) {
    if (dp->ary == NULL) return;
    free(dp->ary);
    dp->ary = NULL;
}

//insert a value into the the node
Node* treeInsert(Node bp, int val) {
    if (!bp) {
        Node newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            fprintf(stderr, "New node memory allocation failed");
            return NULL;
        }
        newNode->value = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < bp->value) { // if the value fed to the function is less than create a node that is to the left
        bp->left = treeInsert(bp->left, val);
    }
    if (val > bp->value) { // if the value fed to the function is greater than create a node that is to the right
        bp->right = treeInsert(bp->right, val);
    }
    return bp;
}

// use bst_insert to create a bst from an array
Node aryToBst(int size, const int x[]) {
    Node new_tree = (Node)malloc(sizeof(Node));
    if (!new_tree) {
        fprintf(stderr,"New tree mem allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        bst_insert(new_tree, x[i]);
    }
    return new_tree;
}

void bstTraverse(const Node bp, traversal_type_t tt) {
    if (tt == PREORDER) {
        if (!bp) return;

        printf("%d\n", bp->value); // print data then go left
        bst_traverse(bp->left, tt); // after left node go to right
        bst_traverse(bp->right, tt);
    }
    else if (tt == INORDER) {
        if (!bp) return;

        bst_traverse(bp->left, tt); //traverse left then print data 
        printf("%d\n", bp->value); //print data
        bst_traverse(bp->right, tt); // then traverse right tree
    }
    else if (tt == POSTORDER) {
        if (!bp) return;

        bst_traverse(bp->left, tt); //traverse left tree
        bst_traverse(bp->right, tt); //traverse right tree
        printf("%d\n", bp->value); // print data
    }
}

int main(int argc, char* argv[]) {
    FILE* fp = stdin;

    // open file
    if (argc > 2) {
        fprintf(stderr, "usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }
    else if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("err opening file");
            return EXIT_FAILURE;
        }
    }

    // initialize and check if initialized
    dynarray* dp = dynarrayInit(ARY_SIZE);
    if (!dp) {
        fprintf(stderr, "err: memory allocation failed\n");
        if (fp != stdin) fclose(fp);
        return EXIT_FAILURE;
    }

    dynarrayRead(dp, fp);
    printf("Input values:\n");
    dynarrayPrint(dp);

    Node tree = aryToBst(dp->size, dp->ary);
    printf("Preorder traversal:\n");
    bstTraverse(tree, PREORDER);
    printf("Inorder traversal:\n");
    bstTraverse(tree, INORDER);
    printf("Postorder traversal:\n");
    bstTraverse(tree, POSTORDER);

    dynarrayFree(dp); // freeing the dynamic array
    destroyNode(tree); // freeing the bst

    return EXIT_SUCCESS;

}
