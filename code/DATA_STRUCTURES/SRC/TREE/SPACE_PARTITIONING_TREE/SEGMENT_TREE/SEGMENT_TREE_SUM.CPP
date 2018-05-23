// Segment tree with spaces. Allows to find sum in O(log size) time. Uses O(n log size) memory.

#include <iostream>
#include <string>

const int size = 1000000000;

struct node
{
    int leftBound, rightBound;
    node *leftChild, *rightChild;
    int value;
    node (int LeftBound, int RightBound)
    {
        leftBound = LeftBound;
        rightBound = RightBound;
        value = 0;
        leftChild = rightChild = 0;
    }
} *root;

void add (node *vertex, int destination, int value)
{
    if (vertex->leftBound == destination && vertex->rightBound == destination + 1)
    {
        vertex->value += value;
        return;
    }

    vertex->value += value;

    int middle = (vertex->leftBound + vertex->rightBound) / 2;

    if (destination < middle)
    {
        if (vertex->leftChild == 0)
            vertex->leftChild = new node (vertex->leftBound, middle);
        add (vertex->leftChild, destination, value);
    }
    else
    {
        if (vertex->rightChild == 0)
            vertex->rightChild = new node (middle, vertex->rightBound);
        add (vertex->rightChild, destination, value);
    }
}

int ask (node *vertex, int leftBound, int rightBound)
{
    if (vertex == 0)
        return 0;

    if (vertex->leftBound >= leftBound && vertex->rightBound <= rightBound)
        return vertex->value;

    if (vertex->leftBound >= rightBound && vertex->rightBound <= leftBound)
        return 0;

    return ask (vertex->leftChild, leftBound, rightBound) + ask (vertex->rightChild, leftBound,
                                                                 rightBound);
}

int main ()
{
    root = new node (-size, size); // Actually allows negative numbers

    std::cout << "Print number of queries!\n";

    int q;
    std::cin >> q;

    for (int _ = 0; _ < q; _++)
    {
        std::string type;
        std::cin >> type;

        if (type == "add")
        {
            int destination, value;
            std::cin >> destination >> value;

            add (root, destination, value);

            std::cout << "Added succesfully!\n";
        }
        else if (type == "ask")
        {
            int leftBound, rightBound;
            std::cin >> leftBound >> rightBound;

            std::cout << ask (root, leftBound, rightBound) << "\n";
        }
        else
            std::cout << "Unknown Type! Only add and ask allowed\n";
    }

}
