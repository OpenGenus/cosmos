/*
 * Part of Cosmos by OpenGenus Foundation
 * arne andersson tree synopsis
 *
 * template<typename _Derive, typename _Tp, typename _Comp = std::less<_Tp> >
 * struct BinaryTreeNode {
 *  _Tp value;
 *  std::shared_ptr<_Derive> left, right;
 *  BinaryTreeNode(_Tp v,
 *                 std::shared_ptr<_Derive> l = nullptr,
 *                 std::shared_ptr<_Derive> r = nullptr);
 * };
 *
 * template<typename _Tp, typename _Comp = std::less<_Tp> >
 * struct AABinaryTreeNode :public BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp> {
 *  size_t level;
 *  AABinaryTreeNode(_Tp v,
 *                   std::shared_ptr<AABinaryTreeNode> l = nullptr,
 *                   std::shared_ptr<AABinaryTreeNode> r = nullptr);
 * };
 *
 * template<typename _Tp,
 *       typename _Comp = std::less<_Tp>,
 *       typename _NodeType = BinaryTreeNode<_Tp, _Comp> >
 * class BinaryTree {
 * public:
 *  typedef _Tp               value_type;
 *  typedef value_type &      reference;
 *  typedef value_type const &const_reference;
 *  typedef std::ptrdiff_t         difference_type;
 *  typedef size_t            size_type;
 *
 * protected:
 *  typedef BinaryTree<_Tp, _Comp, _NodeType> self;
 *  typedef _NodeType                         node_type;
 *  typedef std::shared_ptr<node_type>        p_node_type;
 *
 * public:
 *  BinaryTree(p_node_type r = nullptr) :root_(r), sz_(0), comp_(_Comp()), release_(true);
 *
 *  p_node_type const maximum() const;
 *
 *  p_node_type const minimum() const;
 *
 *  size_type size() const;
 *
 *  bool empty() const;
 *
 *  void inOrder(std::ostream &output) const;
 *
 *  void preOrder(std::ostream &output) const;
 *
 *  void postOrder(std::ostream &output) const;
 *
 * protected:
 *  p_node_type root_;
 *  size_type sz_;
 *  _Comp comp_;
 *  bool release_;
 *  p_node_type nil_;
 *
 *  p_node_type get(const_reference value);
 *
 *  p_node_type const maximum(p_node_type n) const;
 *
 *  p_node_type const minimum(p_node_type n) const;
 *
 *  void inOrder(std::ostream &output, p_node_type const n) const;
 *
 *  void preOrder(std::ostream &output, p_node_type const n) const;
 *
 *  void postOrder(std::ostream &output, p_node_type const n) const;
 * };
 *
 * template<typename _Tp, typename _Comp = std::less<_Tp> >
 * class AATree :public BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp> > {
 * private:
 *  typedef BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp> > base;
 *  typedef AATree<_Tp, _Comp>                                    self;
 *
 * public:
 *  using typename base::size_type;
 *  using typename base::value_type;
 *  using typename base::reference;
 *  using typename base::const_reference;
 *  using typename base::difference_type;
 *
 * protected:
 *  using typename base::p_node_type;
 *  using typename base::node_type;
 *  using base::root_;
 *  using base::comp_;
 *  using base::nil_;
 *  using base::sz_;
 *
 * public:
 *  AATree() :base();
 *
 *  void insert(const_reference value);
 *
 *  void erase(const_reference value);
 *
 *  p_node_type const find(const_reference value);
 *
 * private:
 *  // implement by recursive
 *  void insert(p_node_type &n, const_reference value);
 *
 *  void erase(p_node_type &n, const_reference value);
 *
 *  // input: T, a node representing an AA tree that needs to be rebalanced.
 *  // output: Another node representing the rebalanced AA tree.
 *  p_node_type skew(p_node_type n);
 *
 *  // input: T, a node representing an AA tree that needs to be rebalanced.
 *  // output: Another node representing the rebalanced AA tree
 *  p_node_type split(p_node_type n);
 *
 *  void makeNode(p_node_type &n, value_type value);
 * };
 */

#include <algorithm>
#include <functional>
#include <memory>
#include <stack>
#include <cstddef>

template<typename _Derive, typename _Tp, typename _Comp = std::less<_Tp>>
struct BinaryTreeNode
{
    _Tp value;
    std::shared_ptr<_Derive> left, right;
    BinaryTreeNode(_Tp v,
                   std::shared_ptr<_Derive> l = nullptr,
                   std::shared_ptr<_Derive> r = nullptr)
        : value(v), left(l), right(r)
    {
    };
};

template<typename _Tp, typename _Comp = std::less<_Tp>>
struct AABinaryTreeNode : public BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp>
{
    size_t level;
    AABinaryTreeNode(_Tp v,
                     std::shared_ptr<AABinaryTreeNode> l = nullptr,
                     std::shared_ptr<AABinaryTreeNode> r = nullptr)
        : BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp>(v, l, r), level(1)
    {
    };
};

template<typename _Tp,
         typename _Comp = std::less<_Tp>,
         typename _NodeType = BinaryTreeNode<_Tp, _Comp>>
class BinaryTree {
public:
    typedef _Tp value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

protected:
    typedef BinaryTree<_Tp, _Comp, _NodeType> self;
    typedef _NodeType node_type;
    typedef std::shared_ptr<node_type>        p_node_type;

public:
    BinaryTree(p_node_type r = nullptr) : root_(r), sz_(0), comp_(_Comp()), release_(true)
    {
    };

    p_node_type const maximum() const
    {
        auto f = maximum(root_);
        if (f == nil_)
            return nullptr;

        return f;
    }

    p_node_type const minimum() const
    {
        auto f = minimum(root_);
        if (f == nil_)
            return nullptr;

        return f;
    }

    size_type size() const
    {
        return sz_;
    }

    bool empty() const
    {
        return sz_ == 0;
    }

    void inOrder(std::ostream &output) const
    {
        inOrder(output, root_);
    }

    void preOrder(std::ostream &output) const
    {
        preOrder(output, root_);
    }

    void postOrder(std::ostream &output) const
    {
        postOrder(output, root_);
    }

protected:
    p_node_type root_;
    size_type sz_;
    _Comp comp_;
    bool release_;
    p_node_type nil_;

    p_node_type get(const_reference value)
    {
        p_node_type n = root_;
        while (n != nil_)
        {
            if (comp_(value, n->value))
                n = n->left;
            else if (comp_(n->value, value))
                n = n->right;
            else
                break;
        }

        return n;
    }

    p_node_type const maximum(p_node_type n) const
    {
        if (n != nil_)
            while (n->right != nil_)
                n = n->right;

        return n;
    }

    p_node_type const minimum(p_node_type n) const
    {
        if (n != nil_)
            while (n->left != nil_)
                n = n->left;

        return n;
    }

    void inOrder(std::ostream &output, p_node_type const n) const
    {
        if (n != nil_)
        {
            inOrder(output, n->left);
            output << n->value << " ";
            inOrder(output, n->right);
        }
    }

    void preOrder(std::ostream &output, p_node_type const n) const
    {
        if (n != nil_)
        {
            output << n->value << " ";
            preOrder(output, n->left);
            preOrder(output, n->right);
        }
    }

    void postOrder(std::ostream &output, p_node_type const n) const
    {
        if (n != nil_)
        {
            postOrder(output, n->left);
            output << n->value << " ";
            postOrder(output, n->right);
        }
    }
};

template<typename _Tp, typename _Comp = std::less<_Tp>>
class AATree : public BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp>> {
private:
    typedef BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp>> base;
    typedef AATree<_Tp, _Comp>                                    self;

public:
    using typename base::size_type;
    using typename base::value_type;
    using typename base::reference;
    using typename base::const_reference;
    using typename base::difference_type;

protected:
    using typename base::p_node_type;
    using typename base::node_type;
    using base::root_;
    using base::comp_;
    using base::nil_;
    using base::sz_;

public:
    AATree() : base()
    {
        nil_ = std::make_shared<node_type>(0);
        nil_->left = nil_;
        nil_->right = nil_;
        nil_->level = 0;
        root_ = nil_;
    }

    void insert(const_reference value)
    {
        insert(root_, value);
    }

    void erase(const_reference value)
    {
        erase(root_, value);
    }

    p_node_type const find(const_reference value)
    {
        auto f = base::get(value);
        if (f == nil_)
            return nullptr;

        return f;
    }

private:
// implement by recursive
    void insert(p_node_type &n, const_reference value)
    {
        if (n == nil_)
        {
            makeNode(n, value);
            ++sz_;
        }
        else
        {
            if (comp_(value, n->value))
                insert(n->left, value);
            else if (comp_(n->value, value))
                insert(n->right, value);
            else        // depend on implement
                n->value = value;
        }
        n = skew(n);
        n = split(n);
    }

    void erase(p_node_type &n, const_reference value)
    {
        if (n != nil_)
        {
            if (comp_(value, n->value))
                erase(n->left, value);
            else if (comp_(n->value, value))
                erase(n->right, value);
            else
            {
                if (n->left != nil_ && n->right != nil_)
                {
                    p_node_type leftMax = n->left;
                    while (leftMax->right != nil_)
                        leftMax = leftMax->right;
                    n->value = leftMax->value;
                    erase(n->left, n->value);
                }
                else     // 3 way, n is leaf then nullptr, otherwise n successor
                {
                    p_node_type successor = n->left == nil_ ? n->right : n->left;
                    n = successor;
                    --sz_;
                }
            }
        }

        if (n != nil_
            && (n->left->level < n->level - 1 || n->right->level < n->level - 1))
        {
            --n->level;
            if (n->right->level > n->level)
                n->right->level = n->level;
            n = skew(n);
            if (n->right != nil_)
                n->right = skew(n->right);
            if (n->right != nil_ && n->right != nil_)
                n->right->right = skew(n->right->right);
            n = split(n);
            if (n->right != nil_)
                n->right = split(n->right);
        }
    }

// input: T, a node representing an AA tree that needs to be rebalanced.
// output: Another node representing the rebalanced AA tree.
    p_node_type skew(p_node_type n)
    {
        if (n != nil_
            && n->left != nil_
            && n->left->level == n->level)
        {
            p_node_type left = n->left;
            n->left = left->right;
            left->right = n;
            n = left;
        }

        return n;
    }

// input: T, a node representing an AA tree that needs to be rebalanced.
// output: Another node representing the rebalanced AA tree
    p_node_type split(p_node_type n)
    {
        if (n != nil_
            && n->right != nil_
            && n->right->right != nil_
            && n->level == n->right->right->level)
        {
            p_node_type right = n->right;
            n->right = right->left;
            right->left = n;
            n = right;
            ++n->level;
        }

        return n;
    }

    void makeNode(p_node_type &n, value_type value)
    {
        n = std::make_shared<node_type>(value, nil_, nil_);
    }
};

/*
 * // for test
 * // test insert/erase/size function
 #include <iostream>
 * using namespace std;
 *
 * int main() {
 *  std::shared_ptr<AATree<int> > aat = make_shared<AATree<int> >();
 *
 *  if (!aat->empty())
 *      cout << "error";
 *
 *  auto f = aat->find(3);
 *  if (f != nullptr)
 *      cout << "error";
 *
 *  f = aat->maximum();
 *  if (f != nullptr)
 *      cout << "error";
 *
 *  f = aat->minimum();
 *  if (f != nullptr)
 *      cout << "error";
 *
 *  aat->insert(0);
 *  f = aat->find(0);
 *  if (f == nullptr)
 *      cout << "error";
 *
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(1);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(2);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(3);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(4);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(5);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(6);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(0);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(3);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(1);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(7);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(3);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(7);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(3);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(3);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->insert(1);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(7);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *  aat->erase(8);
 *  aat->inOrder(cout); cout << "\n"; aat->preOrder(cout); cout << "\n";
 *  cout << aat->size() << "\n\n";
 *
 *  f = aat->maximum();
 *  if (f == nullptr || f->value != 6)
 *      cout << "error";
 *
 *  f = aat->minimum();
 *  if (f == nullptr || f->value != 1)
 *      cout << "error";
 *
 *  if (aat->empty())
 *      cout << "error";
 *
 *  return 0;
 * }
 *
 *
 * expected:
 * 0
 * 0
 * 1
 *
 * 0 1
 * 0 1
 * 2
 *
 * 0 1 2
 * 1 0 2
 * 3
 *
 * 0 1 2 3
 * 1 0 2 3
 * 4
 *
 * 0 1 2 3 4
 * 1 0 3 2 4
 * 5
 *
 * 0 1 2 3 4 5
 * 1 0 3 2 4 5
 * 6
 *
 * 0 1 2 3 4 5 6
 * 3 1 0 2 5 4 6
 * 7
 *
 * 1 2 3 4 5 6
 * 3 1 2 5 4 6
 * 6
 *
 * 1 2 4 5 6
 * 2 1 5 4 6
 * 5
 *
 * 2 4 5 6
 * 4 2 5 6
 * 4
 *
 * 2 4 5 6 7
 * 4 2 6 5 7
 * 5
 *
 * 2 3 4 5 6 7
 * 4 2 3 6 5 7
 * 6
 *
 * 2 3 4 5 6
 * 4 2 3 5 6
 * 5
 *
 * 2 4 5 6
 * 4 2 5 6
 * 4
 *
 * 2 3 4 5 6
 * 4 2 3 5 6
 * 5
 *
 * 1 2 3 4 5 6
 * 2 1 4 3 5 6
 * 6
 *
 * 1 2 3 4 5 6
 * 2 1 4 3 5 6
 * 6
 *
 * 1 2 3 4 5 6
 * 2 1 4 3 5 6
 * 6
 *
 */
