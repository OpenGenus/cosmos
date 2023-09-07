#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *construct(vector<int> &datalist)
{
    Node *root = NULL;
    vector<Node *> newlist;

    for (int i = 0; i < datalist.size(); i++)
    {
        if (datalist[i] == -1)
        {
            newlist.pop_back();
        }

        else
        {
            Node *newnode = new Node(datalist[i]);
            if (newlist.size() == 0)
            {
                root = newnode;
            }

            else
            {
                Node *top_of_stack = newlist.back();
                if (top_of_stack->left == NULL)
                {
                    top_of_stack->left = newnode;
                }

                else
                {
                    top_of_stack->right = newnode;
                }
            }
            newlist.push_back(newnode);
        }
    }
    return (root);
}

void RootToLeafPathInRange(Node *root, int low, int high, vector<int> &path, int sum)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        path.push_back(root->data);
        sum = sum + root->data;
        if (sum >= low && sum <= high)
        {
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " " << endl;
            }
        }
        return;
    }

    path.push_back(root->data);
    RootToLeafPathInRange(root->left, low, high, path, sum + root->data);
    RootToLeafPathInRange(root->right, low, high, path, sum + root->data);
    path.pop_back();
}

display(Node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        cout << root->left->data << "<-" << root->data << "->" << root->right->data << endl;
        display(root->left);
        display(root->right);
    }

    else if (root->left != NULL)
    {
        cout << root->left->data << "<-" << root->data << "." << endl;
        display(root->left);
    }

    else if (root->right != NULL)
    {
        cout << "." << root->data << "->" << root->right->data << endl;
        display(root->right);
    }

    else
    {
        cout << "." << root->data << "." << endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> list;

    for (int i = 0; i < 30; i++) // 30 is the no of nodes including '-1'
    {
        int input;
        cin >> input;
        list.push_back(input);
    }

    Node *root = construct(list);
    display(root);

    cout << "Root to Leaf Paths in Range (low,high)" << endl;
    vector<int> path;

    RootToLeafPathInRange(root, 100, 140, path, 120);
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << endl;
    }
}

//Sample Input
//50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1
