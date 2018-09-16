/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * xor linked list synopsis
 *
 *** incomplete ***
 ***
 ***Begin *** Iterator invalidation rules are NOT applicable. ***
 ***[x] Insertion: all iterators and references unaffected.
 ***[x] Erasure: only the iterators and references to the erased element is invalidated.
 ***[o] Resizing: as per insert/erase.
 ***
 ***Refer to: https://stackoverflow.com/questions/6438086/iterator-invalidation-rules
 ***End *** Iterator invalidation rules are NOT applicable. ***
 */

#ifndef XOR_LINKED_LIST_CPP
#define XOR_LINKED_LIST_CPP

#include <iterator>
#include <algorithm>
#include <exception>
#include <cstddef>

template<typename _Type>
class XorLinkedList;

template<class _Type>
class ListIter;

template<class _Type>
class ListConstIter;

template<typename _Type>
class __Node
{
private:
    using value_type = _Type;
    using SPNode = __Node<value_type> *;

public:
    explicit __Node(value_type value) : value_(value), around_(nullptr)
    {
    }

    inline value_type &value()
    {
        return value_;
    }

    inline const value_type &value() const
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

    inline SPNode around(const SPNode &around)
    {
        return reinterpret_cast<SPNode>(reinterpret_cast<uintptr_t>(around) ^
                                        reinterpret_cast<uintptr_t>(around_));
    }

    inline void around(const SPNode &prev, const SPNode &next)
    {
        around_ = reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(prev) ^
                                           reinterpret_cast<uintptr_t>(next));
    }

    friend XorLinkedList<value_type>;
    friend ListIter<value_type>;
    friend ListConstIter<value_type>;
};

template<class _Type>
class ListIter : public std::iterator<std::bidirectional_iterator_tag, _Type>
{
public:
    using value_type = _Type;
    using difference_type = std::ptrdiff_t;
    using pointer = _Type *;
    using reference = _Type &;
    using iterator_category = std::bidirectional_iterator_tag;

private:
    using NodePtr = __Node<value_type> *;
    using Self = ListIter<value_type>;

public:
    ListIter()
    {
    }

    explicit ListIter(NodePtr prev, NodePtr curr) : prev_(prev), curr_(curr)
    {
    }

    ListIter(const Self &it) : prev_(it.prev_), curr_(it.curr_)
    {
    }

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

    Self operator++(int)
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

    Self operator--(int)
    {
        auto temp = *this;
        --*this;

        return temp;
    }

    bool operator==(const Self &other) const
    {
        return curr_ == other.curr_;
    }

    bool operator!=(const Self &other) const
    {
        return !(*this == other);
    }

private:
    NodePtr prev_, curr_;

    friend XorLinkedList<value_type>;
    friend ListConstIter<value_type>;
};

template<class _Type>
class ListConstIter : public std::iterator<std::bidirectional_iterator_tag, _Type>
{
public:
    using value_type = _Type;
    using difference_type = std::ptrdiff_t;
    using pointer = const _Type *;
    using reference = const _Type &;
    using iterator_category = std::bidirectional_iterator_tag;

private:
    using NodePtr = __Node<value_type> *;
    using Self = ListConstIter<value_type>;
    using Iter = ListIter<value_type>;

public:
    ListConstIter()
    {
    }

    explicit ListConstIter(NodePtr prev, NodePtr curr) : prev_(prev), curr_(curr)
    {
    }

    ListConstIter(const Iter &it) : prev_(it.prev_), curr_(it.curr_)
    {
    }

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

    Self operator++(int)
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

    Self operator--(int)
    {
        auto temp = *this;
        --*this;

        return temp;
    }

    bool operator==(const Self &other) const
    {
        return curr_ == other.curr_;
    }

    bool operator!=(const Self &other) const
    {
        return !(*this == other);
    }

private:
    NodePtr prev_, curr_;

    Iter constCast()
    {
        return Iter(prev_, curr_);
    }

    friend XorLinkedList<value_type>;
};

template<typename _Type>
class XorLinkedList
{
private:
    using Node = __Node<_Type>;
    using NodePtr = __Node<_Type> *;
    using Self = XorLinkedList<_Type>;

public:
    using value_type = _Type;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = const value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;

    using iterator = ListIter<value_type>;
    using const_iterator = ListConstIter<value_type>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    explicit XorLinkedList() : sz_(0)
    {
        construct();
    }

    XorLinkedList(const Self &list) : sz_(0)
    {
        construct();
        std::for_each(list.begin(), list.end(), [&](value_type v)
        {
            push_back(v);
        });
    };

    XorLinkedList(std::initializer_list<value_type> &&vs) : sz_(0)
    {
        construct();
        std::for_each(vs.begin(), vs.end(), [&](value_type v)
        {
            push_back(v);
        });
    }

    ~XorLinkedList()
    {
        clear();
        destruct();
    }

// element access
    inline reference back();

    inline const_reference back() const;

    inline reference front();

    inline const_reference front() const;

// modifiers
    void clear();

    template<class ... Args>
    reference emplace_back(Args&& ... args);

    template<class ... Args>
    reference emplace_front(Args&& ... args);

    iterator erase(const_iterator pos);

    iterator erase(const_iterator begin, const_iterator end);

    iterator insert(const_iterator pos, const value_type &v);

    iterator insert(const_iterator pos, size_type size, const value_type &v);

    iterator insert(const_iterator pos, value_type &&v);

    iterator insert(const_iterator pos, std::initializer_list<value_type> il);

    template<typename _InputIt>
    iterator insert(const_iterator pos, _InputIt first, _InputIt last);

    void pop_back();

    void pop_front();

    void push_back(const value_type &v);

    void push_front(const value_type &v);

    void resize(size_type count);

    void resize(size_type count, const value_type&value);

    void swap(Self&other);

// capacity
    inline bool empty() const;

    inline size_type max_size() const;

    inline size_type size() const;

// iterators
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

// operations
    void merge(Self&other);

    void merge(Self&&other);

    template<class Compare>
    void merge(Self&other, Compare comp);

    template<class Compare>
    void merge(Self&&other, Compare comp);

    void reverse();

    void sort();

    template<class Compare>
    void sort(Compare comp);

    void splice(const_iterator pos, Self&other);

    void splice(const_iterator pos, Self&&other);

    void splice(const_iterator pos, Self&other, const_iterator it);

    void splice(const_iterator pos, Self&&other, const_iterator it);

    void splice(const_iterator pos, Self&other, const_iterator first, const_iterator last);

    void splice(const_iterator pos, Self&&other, const_iterator first, const_iterator last);

    void unique();

    template<class BinaryPredicate>
    void unique(BinaryPredicate p);

private:
    NodePtr prevOfBegin_, end_, nextOfEnd_;
    size_type sz_;

    inline void construct();

    inline void destruct();

    inline iterator insertImpl(const_iterator pos, const value_type &v);

    inline iterator eraseImpl(const_iterator pos);
};

// element access
template<typename _Type>
inline auto
XorLinkedList<_Type>::back()->reference
{
    if (empty())
        throw std::out_of_range("access to empty list !");

    return end_->around(nextOfEnd_)->value();
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::back() const->const_reference
{
    return const_cast<Self *>(this)->back();
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::front()->reference
{
    if (empty())
        throw std::out_of_range("access to empty list !");

    return prevOfBegin_->around(nextOfEnd_)->value();
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::front() const->const_reference
{
    return const_cast<Self *>(this)->front();
}

// modifiers
template<typename _Type>
inline void
XorLinkedList<_Type>::clear()
{
    NodePtr begin = prevOfBegin_, nextOfBegin;
    begin = begin->around(nextOfEnd_);

    while (begin != end_)
    {
        nextOfBegin = begin->around(prevOfBegin_);

        prevOfBegin_->around(nextOfEnd_, nextOfBegin);
        nextOfBegin->around(prevOfBegin_, nextOfBegin->around(begin));

        delete begin;
        begin = nextOfBegin;
    }

    sz_ = 0;
}

template<typename _Type>
template<class ... Args>
auto
XorLinkedList<_Type>::emplace_back(Args&& ... args)->reference
{
}

template<typename _Type>
template<class ... Args>
auto
XorLinkedList<_Type>::emplace_front(Args&& ... args)->reference
{
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::erase(const_iterator pos)->iterator
{
    return eraseImpl(pos);
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::erase(const_iterator first, const_iterator last)->iterator
{
    auto diff = std::distance(first, last);
    if (diff == 0)
        return first.constCast(); // check what is std return

    auto firstAfterEraseIter = first;
    while (diff--)
        firstAfterEraseIter = eraseImpl(firstAfterEraseIter);

    return firstAfterEraseIter.constCast();
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::insert(const_iterator pos, const value_type &v)->iterator
{
    return insertImpl(pos, v);
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::insert(const_iterator pos, size_type size, const value_type &v)
->iterator
{
    if (size == 0)
        return pos.constCast();

    auto curr = insert(pos, v);
    auto firstOfInsert = curr;
    ++curr;
    while (--size)
        curr = ++insert(curr, v);

    return firstOfInsert;
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::insert(const_iterator pos, value_type &&v)->iterator
{
    return insertImpl(pos, v);
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::insert(const_iterator pos, std::initializer_list<value_type> il)
->iterator
{
    if (il.begin() == il.end())
        return pos.constCast();

    auto curr = insert(pos, *il.begin());
    auto firstOfInsert = curr;
    ++curr;
    auto begin = il.begin();
    ++begin;
    std::for_each(begin, il.end(), [&](value_type v)
    {
        curr = ++insert(curr, v);
    });

    return firstOfInsert;
}

template<typename _Type>
template<typename _InputIt>
inline auto
XorLinkedList<_Type>::insert(const_iterator pos, _InputIt first, _InputIt last)
->iterator
{
    if (first < last)
    {
        auto curr = insert(pos, *first);
        auto firstOfInsert = curr;
        ++curr;
        auto begin = first;
        ++begin;
        std::for_each(begin, last, [&](value_type it)
        {
            curr = ++insert(curr, it);
        });

        return firstOfInsert;
    }
    return pos.constCast();
}

template<typename _Type>
void
XorLinkedList<_Type>::pop_back()
{
    // Calling pop_back on an empty container is undefined.
    erase(--end());
}

template<typename _Type>
void
XorLinkedList<_Type>::pop_front()
{
    // Calling pop_front on an empty container is undefined.
    erase(begin());
}

template<typename _Type>
void
XorLinkedList<_Type>::push_back(const value_type &v)
{
    insert(end(), v);
}

template<typename _Type>
void
XorLinkedList<_Type>::push_front(const value_type &v)
{
    insert(begin(), v);
}

template<typename _Type>
void
XorLinkedList<_Type>::resize(size_type count)
{
}

template<typename _Type>
void
XorLinkedList<_Type>::resize(size_type count, const value_type&value)
{
}

template<typename _Type>
void
XorLinkedList<_Type>::swap(Self&other)
{
}

// capacity
template<typename _Type>
inline bool
XorLinkedList<_Type>::empty() const
{
    return prevOfBegin_->around(nextOfEnd_) == end_;
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::max_size() const->size_type
{
    return static_cast<size_type>(-1) / sizeof(value_type);
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::size() const->size_type
{
    return sz_;
}

// iterators
template<typename _Type>
inline auto
XorLinkedList<_Type>::begin()->iterator
{
    return iterator(prevOfBegin_, prevOfBegin_->around(nextOfEnd_));
}

template<typename _Type>
auto
XorLinkedList<_Type>::begin() const->const_iterator
{
    return const_iterator(prevOfBegin_, prevOfBegin_->around(nextOfEnd_));
}

template<typename _Type>
auto
XorLinkedList<_Type>::cbegin() const->const_iterator
{
    return const_iterator(prevOfBegin_, prevOfBegin_->around(nextOfEnd_));
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::end()->iterator
{
    return iterator(end_->around(nextOfEnd_), end_);
}

template<typename _Type>
auto
XorLinkedList<_Type>::end() const->const_iterator
{
    return const_iterator(end_->around(nextOfEnd_), end_);
}

template<typename _Type>
auto
XorLinkedList<_Type>::cend() const->const_iterator
{
    return const_iterator(end_->around(nextOfEnd_), end_);
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::rbegin()->reverse_iterator
{
    return reverse_iterator(end());
}

template<typename _Type>
auto
XorLinkedList<_Type>::rbegin() const->const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template<typename _Type>
auto
XorLinkedList<_Type>::crbegin() const->const_reverse_iterator
{
    return const_reverse_iterator(cend());
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::rend()->reverse_iterator
{
    return reverse_iterator(begin());
}

template<typename _Type>
auto
XorLinkedList<_Type>::rend() const->const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

template<typename _Type>
auto
XorLinkedList<_Type>::crend() const->const_reverse_iterator
{
    return const_reverse_iterator(cbegin());
}

// operations
template<typename _Type>
inline void
XorLinkedList<_Type>::merge(Self&other)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::merge(Self&&other)
{
}

template<typename _Type>
template<class Compare>
inline void
XorLinkedList<_Type>::merge(Self&other, Compare comp)
{
}

template<typename _Type>
template<class Compare>
inline void
XorLinkedList<_Type>::merge(Self&&other, Compare comp)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::reverse()
{
    std::swap(prevOfBegin_, end_);
}

template<typename _Type>
inline void
XorLinkedList<_Type>::sort()
{
}

template<typename _Type>
template<class Compare>
inline void
XorLinkedList<_Type>::sort(Compare comp)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos, Self&other)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos, Self&&other)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos, Self&other, const_iterator it)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos, Self&&other, const_iterator it)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos,
                             Self&other,
                             const_iterator first,
                             const_iterator
                             last)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::splice(const_iterator pos,
                             Self&&other,
                             const_iterator first,
                             const_iterator
                             last)
{
}

template<typename _Type>
inline void
XorLinkedList<_Type>::unique()
{
}

template<typename _Type>
template<class BinaryPredicate>
inline void
XorLinkedList<_Type>::unique(BinaryPredicate p)
{
}

// private functions
template<typename _Type>
inline void
XorLinkedList<_Type>::construct()
{
    end_ = new Node(0);
    prevOfBegin_ = new Node(0);
    nextOfEnd_ = new Node(0);

    end_->around(prevOfBegin_, nextOfEnd_);
    prevOfBegin_->around(nextOfEnd_, end_);
    nextOfEnd_->around(end_, prevOfBegin_);
}

template<typename _Type>
inline void
XorLinkedList<_Type>::destruct()
{
    delete prevOfBegin_;
    delete end_;
    delete nextOfEnd_;
}

template<typename _Type>
inline auto
XorLinkedList<_Type>::insertImpl(const_iterator pos, const value_type &v)
->iterator
{
    auto curr = pos.curr_;
    auto prev = pos.prev_;

    auto nextOfNext = curr->around(prev);
    auto prevOfPrev = prev->around(curr);
    auto newCurr = new Node(v);
    newCurr->around(prev, curr);
    curr->around(newCurr, nextOfNext);
    prev->around(prevOfPrev, newCurr);
    ++sz_;

    return iterator(prev, prev->around(prevOfPrev));
}

template<typename _Type>
auto
XorLinkedList<_Type>::eraseImpl(const_iterator pos)->iterator
{
    auto curr = pos.curr_;
    auto prev = pos.prev_;

    auto nextOfCurr = curr->around(prev);
    auto nextOfNext = nextOfCurr->around(curr);
    auto prevOfPrev = prev->around(curr);
    nextOfCurr->around(prev, nextOfNext);
    prev->around(prevOfPrev, nextOfCurr);
    delete curr;
    --sz_;

    return iterator(prev, nextOfCurr);
}

#endif // XOR_LINKED_LIST_CPP
