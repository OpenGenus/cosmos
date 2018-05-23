#include <iostream>
using namespace std;

class node {
private:
    int value;
    node* left, *right;
public:
    node()
    {
    };
    ~node()
    {
    };
    node* create_node(int& val);
    void create_tree(int& val);
    int height_tree(node* tmp);
    void cleanup_tree(node* tmp);
    inline int maximum(int left_ht, int right_ht)
    {
        return left_ht > right_ht ? left_ht : right_ht;
    }
};

static node* root = NULL;
node* node::create_node(int& val)
{
    node* tmp = new node;
    tmp->value = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void node::create_tree(int& val)
{
    node* tmp = root;
    if (!root)
        root = create_node(val);
    else
        while (1)
        {
            if (val > tmp->value)
            {
                if (!tmp->right)
                {
                    tmp->right = create_node(val);
                    break;
                }
                else
                    tmp = tmp->right;
            }
            else
            {
                if (!tmp->left)
                {
                    tmp->left = create_node(val);
                    break;
                }
                else
                    tmp = tmp->left;
            }
        }

}

int node::height_tree(node* tmp)
{
    if (!tmp)
        return 0;
    int left_ht = height_tree(tmp->left);
    int right_ht = height_tree(tmp->right);
    return 1 + max(left_ht, right_ht);
}

void node::cleanup_tree(node* tmp)
{
    if (tmp)
    {
        cleanup_tree(tmp->left);
        cleanup_tree(tmp->right);
        if (tmp->left)
            delete tmp->left;
        if (tmp->right)
            delete tmp->right;
    }
    if (tmp == root)
        delete root;
}


int main()
{
    int val, num;
    node tmp;
    cout << "Enter number of nodes" << endl;
    cin >> num;
    for (int ctr = 0; ctr < num; ctr++)
    {
        cout << "Enter values" << endl;
        cin >> val;
        tmp.create_tree(val);
    }
    int tree_ht = tmp.height_tree(root);
    cout << "Height of tree is " << tree_ht << endl;
    tmp.cleanup_tree(root);
    return 0;
}
