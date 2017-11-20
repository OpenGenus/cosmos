/*
 Part of Cosmos by OpenGenus Foundation

 diameter of tree synopsis

 *** incomplete ***

 */


#ifndef XOR_LINKED_LIST_CPP
#define XOR_LINKED_LIST_CPP

#include <memory>
#include <functional>
#include <iterator>
#include <iostream>

template<typename _Type>
class XorLinkedListNode
{
private:
    using value_type = _Type;
    using SPNode = XorLinkedListNode<value_type> *;

public:
    explicit XorLinkedListNode(value_type value) :value_(value), around_(nullptr) {}

    inline SPNode around(SPNode const &around)
    {
        void *res = (void *)((uintptr_t)(around) ^ (uintptr_t)around_);

        return static_cast<SPNode>(res);
    }

    inline void around(SPNode const &prev, SPNode const &next)
    {
        around_ = (void *)((uintptr_t)(prev) ^ (uintptr_t)(next));
    }

    inline value_type &value()
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

template<class _Type>
class XorLinkedListIter :public std::iterator<std::bidirectional_iterator_tag, _Type>
{
    // todo
};

template<class _Type>
class XorLinkedListReverseIter :public std::iterator<std::bidirectional_iterator_tag, _Type>
{};

template<typename _Type, typename _Compare = std::less<_Type>>
class XorLinkedList
{
private:
    using list_node_type = XorLinkedListNode<_Type>;
    using const_list_node_type = XorLinkedListNode<const _Type>;

public:
    using value_type = _Type;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = list_node_type *;
    using const_pointer = const_list_node_type *;
    using reference = value_type &;
    using const_reference = value_type const &;

    using iterator = XorLinkedListIter<value_type>;
    using const_iterator = XorLinkedListIter<const value_type>;
    using reverse_iterator = XorLinkedListReverseIter<value_type>;
    using const_reverse_iterator = XorLinkedListReverseIter<const value_type>;

    XorLinkedList() :begin_(new list_node_type(0)), end_(begin_), sz_(0) {}

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

// void insert(iterator pos, value_type const& v);
//
// void erase(iterator pos);
//
// iterator find();
//
// const_iterator find() const;

    void reverse();

// void unique();
//
// void sort();

    inline size_type max_size();

    inline size_type size();

    inline bool empty();

    void clear();

// iterator begin();

// const_iterator cbegin() const;

// iterator end();

// const_iterator cend() const;

// reverse_iterator rbegin();

// const_reverse_iterator crbegin() const;

// reverse_iterator rend();

// const_reverse_iterator crend() const;

private:
    pointer begin_, end_;
    size_type sz_;

    inline pointer otherSide(pointer current, pointer side);

    inline void insertBetweenEndAndBegin(value_type const &v);

    void pushToEmpty(value_type const &v);
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
    if (empty())
        throw "the list is empty !";

    return begin_->value();
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::back() const->const_reference
{
    if (empty())
        throw "the list is empty !";

    return end_->value();
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::push_front(value_type const &v)
{
    if (empty())
        pushToEmpty(v);
    else
    {
        auto nextOfBegin = begin_->around(end_);
        auto prevOfEnd = end_->around(begin_);
        auto newBegin = new list_node_type(v);
        newBegin->around(end_, begin_);
        begin_->around(newBegin, nextOfBegin);
        end_->around(prevOfEnd, newBegin);
        begin_ = newBegin;
    }
    ++sz_;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::push_back(value_type const &v)
{
    if (empty())
        pushToEmpty(v);
    else
    {
        auto prevOfEnd = end_->around(begin_);
        auto doublePrevOfEnd = prevOfEnd->around(end_);
        auto newPrevOfEnd = new list_node_type(v);
        newPrevOfEnd->around(prevOfEnd, end_);
        end_->around(newPrevOfEnd, begin_);
        prevOfEnd->around(doublePrevOfEnd, newPrevOfEnd);
    }
    ++sz_;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::pop_front()
{
    if (empty())
        throw "the list is empty !";
    else
    {
        if (size() == 1)
        {
            delete begin_;
            begin_ = end_;
            end_->around(nullptr, nullptr);
        }
        else
        {
            auto nextOfBegin = begin_->around(end_);
            auto doubleNextOfBegin = nextOfBegin->around(begin_);
            auto prevOfEnd = end_->around(begin_);
            nextOfBegin->around(end_, doubleNextOfBegin);
            end_->around(prevOfEnd, nextOfBegin);
            delete begin_;
            begin_ = nextOfBegin;
        }
        --sz_;
    }
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::pop_back()
{
    reverse();
    pop_front();
    reverse();
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::reverse()
{
    // since list node stored nondirectional pointer, we can just replace sentinel nodes
    if (!empty())
        std::swap(begin_, end_);
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::clear()
{
    // release nodes without end_
    pointer prev = end_, next;
    while (begin_ != end_)
    {
        next = begin_->around(prev);
        prev = begin_;
        delete begin_;
        begin_ = next;
    }

    // reset
    end_->around(nullptr, nullptr);
    sz_ = 0;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::max_size()->size_type
{
    return static_cast<size_type>(-1) / sizeof(value_type);
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::size()->size_type
{
    return sz_;
}

template<typename _Type, typename _Compare>
inline bool
XorLinkedList<_Type, _Compare>::empty()
{
    return begin_ == end_;
}

template<typename _Type, typename _Compare>
inline auto
XorLinkedList<_Type, _Compare>::otherSide(pointer current, pointer side)->pointer
{
    return current->around(side);
}

template<typename _Type, typename _Compare>
inline void
XorLinkedList<_Type, _Compare>::insertBetweenEndAndBegin(value_type const &v)
{
    auto newNode = new list_node_type(v);
    auto nextOfBegin = begin_->around(end_);
    auto prevOfEnd = end_->around(begin_);
    newNode->around(end_, begin_);
    end_->around(prevOfEnd, newNode);
    begin_->around(newNode, nextOfBegin);
    end_ = newNode;
}

template<typename _Type, typename _Compare>
void
XorLinkedList<_Type, _Compare>::pushToEmpty(value_type const &v)
{
    begin_ = new list_node_type(v);
}

// template<typename _Type, typename _Compare>
// inline auto
// XorLinkedList<_Type, _Compare>::begin()->iterator
// {
//     return static_cast<iterator>(begin_);
// }

// template<typename _Type, typename _Compare>
// auto
// XorLinkedList<_Type, _Compare>::cbegin() const->const_iterator
// {
//     return static_cast<const_iterator>(begin_);
// }

// template<typename _Type, typename _Compare>
// inline auto
// XorLinkedList<_Type, _Compare>::end()->iterator
// {
//     return static_cast<iterator>(end_);
// }

// template<typename _Type, typename _Compare>
// auto
// XorLinkedList<_Type, _Compare>::cend() const->const_iterator
// {
//     return static_cast<const_iterator>(end_);
// }

// template<typename _Type, typename _Compare>
// inline auto
// XorLinkedList<_Type, _Compare>::rbegin()->reverse_iterator
// {
//     return static_cast<reverse_iterator>(end_);
// }

// template<typename _Type, typename _Compare>
// auto
// XorLinkedList<_Type, _Compare>::crbegin() const->const_reverse_iterator
// {
//     return static_cast<const_reverse_iterator>(end_);
// }

// template<typename _Type, typename _Compare>
// inline auto
// XorLinkedList<_Type, _Compare>::rend()->reverse_iterator
// {
//     return static_cast<reverse_iterator>(begin_);
// }

// template<typename _Type, typename _Compare>
// auto
// XorLinkedList<_Type, _Compare>::crend() const->const_reverse_iterator
// {
//     return static_cast<const_reverse_iterator>(begin_);
// }

#endif // XOR_LINKED_LIST_CPP
