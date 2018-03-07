#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* 
newNode(char data, int freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return (temp);
}

struct MinHeap* 
createMinHeap(int capacity) 
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return (minHeap);
}

void 
swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void 
minHeapify(struct MinHeap* minHeap, int index)
{
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
 
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != index) {
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

int 
isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

struct MinHeapNode* 
extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];

    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return (temp);
}

void 
insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = minHeapNode;
}

void
buildMinHeap(struct MinHeap* minHeap)
{
    int i;
    for (i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void 
printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
 
    printf("\n");
}

int 
isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

struct MinHeap*
createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return (minHeap);
}

struct MinHeapNode* 
buildHuffmanTree(char data[], int freq[], int size) 
{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('@', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
    return (extractMin(minHeap));
}

void 
printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) { 
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void 
HuffmanCodes(char data[], int freq[], int size) 
{
    struct MinHeapNode* root= buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
 
    printCodes(root, arr, top);
}

int 
main()
{
    int size;
    printf("Enter number of characters: ");
    scanf("%d", &size);

    char arr[size];
    int freq[size];

    int i;
    for (i = 0; i <size; ++i) {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &arr[i]);
        printf("Enter frequency character %d: ", i + 1);
        scanf("%d", &freq[i]);
    }
 
    HuffmanCodes(arr, freq, size);
 
    return (0);
}
