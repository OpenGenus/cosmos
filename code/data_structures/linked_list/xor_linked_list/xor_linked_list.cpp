/*
 Part of Cosmos by OpenGenus Foundation

 xor linked list synopsis

 *** incomplete ***

 */

#ifndef XOR_LINKED_LIST_CPP
#define XOR_LINKED_LIST_CPP

#include <memory>
#include <functional>
#include <iterator>
#include <iostream>

template<typename _Type>
class __Node
{
private:
    using value_type = _Type;
    using SPNode = __Node<value_type> *;

public:
    explicit __Node(value_type value) :value_(value), around_(nullptr) {}

    inline SPNode around(SPNode const &around)
    {
        return reinterpret_cast<SPNode>(reinterpret_cast<uintptr_t>(around) ^
                                        reinterpret_cast<uintptr_t>(around_));
    }

    inline void around(SPNode const &prev, SPNode const &next)
    {
        around_ = reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(prev) ^
                                           reinterpret_cast<uintptr_t>(next));
    }

    inline value_type &value()
    {
        return value_;
    }

    inline value_type const &value() const
    {
        return value_;
    }

    inline void value(value_type v)
    {
        value_ = v;
    }

private:
    value_type value_;
    void *around_;
};

template<typename _Type, typename _Compare = std::less<_Type>>
class XorLinkedList;

template<class _Type>
class ListConstIter;

template<class _Type>
class ListIter :public std::iterator<std::bidirectional_iterator_tag, _Type>
{
public:
    using value_type = _Type;
    using difference_type = ptrdiff_t;
    using pointer = _Type *;
    using reference = _Type &;
    using iterator_category = std::bidirectional_iterator_tag;

private:
    using NodePtr = __Node<value_type> *;
    using Self = ListIter<value_type>;

public:
    ListIter() {}

    explicit ListIter(NodePtr node, NodePtr prev) :curr_(node), prev_(prev) {}

    ListIter(const Self &it) :curr_(it.curr_), prev_(it.prev_) {}

    reference operator*()
    {
        return curr_->value();
    }

    pointer operator->()
    {
        return &curr_->value();
    }

    Self &operator++()
    {
        auto next = curr_->around(prev_);
        prev_ = curr_;
        curr_ = next;

        return *this;
    }

    Self operator++(int i)
    {
        auto temp = *this;
        ++*this;

        return temp;
    }

    Self &operator--()
    {
        auto prevOfprev = prev_->around(curr_);
        curr_ = prev_;
        prev_ = prevOfprev;

        return *this;
    }

    Self operator--(int i)
    {
        auto temp = *this;
        --*this;

        return temp;
    }

    bool operator==(Self const &other) const
    {
        return curr_ == other.curr_;
    }

    bool operator!=(Self const &other) const
    {
        return curr_ != other.curr_;
    }

private:
    NodePtr curr_, prev_;
    friend XorLinkedList<value_type>;
    friend ListConstIter<value_type>;
};

template<class _Type>
class ListConstIter :public std::iterator<std::bidirectional_iterator_tag, _Type>
{
public:
    using value_type = _Type;
    using difference_type = ptrdiff_t;
    using pointer = _Type const *;
    using reference = _Type const &;
    using iterator_category = std::bidirectional_iterator_tag;

private:
    using NodePtr = __Node<value_type> *;
    using Self = ListConstIter<value_type>;
    using iterator = ListIter<value_type>;

public:
    ListConstIter() {}

    explicit ListConstIter(NodePtr node, NodePtr prev) :curr_(node), prev_(prev) {}

    ListConstIter(const iterator &it) :curr_(it.curr_), prev_(it.prev_) {}

    reference operator*() const
    {
        return curr_->value();
    }

    pointer operator->() const
    {
        return &curr_->value();
    }

    Self &operator++()
    {
        auto next = curr_->around(prev_);
        prev_ = curr_;
        curr_ = next;

        return *this;
    }

    Self operator++(int i)
    {
        auto temp = *this;
        ++*this;

        return temp;
    }

    Self &operator--()
    {
        auto prevOfprev = prev_->around(curr_);
        curr_ = prev_;
        prev_ = prevOfprev;

        return *this;
    }

    Self operator--(int i)
    {
        auto temp = *this;
        --*this;

        return temp;
    }

    bool operator==(Self const &other) const
    {
        return curr_ == other.curr_;
    }

    bool operator!=(Self const &other) const
    {
        return curr_ != other.curr_;
    }

public:
    NodePtr curr_, prev_;
    friend XorLinkedList<value_type>;
};

template<typename _Type, typename _Compare>
class XorLinkedList
{
private:
    using Node = __Node<_Type>;
    using NodePtr = __Node<_Type> *;
    using Self = XorLinkedList<_Type, _Compare>;

public:
    using value_type = _Type;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = value_type const *;
    using const_pointer = value_type const *;
    using reference = value_type &;
    using const_reference = value_type const &;

    using iterator = ListIter<value_type>;
    using const_iterator = ListConstIter<value_type>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    explicit XorLinkedList() :begin_(new Node(0)), end_(begin_), sz_(0)
    {}

    XorLinkedList(Self const &list) :begin_(new Node(0)), end_(begin_), sz_(0)
    {
        for_each(list.begin(), list.end(), [&](value_type v)
        {
            push_back(v);
        });
    };

    XorLinkedList(std::initializer_list<value_type> &&vs) :begin_(new Node(0)), end_(begin_), sz_(0)
    {
        std::for_each(vs.begin(), vs.end(), [&](value_type v)
        {
            push_back(v);
        });
    }

    ~XorLinkedList()
    {
        clear();
        delete end_;
    }

    inline reference front();

    inline reference back();

    inline const_reference front() const;

    inline const_reference back() const;

    void push_front(value_type const &v);

    void push_back(value_type const &v);

    void pop_front();

    void pop_back();

    void insert(iterator pos, value_type const &v);

    void erase(iterator pos);

    iterator find(value_type const &v);

    void reverse();

    // void unique();
    //
    // void sort();

    inline size_type max_size() const;

    inline size_type size() const;

    inline bool empty() const;

    void clear();

    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    iterator end();

    const_iterator end() const;

    const_iterator cend() const;

    reverse_iterator rbegin();

    const_reverse_iterator rbegin() const;

    const_reverse_iterator crbegin() const;

    reverse_iterator rend();

    const_reverse_iterator rend() const;

    const_reverse_iterator crend() const;

private:
    NodePtr begin_, end_;
    size_type sz_;

    inline void insertToEmpty(value_type const &v);

    inline NodePtr insertBetween(NodePtr &prev, NodePtr &curr, value_type const &v);

    inline void eraseOnlyOne();

    inline void eraseNode(NodePtr &popNode, NodePtr &prev);

    inline NodePtr &findPrev(NodePtr &node);
};

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::front()->reference
{
    if (empty())
        throw "the list is empty !";

    return begin_->value();
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::back()->reference
{
    if (empty())
        throw "the list is empty !";

    return end_->around(begin_)->value();
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::front() const->const_reference
{
    return const_cast<Self *>(this)->front();
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::back() const->const_reference
{
    return const_cast<Self *>(this)->back();
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::push_front(value_type const &v)
{
    if (empty())
        insertToEmpty(v);
    else
        insert(begin(), v);
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::push_back(value_type const &v)
{
    if (empty())
        insertToEmpty(v);
    else
        insert(end(), v);
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::pop_front()
{
    if (empty())
        throw "list is empty";
    else
        erase(begin());
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::pop_back()
{
    if (empty())
        throw "list is empty";
    else
        erase(--end());
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::insert(iterator pos, value_type const &v)
{
    if (empty())
        insertToEmpty(v);
    else
        insertBetween(pos.prev_, pos.curr_, v);
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::erase(iterator pos)
{
    if (pos != end())
    {
        if (size() == 1)
            eraseOnlyOne();
        else
            eraseNode(pos.prev_, pos.curr_);
    }
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::find(value_type const &v)->iterator
{
    return std::find(begin(), end(), v);
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::reverse()
{
    if (!empty())
        begin_ = end_->around(begin_);
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::clear()
{
    auto b = begin();
    while (b != end())
    {
        iterator temp = b;
        ++b;
        delete temp.curr_;
    }
    end_->around(nullptr, nullptr);
    begin_ = end_;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::max_size() const->size_type
{
    return static_cast<size_type>(-1) / sizeof(value_type);
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::size() const->size_type
{
    return sz_;
}

template<typename _Type, typename _Compare>
inline bool
XorLinkedList<_Type, _Compare>::empty() const
{
    return begin_ == end_;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::insertToEmpty(value_type const &v)
{
    begin_ = new Node(v);
    ++sz_;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::insertBetween(NodePtr &prev, NodePtr &curr, value_type const &v)
->NodePtr
{
    auto nextOfNext = curr->around(prev);
    auto prevOfPrev = prev->around(curr);
    auto newCurr = new Node(v);
    newCurr->around(prev, curr);
    curr->around(newCurr, nextOfNext);
    prev->around(prevOfPrev, newCurr);
    if (curr == begin_)
        begin_ = newCurr;
    ++sz_;

    return newCurr;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::eraseOnlyOne()
{
    delete begin_;
    end_->around(nullptr, nullptr);
    begin_ = end_;
    --sz_;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::eraseNode(NodePtr &prev, NodePtr &curr)
{
    auto insteadNode = curr->around(prev);
    auto nextOfInsteadNode = insteadNode->around(curr);
    auto prevOfPrevNode = prev->around(curr);
    insteadNode->around(prev, nextOfInsteadNode);
    prev->around(prevOfPrevNode, insteadNode);
    delete curr;
    if (curr == begin_)
        begin_ = insteadNode;
    --sz_;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::findPrev(NodePtr &node)->NodePtr &
{
    NodePtr &curr = begin_;
    NodePtr &prev = end_;
    while (curr != end_)
    {
        if (curr == node)
            return prev;
        curr = curr->around(prev);
        prev = curr;
    }

    return node;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::begin()->iterator
{
    return iterator(begin_, end_);
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::begin() const->const_iterator
{
    return const_iterator(begin_, end_);
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::cbegin() const->const_iterator
{
    return const_iterator(begin_, end_);
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::end()->iterator
{
    return iterator(end_, end_->around(begin_));
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::end() const->const_iterator
{
    return const_iterator(end_, end_->around(begin_));
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::cend() const->const_iterator
{
    return const_iterator(end_, end_->around(begin_));
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::rbegin()->reverse_iterator
{
    return reverse_iterator(end());
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::rbegin() const->const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::crbegin() const->const_reverse_iterator
{
    return const_reverse_iterator(cend());
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::rend()->reverse_iterator
{
    return reverse_iterator(begin());
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::rend() const->const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

template<typename _Type, typename _Compare>
auto
XorLinkedList<_Type, _Compare>::crend() const->const_reverse_iterator
{
    return const_reverse_iterator(cbegin());
}

#endif // XOR_LINKED_LIST_CPP

// template<class _ListIterator>
// class __ListReverseIterator;

// template<class _ListIterator>
// class __ListReverseIterator :public std::iterator<std::bidirectional_iterator_tag,
// typename _ListIterator::value_type>
// {
// public:
// using value_type = typename _ListIterator::value_type;
// using difference_type = typename _ListIterator::difference_type;
// using pointer = typename _ListIterator::pointer;
// using reference = typename _ListIterator::reference;
// using iterator_category = typename _ListIterator::iterator_category;

// private:
// using NodePtr = __Node<value_type> *;
// using Base = _ListIterator;
// using Self = __ListReverseIterator<Base>;

// public:
// __ListReverseIterator() {}

// explicit __ListReverseIterator(Base it) :base_(it) {}

// __ListReverseIterator(const Self &it) :base_(it.base_) {}

// reference operator*()
// {
// auto next = base_;

// return *++next;
// }

// pointer operator->()
// {
// auto next = base_;

// return ++next.operator->();
// }

// Self &operator++()
// {
// --base_;

// return *this;
// }

// Self operator++(int i)
// {
// base_--;

// return *this;
// }

// Self &operator--()
// {
// ++base_;

// return *this;
// }

// Self operator--(int i)
// {
// base_++;

// return *this;
// }

// bool operator==(Self const &other) const
// {
// return base_ == other.base_;
// }

// bool operator!=(Self const &other) const
// {
// return base_ != other.base_;
// }

// Base base() const
// {
// return base_;
// }

// private:
// Base base_;
// friend XorLinkedList<value_type>;
// };

// template<class _ListConstIterator>
// class __ListConstReverseIterator :public std::iterator<std::bidirectional_iterator_tag,
// typename _ListConstIterator::value_type>
// {
// public:
// using value_type = typename _ListConstIterator::value_type;
// using difference_type = typename _ListConstIterator::difference_type;
// using pointer = typename _ListConstIterator::pointer;
// using reference = typename _ListConstIterator::reference;
// using iterator_category = typename _ListConstIterator::iterator_category;

// private:
// using NodePtr = __Node<value_type> *;
// using Base = _ListConstIterator;
// using Self = __ListConstReverseIterator<Base>;
// using iterator = __ListReverseIterator<Base>;

// public:
// __ListConstReverseIterator() {}

// explicit __ListConstReverseIterator(Base it) :base_(it) {}

// __ListConstReverseIterator(const iterator &it) :base_(it.base_) {}

// reference operator*() const
// {
// auto next = base_;

// return *++next;
// }

// pointer operator->() const
// {
// auto next = base_;

// return ++next.operator->();
// }

// Self &operator++()
// {
// --base_;

// return *this;
// }

// Self operator++(int i)
// {
// base_--;

// return *this;
// }

// Self &operator--()
// {
// ++base_;

// return *this;
// }

// Self operator--(int i)
// {
// base_++;

// return *this;
// }

// bool operator==(Self const &other) const
// {
// return base_ == other.base_;
// }

// bool operator!=(Self const &other) const
// {
// return base_ != other.base_;
// }

// Base base() const
// {
// return base_;
// }

// private:
// Base base_;
// friend XorLinkedList<value_type>;
// };
