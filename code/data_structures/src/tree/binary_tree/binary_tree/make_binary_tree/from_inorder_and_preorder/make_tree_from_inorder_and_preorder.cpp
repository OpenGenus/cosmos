#include <iostream>
#include <cmath>
#include <queue>
#include <cmath>
using namespace std;

template<typename T>
class Binarytreenode {

public:
    T data;
    Binarytreenode<T> * left;
    Binarytreenode<T> * right;


    Binarytreenode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};


void postorder(Binarytreenode<int>* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
    return;
}
Binarytreenode<int> * create(int *preorder, int*inorder, int ps, int pe, int is, int ie)
{
    if (ps > pe || is > ie)
        return NULL;

    int rootdata = preorder[ps];
    Binarytreenode<int> * root = new Binarytreenode<int>(rootdata);
    int k;
    for (int i = is; i <= ie; i++)
        if (inorder[i] == rootdata)
        {
            k = i;
            break;
        }

    root->left = create(preorder, inorder, ps + 1, ps + k - is, is, k - 1);
    root->right = create(preorder, inorder, ps + k - is + 1, pe, k + 1, ie);

    return root;
}
int main()
{
    int preorder[100], inorder[100];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> preorder[i];

    for (int i = 0; i < size; i++)
        cin >> inorder[i];

    Binarytreenode<int> * root = create(preorder, inorder, 0, size - 1, 0, size - 1);


    postorder(root);


}
