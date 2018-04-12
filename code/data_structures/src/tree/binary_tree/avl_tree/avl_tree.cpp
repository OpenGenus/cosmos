/*
 * Part of Cosmos by OpenGenus Foundation
 * avl tree synopsis
 *
 * template<typename _Tp, typename _Comp = std::less<_Tp> >
 * class avl_tree {
 * private:
 *  struct AVLNode {
 *      _Tp data;
 *      std::shared_ptr<AVLNode> left;
 *      std::shared_ptr<AVLNode> right;
 *      int height;
 *  };
 *
 *  typedef _Tp                      value_type;
 *  typedef AVLNode                  node_type;
 *  typedef std::shared_ptr<AVLNode> p_node_type;
 *
 * public:
 *  avl_tree() :root_(nullptr);
 *
 *  // function to insert a node into the AVL tree
 *  void insert(int data);
 *
 *  // function to delete a node from the AVL tree
 *  void erase(int data);
 *
 *  // helper function to return height of a node
 *  int getHeight(p_node_type node);
 *
 *  // function to find the minimum element in the tree (lefftmost node)
 *  p_node_type findMin(p_node_type root_);
 *
 *  // function to find the maximum element in the tree (rightmost node)
 *  p_node_type findMax(p_node_type root_);
 *
 *  // preorder traversal of the AVL tree
 *  void preOrder(std::ostream &out) const;
 *
 *  // inorder traversal of the AVL tree
 *  void inOrder(std::ostream &out) const;
 *
 *  // postorder traversal of the AVL tree
 *  void postOrder(std::ostream &out) const;
 *
 * private:
 *  p_node_type root_;
 *  _Comp comp_;
 *
 *  // LL rotation root_ed at X
 *  p_node_type rotateLL(p_node_type &X);
 *
 *  // RR rotation root_ed at X
 *  p_node_type rotateRR(p_node_type &X);
 *
 *  // LR rotation root_ed at X
 *  p_node_type rotateLR(p_node_type &X);
 *
 *  // RL rotation root_ed at X
 *  p_node_type rotateRL(p_node_type &X);
 *
 *  // function to insert a node into the AVL tree
 *  p_node_type insert(p_node_type root_, int data);
 *
 *  // function to delete a node from the AVL tree
 *  p_node_type erase(p_node_type root_, int data);
 *
 *  // preorder traversal of the AVL tree
 *  void preOrder(p_node_type root_, std::ostream &out) const;
 *
 *  // inorder traversal of the AVL tree
 *  void inOrder(p_node_type root_, std::ostream &out) const;
 *
 *  // postorder traversal of the AVL tree
 *  void postOrder(p_node_type root_, std::ostream &out) const;
 * };
 */

#include <algorithm>
#include <memory>
#include <ostream>

template<typename _Tp, typename _Comp = std::less<_Tp>>
class avl_tree {
private:
    struct AVLNode
    {
        _Tp data;
        std::shared_ptr<AVLNode> left;
        std::shared_ptr<AVLNode> right;
        int height;
    };

    typedef _Tp value_type;
    typedef AVLNode node_type;
    typedef std::shared_ptr<AVLNode> p_node_type;

public:
    avl_tree() : root_(nullptr)
    {
        ;
    }

// function to insert a node into the AVL tree
    void insert(int data)
    {
        root_ = insert(root_, data);
    }

// function to delete a node from the AVL tree
    void erase(int data)
    {
        root_ = erase(root_, data);
    }

// helper function to return height of a node
    int getHeight(p_node_type node)
    {
        if (node)
            return node->height;

        return -1;
    }

// function to find the minimum element in the tree (lefftmost node)
    p_node_type findMin(p_node_type root_)
    {
        if (root_ != nullptr)
            while (root_->left != nullptr)
                root_ = root_->left;

        return root_;
    }

// function to find the maximum element in the tree (rightmost node)
    p_node_type findMax(p_node_type root_)
    {
        if (root_ != nullptr)
            while (root_->right != nullptr)
                root_ = root_->right;

        return root_;
    }

// preorder traversal of the AVL tree
    void preOrder(std::ostream &out) const
    {
        preOrder(root_, out);
    }

// inorder traversal of the AVL tree
    void inOrder(std::ostream &out) const
    {
        inOrder(root_, out);
    }

// postorder traversal of the AVL tree
    void postOrder(std::ostream &out) const
    {
        postOrder(root_, out);
    }

private:
    p_node_type root_;
    _Comp comp_;

// LL rotation root_ed at X
    p_node_type rotateLL(p_node_type &X)
    {
        p_node_type W = X->left;
        X->left = W->right;
        W->right = X;
        X->height = std::max(getHeight(X->left), getHeight(X->right)) + 1;
        W->height = std::max(getHeight(W->left), getHeight(X)) + 1;

        return W;   // new root_
    }

// RR rotation root_ed at X
    p_node_type rotateRR(p_node_type &X)
    {
        p_node_type W = X->right;
        X->right = W->left;
        W->left = X;
        X->height = std::max(getHeight(X->left), getHeight(X->right)) + 1;
        W->height = std::max(getHeight(X), getHeight(W->right));

        return W;   // new root_
    }

// LR rotation root_ed at X
    p_node_type rotateLR(p_node_type &X)
    {
        X->left = rotateRR(X->left);

        return rotateLL(X);
    }

// RL rotation root_ed at X
    p_node_type rotateRL(p_node_type &X)
    {
        X->right = rotateLL(X->right);

        return rotateRR(X);
    }

// function to insert a node into the AVL tree
    p_node_type insert(p_node_type root_, int data)
    {
        if (root_ == nullptr)
        {
            p_node_type newNode = std::make_shared<node_type>();
            newNode->data = data;
            newNode->height = 0;
            newNode->left = newNode->right = nullptr;
            root_ = newNode;
        }
        else if (comp_(data, root_->data))
        {
            root_->left = insert(root_->left, data);
            if (getHeight(root_->left) - getHeight(root_->right) == 2)
            {
                if (comp_(data, root_->left->data))
                    root_ = rotateLL(root_);
                else
                    root_ = rotateLR(root_);
            }
        }
        else if (comp_(root_->data, data))
        {
            root_->right = insert(root_->right, data);
            if (getHeight(root_->right) - getHeight(root_->left) == 2)
            {
                if (comp_(root_->right->data, data))
                    root_ = rotateRR(root_);
                else
                    root_ = rotateRL(root_);
            }
        }
        root_->height = std::max(getHeight(root_->left), getHeight(root_->right)) + 1;

        return root_;
    }

// function to delete a node from the AVL tree
    p_node_type erase(p_node_type root_, int data)
    {
        if (root_ == nullptr)
            return nullptr;
        else if (comp_(data, root_->data))
        {
            root_->left = erase(root_->left, data);
            if (getHeight(root_->right) - getHeight(root_->left) == 2)
            {
                if (getHeight(root_->right->right) > getHeight(root_->right->left))
                    root_ = rotateRR(root_);
                else
                    root_ = rotateRL(root_);
            }
        }
        else if (comp_(root_->data, data))
        {
            root_->right = erase(root_->right, data);
            if (getHeight(root_->left) - getHeight(root_->right) == 2)
            {
                if (getHeight(root_->left->left) > getHeight(root_->left->right))
                    root_ = rotateLL(root_);
                else
                    root_ = rotateLR(root_);
            }
        }
        else
        {
            p_node_type temp = nullptr;
            if (root_->left && root_->right)
            {
                temp = findMin(root_->right);
                root_->data = temp->data;
                root_->right = erase(root_->right, root_->data);
                if (getHeight(root_->left) - getHeight(root_->right) == 2)
                {
                    if (getHeight(root_->left->left) > getHeight(root_->left->right))
                        root_ = rotateLL(root_);
                    else
                        root_ = rotateLR(root_);
                }
            }
            else if (root_->left)
            {
                temp = root_;
                root_ = root_->left;
            }
            else if (root_->right)
            {
                temp = root_;
                root_ = root_->right;
            }
            else
                return nullptr;
        }

        return root_;
    }

// preorder traversal of the AVL tree
    void preOrder(p_node_type root_, std::ostream &out) const
    {
        if (root_ != nullptr)
        {
            out << (root_)->data << " ";
            preOrder((root_)->left, out);
            preOrder((root_)->right, out);
        }
    }

// inorder traversal of the AVL tree
    void inOrder(p_node_type root_, std::ostream &out) const
    {
        if (root_ != nullptr)
        {
            inOrder((root_)->left, out);
            out << (root_)->data << " ";
            inOrder((root_)->right, out);
        }
    }

// postorder traversal of the AVL tree
    void postOrder(p_node_type root_, std::ostream &out) const
    {
        if (root_ != nullptr)
        {
            postOrder((root_)->left, out);
            postOrder((root_)->right, out);
            out << (root_)->data << " ";
        }
    }
};

/*
 * // for test
 #include <iostream>
 * using namespace std;
 * int main() {
 *  int ch, data;
 *  shared_ptr<avl_tree<int> > avlt = make_shared<avl_tree<int> >();
 *  while (1)
 *  {
 *      cout << "1. Insert 2. Delete 3. Preorder 4. Inorder 5. Postorder 6. Exit\n";
 *      cin >> ch;
 *      switch (ch) {
 *      case 1: cout << "Enter data\n";
 *          cin >> data;
 *          avlt->insert(data);
 *          break;
 *      case 2: cout << "Enter data\n";
 *          cin >> data;
 *          avlt->erase(data);
 *          break;
 *      case 3: avlt->preOrder(cout);
 *          cout << endl;
 *          break;
 *      case 4: avlt->inOrder(cout);
 *          cout << endl;
 *          break;
 *      case 5: avlt->postOrder(cout);
 *          cout << endl;
 *          break;
 *      }
 *      if (ch == 6)
 *          break;
 *  }
 *
 *  return 0;
 * }
 *
 * // */
