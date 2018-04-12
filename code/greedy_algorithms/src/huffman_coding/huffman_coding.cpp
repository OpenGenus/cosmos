/*
 * Huffman Codes
 */
// Part of Cosmos by OpenGenus Foundation
#include <iostream> // std::cout, std::endl
#include <map> // std::map
#include <string> // std::string
#include <queue> // std::priority_queue

struct huff_node
{
    float weight;
    huff_node *left, *right;

    huff_node(float w, huff_node *l, huff_node *r)
        : weight(w), left(l), right(r)
    {
    }

    virtual ~huff_node()
    {
        delete left;
        delete right;
    }

    virtual void print(std::string)
    {
    }
};

struct huff_leaf : public huff_node
{
    char letter;

    huff_leaf(char c, float w)
        : huff_node(w, nullptr, nullptr), letter(c)
    {
    }

    void print(std::string prefix = "")
    {
        std::cout << letter << " (" << weight
                  << ") -> " << prefix << std::endl;
    }
};

struct Compare
{
    bool operator()(huff_node *a, huff_node *b)
    {
        return a->weight > b->weight;
    }
};

huff_node * merge_nodes(huff_node *a, huff_node *b)
{
    return new huff_node(a->weight + b->weight, a, b);
}

typedef std::priority_queue<huff_node*, std::vector<huff_node*>, Compare>
    huff_priority_queue;

huff_node * encode(std::map<char, float> &m)
{
    huff_priority_queue pq;
    huff_node *a, *b;

    // create a huff_leaf for each letter in the map
    // weighted by its associated weight, and put each leaf into
    // priority queue
    std::map<char, float>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        pq.push(new huff_leaf(it->first, it->second));

    // create the tree
    while (pq.size() > 1)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(merge_nodes(a, b));
    }

    // only single node left in the pq, root of the tree
    return pq.top();
}

void print_tree(huff_node *node, std::string prefix = "")
{
    node->print(prefix);
    if (node->left)
        print_tree(node->left, prefix + "0");
    if (node->right)
        print_tree(node->right, prefix + "1");
}

int main()
{
    // dictionary of letters w/ frequency in English
    std::map<char, float> freq = {
        {'a', 8.1},
        {'b', 1.5},
        {'c', 2.8},
        {'d', 4.2},
        {'e', 12.7},
        {'f', 2.2},
        {'g', 2.0},
        {'h', 6.0},
        {'i', 7.0},
        {'j', 0.2},
        {'k', 0.8},
        {'l', 4.0},
        {'m', 2.4},
        {'n', 6.7},
        {'o', 7.5},
        {'p', 1.9},
        {'q', 0.1},
        {'r', 6.0},
        {'s', 6.3},
        {'t', 9.1},
        {'u', 2.8},
        {'v', 1.0},
        {'w', 2.4},
        {'x', 0.2},
        {'y', 2.0},
        {'z', 0.1}
    };

    huff_node *root = encode(freq);
    print_tree(root);
    return 0;
}
