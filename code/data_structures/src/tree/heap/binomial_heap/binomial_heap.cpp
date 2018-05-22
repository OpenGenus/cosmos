#include <iostream>
#include <queue>
#include <vector>

/* Part of Cosmos by OpenGenus Foundation */
using namespace std;

class Node {
public:
    int value;
    int degree;
    Node* parent;
    Node* child;
    Node* sibling;
    Node() : value(0), degree(0), parent(0), child(0), sibling(0)
    {
    };
    ~Node()
    {
    };
};

class BinomialHeap {
public:
    BinomialHeap() : head(NULL)
    {
    }
    Node* getHead()
    {
        return head;
    }
    void insert(int value)
    {
        BinomialHeap tempHeap;
        Node* tempNode = new Node();
        tempNode->value = value;
        tempHeap.setHead(&tempNode);
        bHeapUnion(tempHeap);
    }
    void deleteMin()
    {
        int min = head->value;
        Node* tmp = head;
        Node* minPre = NULL;
        Node* minCurr = head;

        //find the root x with the minimum key in the root list of H
        // remove x from the root list of H
        while (tmp->sibling)
        {
            if (tmp->sibling->value < min)
            {
                min = tmp->sibling->value;
                minPre = tmp;
                minCurr = tmp->sibling;
            }
            tmp = tmp->sibling;
        }
        if (!minPre && minCurr)
            head = minCurr->sibling;
        else if (minPre && minCurr)
            minPre->sibling = minCurr->sibling;
        //H' Make-BINOMIAL-HEAP()
        BinomialHeap bh;
        Node *pre, *curr;
        //reverse the order of the linked list of x's children
        pre = tmp = NULL;
        curr = minCurr->child;
        while (curr)
        {
            tmp = curr->sibling;
            curr->sibling = pre;
            curr->parent = NULL;
            pre = curr;
            curr = tmp;
        }
        //set head[H'] to point to the head of the resulting list
        bh.setHead(&pre);
        //H <- BINOMIAL-HEAP-UNION
        bHeapUnion(bh);
    }
    int getMin()
    {
        int min = 2 << 20;
        Node* tmp = head;
        while (tmp)
        {
            if (tmp->value < min)
                min = tmp->value;
            tmp = tmp->sibling;
        }
        return min;

    }
    void preorder()
    {
        puts("");
        Node* tmp = head;
        while (tmp)
        {
            _preorder(tmp);
            tmp = tmp->sibling;
        }
        puts("");
    }
    void BFS()
    {
        puts("");
        queue<Node*> nodeQueue;
        Node *tmp = head;

        while (tmp)
        {
            nodeQueue.push(tmp);
            tmp = tmp->sibling;
        }

        while (!nodeQueue.empty())
        {
            Node *node = nodeQueue.front();
            nodeQueue.pop();

            if (node)
                printf("%d ", node->value);

            node = node->child;
            while (node)
            {
                nodeQueue.push(node);
                node = node->sibling;
            }
        }
        puts("");

    }
    void bHeapUnion(BinomialHeap &bh)
    {

        _mergeHeap(bh);
        Node* prev = NULL;
        Node* x = head;
        Node* next = x->sibling;
        while (next)
        {
            if (x->degree != next->degree)
            {
                prev = x;                          //Case 1 and 2
                x = next;                          //Case 1 and 2
            }
            else if (next->sibling && next->sibling->degree == x->degree)                       //three BT has the same degree
            {
                if (next->value < x->value && next->value < next->sibling->value)                           //312, need to trans to 132
                {
                    x->sibling = next->sibling;
                    next->sibling = x;
                    if (prev)
                        prev->sibling = next;
                    else
                        head = next;

                    prev = x;
                    x = next;
                }
                else if (next->sibling->value < x->value && next->sibling->value < next->value)                           //321, need to trans to 123
                {
                    x->sibling = next->sibling->sibling;
                    next->sibling->sibling = next;
                    if (prev)
                        prev->sibling = next->sibling;
                    else
                        head = next->sibling;
                    prev = next->sibling;
                    next->sibling = x;
                    x = next;
                }
                else
                {
                    prev = x;                              //Case 1 and 2
                    x = next;                              //Case 1 and 2
                }
            }
            else if (x->value <= next->value)
            {
                x->sibling = next->sibling;                          //Case 3
                _mergeTree(next, x);                                             //Case 3
                next = x;
            }
            else
            {
                if (!prev)                                                               //Case 4
                    head = next;                                                         //Case 4
                else
                    prev->sibling = next;                                    //Case 4
                _mergeTree(x, next);                                             //Case 4
                x = next;                                                                //Case 4
            }
            next = next->sibling;                                        //Case 4
        }
    }
    int size()
    {
        return _size(head);
    }
    void setHead(Node** node)
    {
        head = *node;
    }

private:
    int _size(Node* node)
    {
        if (!node)
            return 0;
        return 1 + _size(node->child) + _size(node->sibling);
    }
    void _preorder(Node* node)
    {
        if (!node)
            return;
        printf("%d ", node->value);
        _preorder(node->child);
        if (node->parent)
            _preorder(node->sibling);
        //printf("%d(%d) ",node->value,node->degree);
    }
    void _mergeTree(Node* tree1, Node* tree2)
    {
        tree1->parent = tree2;
        tree1->sibling = tree2->child;
        tree2->child = tree1;
        tree2->degree++;
    }
    void _mergeHeap(BinomialHeap &bh)
    {
        Node* head2 = bh.getHead();
        Node* head1 = head;
        //for new pointer
        Node *newHead, *newCurr;
        if (!head1)
        {
            head = head2;
            return;
        }
        if (head1->degree > head2->degree)
        {
            newHead = newCurr = head2;
            head2 = head2->sibling;
        }
        else
        {
            newHead = newCurr = head1;
            head1 = head1->sibling;
        }
        //Sorted by degree into monotonically increasing order
        while (head1 && head2)
        {
            if (head1->degree < head2->degree)
            {
                newCurr->sibling = head1;
                newCurr = head1;
                head1 = head1->sibling;
            }
            else
            {
                newCurr->sibling = head2;
                newCurr = head2;
                head2 = head2->sibling;
            }
        }
        while (head1)
        {
            newCurr->sibling = head1;
            newCurr = head1;
            head1 = head1->sibling;
        }
        while (head2)
        {
            newCurr->sibling = head2;
            newCurr = head2;
            head2 = head2->sibling;
        }
        head = newHead;
    }

    Node* head;
};

int main()
{
    vector<int> heap1{5, 4, 3, 2, 1};
    vector<int> heap2{4, 3, 2, 1, 8};
    BinomialHeap bh1, bh2;

    for (auto v: heap1)
        bh1.insert(v);

    for (auto v: heap2)
        bh2.insert(v);

    printf("preorder traversal of first binomialheap: ");
    bh1.preorder();
    printf("BFS of first binomialheap: ");
    bh1.BFS();

    printf("\n");

    printf("preorder traversal of second binomialheap: ");
    bh2.preorder();
    printf("BFS of second binomialheap: ");
    bh2.BFS();

    printf("-----------Union------------------\n");;
    bh1.bHeapUnion(bh2);
    printf("preorder traversal of union: ");
    bh1.preorder();
    printf("BFS of union: ");
    bh1.BFS();

    printf("-----------Delete min = 1 --------\n");
    bh1.deleteMin();
    printf("preorder traversal of delete min: ");
    bh1.preorder();
    printf("BFS of union: ");
    bh1.BFS();

    printf("-----------Delete min = 2 --------\n");
    bh1.deleteMin();
    printf("preorder traversal of delete min: ");
    bh1.preorder();
    printf("BFS of union: ");
    bh1.BFS();

    printf("binomialheap min:%d\n", bh1.getMin());
    printf("binomailheap size %d\n", bh1.size());
}
