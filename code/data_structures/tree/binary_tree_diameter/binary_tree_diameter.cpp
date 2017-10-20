/*
    Part of Cosmos by OpenGenus Foundation

    diameter of tree synopsis

template<typename _TreeNode>
size_t diameter_impl(_TreeNode *node, size_t &max);

template<typename _TreeNode>
size_t diameter(_TreeNode *node);
*/

#include <functional>

template<typename _TreeNode>
size_t diameter_impl(_TreeNode *node, size_t &max) {
    if (node != nullptr) {
        size_t left_max{}, right_max{};

        // DFS
        size_t left_height = diameter_impl(node->left, left_max);
        size_t right_height = diameter_impl(node->right, right_max);

        max = left_height + right_height + 1;
        max = std::max(max, left_max);
        max = std::max(max, right_max);

        return std::max(left_height, right_height) + 1;
    }

    return 0;
}

template<typename _TreeNode>
size_t diameter(_TreeNode *node) {
    size_t res{};
    diameter_impl(node, res);

    return res;
}

/*
// for test
#include <iostream>

struct node {
    struct node *left;
    struct node *right;
    node() :left(nullptr), right(nullptr) {;}
};
int main()
{
    using namespace std;

//        root
//        / \
//       l   r
//      / \
//    ll   lr
//    /     \
//  lll     lrr
//  /         \
//llll       (lrrr) ->   test1: without=6(llll->r), test2: within=7(llll->lrrr)

    node *root = nullptr;
    if (diameter(root) != 0)
        cout << "error" << endl;  // boundary test
    root = new node();

    node *l = new node(); root->left = l;
    node *r = new node();

    node *ll = new node(); l->left = ll;
    node *lr = new node(); l->right = lr;

    node *lll = new node(); ll->left = lll;
    node *lrr = new node(); lr->right = lrr;

    node *llll = new node(); lll->left = llll;

    if (diameter(root) != 6)
        cout << "error" << endl;

    node *lrrr = new node(); lrr->right = lrrr;

    if (diameter(root) != 7)
        cout << "error" << endl;

    return 0;
}

// */
