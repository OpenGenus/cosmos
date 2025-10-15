#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS
#define BUFLEN 100
#define ARY_SIZE 10

//================ Dynamic Array ==================
typedef struct dynarray_t {
    int* ary;
    int capacity;
    int size;
} dynarray;

dynarray* dynarrayInit(int capacity) {
    dynarray* dp = (dynarray*)malloc(sizeof(dynarray));
    if (!dp) return NULL;
    dp->ary = (int*)malloc(capacity * sizeof(int));
    if (!dp->ary) {
        free(dp);
        return NULL;
    }
    dp->capacity = capacity;
    dp->size = 0;
    return dp;
}

void dynarrayInsert(dynarray* arr, int data) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->ary = realloc(arr->ary, arr->capacity * sizeof(int));
    }
    arr->ary[arr->size++] = data;
}

void dynarrayRead(dynarray* dp, FILE* fp) {
    char buffer[BUFLEN];
    int val;

    while (fgets(buffer, sizeof(buffer), fp)) {
        int i = 0;
        while (buffer[i] != '\0' && isspace((unsigned char)buffer[i])) i++;
        if (buffer[i] == '\0') continue;

        if (sscanf(buffer, "%d", &val) == 1) {
            dynarrayInsert(dp, val);
        }
    }
}

void dynarrayPrint(const dynarray* dp) {
    if (!dp || !dp->ary) return;
    for (int i = 0; i < dp->size; i++) {
        printf("%d ", dp->ary[i]);
    }
    printf("\n");
}

void dynarrayFree(dynarray* dp) {
    if (dp->ary) free(dp->ary);
    free(dp);
}

//================ Binary Search Tree ==================
typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} traversal_type_t;

typedef struct Node_S {
    int value;
    struct Node_S* left;
    struct Node_S* right;
} *Node;

Node createNode(int val) {
    Node node = (Node)malloc(sizeof(struct Node_S));
    node->left = NULL;
    node->right = NULL;
    node->value = val;
    return node;
}

void destroyNode(Node root) {
    if (!root) return;
    destroyNode(root->left);
    destroyNode(root->right);
    free(root);
}

Node bstInsert(Node root, int val) {
    if (!root) return createNode(val);

    if (val < root->value) root->left = bstInsert(root->left, val);
    else if (val > root->value) root->right = bstInsert(root->right, val);
    return root;
}

Node aryToBst(int size, const int x[]) {
    Node tree = NULL;
    for (int i = 0; i < size; i++) {
        tree = bstInsert(tree, x[i]);
    }
    return tree;
}

void bstTraverse(const Node root, traversal_type_t tt) {
    if (!root) return;

    if (tt == PREORDER) {
        printf("%d ", root->value);
        bstTraverse(root->left, tt);
        bstTraverse(root->right, tt);
    }
    else if (tt == INORDER) {
        bstTraverse(root->left, tt);
        printf("%d ", root->value);
        bstTraverse(root->right, tt);
    }
    else if (tt == POSTORDER) {
        bstTraverse(root->left, tt);
        bstTraverse(root->right, tt);
        printf("%d ", root->value);
    }
}

//================ Binary Tree (Level Order Insert) ==================
typedef struct QueueNode {
    Node data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node n) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = n;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node node = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

Node binaryTreeInsert(Node root, int val) {
    Node newNode = createNode(val);
    if (!root) return newNode;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node temp = dequeue(q);

        if (!temp->left) {
            temp->left = newNode;
            break;
        }
        else enqueue(q, temp->left);

        if (!temp->right) {
            temp->right = newNode;
            break;
        }
        else enqueue(q, temp->right);
    }

    free(q);
    return root;
}

Node aryToBinaryTree(int size, const int x[]) {
    Node tree = NULL;
    for (int i = 0; i < size; i++) {
        tree = binaryTreeInsert(tree, x[i]);
    }
    return tree;
}

//================ MAIN ==================
int main(int argc, char* argv[]) {
    FILE* fp = stdin;

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

    dynarray* dp = dynarrayInit(ARY_SIZE);
    if (!dp) {
        fprintf(stderr, "err: memory allocation failed\n");
        if (fp != stdin) fclose(fp);
        return EXIT_FAILURE;
    }

    dynarrayRead(dp, fp);
    printf("Input values:\n");
    dynarrayPrint(dp);

    // BST
    Node bst = aryToBst(dp->size, dp->ary);
    printf("\nBST Traversals:\n");
    printf("Preorder: "); bstTraverse(bst, PREORDER); printf("\n");
    printf("Inorder: "); bstTraverse(bst, INORDER); printf("\n");
    printf("Postorder: "); bstTraverse(bst, POSTORDER); printf("\n");

    // Binary Tree
    Node btree = aryToBinaryTree(dp->size, dp->ary);
    printf("\nBinary Tree Traversals:\n");
    printf("Preorder: "); bstTraverse(btree, PREORDER); printf("\n");
    printf("Inorder: "); bstTraverse(btree, INORDER); printf("\n");
    printf("Postorder: "); bstTraverse(btree, POSTORDER); printf("\n");

    dynarrayFree(dp);
    destroyNode(bst);
    destroyNode(btree);
    if (fp != stdin) fclose(fp);

    return EXIT_SUCCESS;
}
