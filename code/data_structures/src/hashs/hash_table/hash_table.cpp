/*
 *  Part of Cosmos by OpenGenus Foundation
 *
 *  hash_table synopsis
 *
 * template<typename _Tp, typename _HashFunc = std::hash<_Tp> >
 * class hash_table {
 * public:
 *  typedef _Tp                                         value_type;
 *  typedef decltype (_HashFunc ().operator()(_Tp()))   key_type;
 *  typedef std::map<key_type, value_type>              container_type;
 *  typedef typename container_type::const_iterator     const_iterator;
 *  typedef typename container_type::size_type          size_type;
 *
 *  // Initialize your data structure here.
 *  hash_table() :_container({}) {}
 *
 *  // Inserts a value to the set. Returns true if the set did not already contain the specified
 *   element.
 *  std::pair<const_iterator, bool> insert(const _Tp val);
 *
 *  template<typename _InputIter>
 *  void insert(_InputIter first, _InputIter last);
 *
 *  void insert(std::initializer_list<_Tp> init_list);
 *
 *  // Removes a value from the set. Returns true if the set contained the specified element.
 *  const_iterator erase(const _Tp val);
 *
 *  const_iterator erase(const_iterator pos);
 *
 *  // Find a value from the set. Returns true if the set contained the specified element.
 *
 *  const_iterator find(const _Tp val) const;
 *
 *  const_iterator end() const;
 *
 *  bool empty() const;
 *
 *  size_type size() const;
 *
 * private:
 *  container_type _container;
 *
 *  key_type hash(const value_type &val) const;
 *
 *  template<typename _InputIter>
 *  void _insert(_InputIter first, _InputIter last, std::input_iterator_tag);
 * };
 */

#include <map>
template<typename _Tp, typename _HashFunc = std::hash<_Tp>>
class hash_table {
public:
    typedef _Tp value_type;
    typedef decltype (_HashFunc ().operator()(_Tp()))   key_type;
    typedef std::map<key_type, value_type>              container_type;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::size_type size_type;

/** Initialize your data structure here. */
    hash_table() : _container({})
    {
    }

/** Inserts a value to the set. Returns true if the set did not already contain the specified
 * element. */
    std::pair<const_iterator, bool> insert(const _Tp val)
    {
        key_type key = hash(val);
        if (_container.find(key) == _container.end())
        {
            _container.insert(std::make_pair(key, val));

            return make_pair(_container.find(key), true);
        }

        return make_pair(_container.end(), false);
    }

    template<typename _InputIter>
    void insert(_InputIter first, _InputIter last)
    {
        _insert(first, last, typename std::iterator_traits<_InputIter>::iterator_category());
    }

    void insert(std::initializer_list<_Tp> init_list)
    {
        insert(init_list.begin(), init_list.end());
    }

/** Removes a value from the set. Returns true if the set contained the specified element. */
    const_iterator erase(const _Tp val)
    {
        const_iterator it = find(val);
        if (it != end())
            return erase(it);

        return end();
    }

    const_iterator erase(const_iterator pos)
    {
        return _container.erase(pos);
    }

/** Find a value from the set. Returns true if the set contained the specified element. */
    const_iterator find(const _Tp val)
    {
        key_type key = hash(val);

        return _container.find(key);
    }

    const_iterator find(const _Tp val) const
    {
        key_type key = hash(val);

        return _container.find(key);
    }

    const_iterator end() const
    {
        return _container.end();
    }

    bool empty() const
    {
        return _container.empty();
    }

    size_type size() const
    {
        return _container.size();
    }

private:
    container_type _container;

    key_type hash(const value_type &val) const
    {
        return _HashFunc()(val);
    }

    template<typename _InputIter>
    void _insert(_InputIter first, _InputIter last, std::input_iterator_tag)
    {
        _InputIter pos = first;
        while (pos != last)
            insert(*pos++);
    }
};

/*
 * // for test
 *
 * // a user-defined hash function
 * template<typename _Tp>
 * struct MyHash {
 *  // hash by C++ boost
 *  // phi = (1 + sqrt(5)) / 2
 *  // 2^32 / phi = 0x9e3779b9
 *  void hash(std::size_t &seed, const _Tp &i) const
 *  {
 *      seed ^= std::hash<_Tp>()(i) + 0x87654321 * (seed << 1) + (seed >> 2);
 *      seed <<= seed % 6789;
 *  }
 *
 *  std::size_t operator()(const _Tp &d) const
 *  {
 *      std::size_t seed = 1234;
 *      hash(seed, d);
 *
 *      return seed;
 *  }
 * };
 *
 #include <iostream>
 #include <vector>
 * using namespace std;
 *
 * int main() {
 *  hash_table<int, MyHash<int> > ht;
 *
 *  // test find
 *  if (ht.find(9) != ht.end())
 *      cout << __LINE__ << " error\n";
 *
 *  // test insert(1)
 *  if (!ht.insert(3).second)  // return true
 *      cout << __LINE__ << " error\n";
 *
 *  if (ht.insert(3).second)  // return false
 *      cout << __LINE__ << " error\n";
 *
 *  // test insert(2)
 *  vector<int> input{10, 11, 12};
 *  ht.insert(input.begin(), input.end());
 *  if (ht.find(10) == ht.end())
 *      cout << __LINE__ << " error\n";
 *  if (ht.find(11) == ht.end())
 *      cout << __LINE__ << " error\n";
 *  if (ht.find(12) == ht.end())
 *      cout << __LINE__ << " error\n";
 *
 *  // test insert(3)
 *  ht.insert({13, 14, 15, 16});
 *
 *  // test erase(1)
 *  ht.erase(13);
 *
 *  // test erase(2)
 *  auto it = ht.find(14);
 *  ht.erase(it);
 *
 *  // test empty
 *  if (ht.empty())
 *      cout << __LINE__ << " error\n";
 *
 *  // test size
 *  if (ht.size() != 6)
 *      cout << __LINE__ << " error\n";
 *
 *  return 0;
 * }
 *
 * // */
