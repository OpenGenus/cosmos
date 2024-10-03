#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node *> childs;

    Node(int data)
    {
        this->data = data;
    }
};

Node *createTree(vector<int> &arr)
{
    stack<Node *> st;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == -1)
        {
            Node *node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
        else
        {
            st.push(new Node(arr[i]));
        }
    }

    return st.top();
}

void display(Node *node)
{

    cout << node->data << " -> ";
    for (Node *child : node->childs)
    {
        cout << child->data << ", ";
    }
    cout << endl;

    for (Node *child : node->childs)
    {
        display(child);
    }
}


Node *linearizeAndReturnTail(Node *node)
{
    if (node->childs.size() == 0)
        return node;

    int n = node->childs.size();
    Node *oTail = linearizeAndReturnTail(node->childs[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        Node *tail = linearizeAndReturnTail(node->childs[i]);
        tail->childs.push_back(node->childs[i + 1]);
        node->childs.pop_back();
    }

    return oTail;
}

int main(){
     vector<int> arr{10, 40, -1, 30, 90, -1, 80, 110, -1, 100, -1, -1, 70, -1, -1, 20, 60, -1, 50, -1, -1, -1};

    Node *node = createTree(arr);
    display(node);
    Node *root=linearizeAndReturnTail(node);
    display(node);
    return 0;
}