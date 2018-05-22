/**
 * skip list C++ implementation
 *
 *          Average     Worst-case
 * Space    O(n)        O(n log n)
 * Search   O(log n)    0(n)
 * Insert   O(log n)    0(n)
 * Delete   O(log n)    0(n)
 * Part of Cosmos by OpenGenus Foundation
 */

#include <algorithm>    // std::less, std::max
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl, std::ostream
#include <map>          // std::map
#include <stdlib.h>     // rand, srand
#include <time.h>       // time

template <typename val_t> class skip_list;
template <typename val_t>
std::ostream & operator<<(std::ostream &os, const skip_list<val_t> &jls);

template <typename val_t>
class skip_list
{
private:
/**
 * skip_node
 */
    struct skip_node
    {
        val_t data;
        skip_node   **forward;
        int height;

        skip_node(int ht)
            : forward{new skip_node*[ht]}, height{ht}
        {
            for (int i = 0; i < ht; ++i)
                forward[i] = nullptr;
        }

        skip_node(const val_t &ele, int ht)
            : skip_node(ht)
        {
            data = ele;
        }

        ~skip_node()
        {
            if (forward[0])
                delete forward[0];
            delete[] forward;
        }

    };

/* member variables */
    skip_node                       *head_;
    int size_,
        cur_height_;
    constexpr const static int MAX_HEIGHT = 10;
    constexpr const static float PROB = 0.5f;
/* private functions */

    bool coin_flip()
    {
        return ((float) rand() / RAND_MAX) < PROB;
    }

    int rand_height()
    {
        int height = 1;
        for (; height < MAX_HEIGHT && coin_flip(); ++height)
        {
        }
        return height;
    }

    skip_node ** find(const val_t &ele)
    {
        auto comp = std::less<val_t>();
        skip_node **result = new skip_node*[cur_height_],
                  *cur_node = head_;
        for (int lvl = cur_height_ - 1; lvl >= 0; --lvl)
        {
            while (cur_node->forward[lvl]
                   && comp(cur_node->forward[lvl]->data, ele))
                cur_node = cur_node->forward[lvl];
            result[lvl] = cur_node;
        }
        return result;
    }

    void print(std::ostream &os) const
    {
        int i;
        for (skip_node *n = head_; n != nullptr; n = n->forward[0])
        {
            os << n->data << ": ";
            for (i = 0; i < cur_height_; ++i)
            {
                if (i < n->height)
                    os << "[ ] ";
                else
                    os << " |  ";
            }
            os << std::endl;
            os << "   ";
            for (i = 0; i < cur_height_; ++i)
                os << " |  ";
            os << std::endl;
        }
    }

public:
/* Default C'tor */
    skip_list()
        : head_{new skip_node(MAX_HEIGHT)}, size_{0}, cur_height_{0}
    {
        srand((unsigned)time(0));
    }

/* D'tor */
    ~skip_list()
    {
        delete head_;
    }

/**
 * size
 * @return - the number of elements in the list
 */
    int size()
    {
        return size_;
    }

/**
 * insert
 * @param ele - the element to be inserted into the list
 */
    void insert(const val_t &ele)
    {
        int new_ht = rand_height();
        skip_node *new_node = new skip_node(ele, new_ht);
        cur_height_ = std::max(new_ht, cur_height_);
        skip_node **pre = find(ele);
        for (int i = 0; i < new_ht; ++i)
        {
            new_node->forward[i] = pre[i]->forward[i];
            pre[i]->forward[i] = new_node;
        }
        ++size_;
        delete[] pre;
    }

/**
 * contains
 * @param ele - the element to search for
 * @retrun - true if the element is in the list, false otherwise
 */
    bool contains(const val_t &ele)
    {
        skip_node **pre = find(ele);
        bool result = pre[0] &&
                      pre[0]->forward[0] &&
                      pre[0]->forward[0]->data == ele;
        delete[] pre;
        return result;
    }

/**
 * remove
 * @param ele - the element to delete if found
 */
    void remove(const val_t &ele)
    {
        if (!contains(ele))
        {
            std::cout << ele << " not found!" << std::endl;
            return;
        }
        skip_node *tmp, **pre = find(ele), *del = pre[0]->forward[0];
        for (int i = 0; i < cur_height_; ++i)
        {
            tmp = pre[i]->forward[i];
            if (tmp != nullptr && tmp->data == ele)
            {
                pre[i]->forward[i] = tmp->forward[i];
                tmp->forward[i] = nullptr;
            }
        }
        --size_;
        delete del;
        delete[] pre;
    }

    friend std::ostream & operator<< <val_t>(std::ostream &os,
                                             const skip_list<val_t> &ls);
}; // skip_node

template<typename val_t>
std::ostream & operator<<(std::ostream &os, const skip_list<val_t> &ls)
{
    ls.print(os);
    return os;
}

int main()
{
    auto ints = { 1, 4, 2, 7, 9, 3, 5, 8, 6 };
    skip_list<int> isl;
    for (auto i : ints)
    {
        isl.insert(i);
        std::cout << isl << std::endl;
    }
    for (auto i : ints)
    {
        assert(isl.contains(i));
        std::cout << "removing " << i << std::endl;
        isl.remove(i);
        std::cout << isl << std::endl;
    }
    return 0;
}
