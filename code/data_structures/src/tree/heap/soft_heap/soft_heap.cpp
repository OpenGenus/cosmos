/**
 * Soft Heap
 * Author: JonNRb
 *
 * Original paper: https://www.cs.princeton.edu/~chazelle/pubs/sheap.pdf
 * Binary heap version by Kaplan and Zwick
 */

#include <functional>
#include <iterator>
#include <limits>
#include <list>
#include <memory>
#include <stdexcept>

using namespace std;

#if __cplusplus <= 201103L
namespace {
template <typename T, typename ... Args>
unique_ptr<T> make_unique(Args&& ... args)
{
    return unique_ptr<T>(new T(forward<Args>(args) ...));
}
}  // namespace
#endif

// `T` is a comparable type and higher values of `corruption` increase the
// orderedness of the soft heap
template <typename T>
class SoftHeap {
private:
// `node`s make up elements in the soft queue, which is a binary heap with
// "corrupted" entries
    struct node
    {
        typename list<T>::iterator super_key;
        unsigned rank;

        // `target_size` is a target for the number of corrupted nodes. the number
        // increases going up the heap and should be between 1 and 2 times the
        // `target_size` of its children -- unless it is `corruption` steps from the
        // bottom, in which case it is 1.
        unsigned target_size;

        // `link[0]` is the left node and `link[1]` is the right node
        unique_ptr<node> link[2];

        // if `l` contains more than 1 entry, the node is "corrupted"
        list<T> l;
    };

    struct head
    {
        // the root of a "soft queue": a binary heap of nodes
        unique_ptr<node> q;

        // iterator to the tree following this one with the minimum `super_key` at
        // the root. may be the current `head`.
        typename list<head>::iterator suffix_min;
    };

// doubly-linked list of all binary heaps (soft queues) in the soft heap
    list<head> l;
    unsigned corruption;

public:
    SoftHeap(unsigned corruption) : corruption(corruption)
    {
    }

    bool empty()
    {
        return l.empty();
    }

    void push(T item)
    {
        auto item_node = make_unique<node>();
        item_node->rank = 0;
        item_node->target_size = 1;
        item_node->link[0] = nullptr;
        item_node->link[1] = nullptr;
        item_node->l.push_front(move(item));
        item_node->super_key = item_node->l.begin();

        l.emplace_front();
        auto h = l.begin();
        h->q = move(item_node);
        h->suffix_min = next(h) != l.end() ? next(h)->suffix_min : h;

        repeated_combine(1);
    }

    T pop()
    {
        if (l.empty())
            throw invalid_argument("empty soft heap");

        auto it = l.begin()->suffix_min;
        node* n = it->q.get();

        T ret = move(*n->l.begin());
        n->l.pop_front();

        if (n->l.size() < n->target_size)
        {
            if (n->link[0] || n->link[1])
            {
                sift(n);
                update_suffix_min(it);
            }
            else if (n->l.empty())
            {
                if (it == l.begin())
                    l.erase(it);
                else
                {
                    auto p = prev(it);
                    l.erase(it);
                    update_suffix_min(p);
                }
            }
        }

        return ret;
    }

private:
    void update_suffix_min(typename list<head>::iterator it) const
    {
        if (it == l.end())
            return;
        while (true)
        {
            if (next(it) == l.end())
                it->suffix_min = it;
            else if (*it->q->super_key <= *next(it)->suffix_min->q->super_key)
                it->suffix_min = it;
            else
                it->suffix_min = next(it)->suffix_min;
            if (it == l.begin())
                return;
            --it;
        }
    }

    unique_ptr<node> combine(unique_ptr<node> a, unique_ptr<node> b) const
    {
        auto n = make_unique<node>();
        n->rank = a->rank + 1;
        n->target_size = n->rank <= corruption ? 1 : (3 * a->target_size + 1) / 2;
        n->link[0] = move(a);
        n->link[1] = move(b);
        sift(n.get());
        return n;
    }

    void repeated_combine(unsigned max_rank)
    {
        auto it = l.begin();
        for (auto next_it = next(l.begin()); next_it != l.end();
             it = next_it, ++next_it)
        {
            if (it->q->rank == next_it->q->rank)
            {
                if (next(next_it) == l.end() || next(next_it)->q->rank != it->q->rank)
                {
                    it->q = combine(move(it->q), move(next_it->q));
                    next_it = l.erase(next_it);
                    if (next_it == l.end())
                        break;
                }
            }
            else if (it->q->rank > max_rank)
                break;
        }

        update_suffix_min(it);
    }

    static void sift(node* n)
    {
        while (n->l.size() < n->target_size)
        {
            if (n->link[1])
            {
                if (!n->link[0] || *n->link[0]->super_key > *n->link[1]->super_key)
                    swap(n->link[0], n->link[1]);
            }
            else if (!n->link[0])
                return;

            n->super_key = n->link[0]->super_key;
            n->l.splice(n->l.end(), n->link[0]->l);

            if (!n->link[0]->link[0] && !n->link[0]->link[1])
                n->link[0] = nullptr;
            else
                sift(n->link[0].get());
        }
    }
};

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

int run_test_with_corruption(unsigned corruption, unsigned k_num_elems)
{
    using namespace std::chrono;

    cout << "making soft heap with corruption " << corruption << " and "
         << k_num_elems << " elements..." << endl;
    SoftHeap<unsigned> sh(corruption);

    // create a random ordering of the numbers [0, k_num_elems)
    vector<bool> popped_nums(k_num_elems);
    vector<unsigned> nums(k_num_elems);
    random_device rd;
    mt19937 gen(rd());

    for (unsigned i = 0; i < k_num_elems; ++i)
        nums[i] = i;
    for (unsigned i = 0; i < k_num_elems; ++i)
    {
        uniform_int_distribution<unsigned> dis(i, k_num_elems - 1);
        swap(nums[i], nums[dis(gen)]);
    }

    auto start = steady_clock::now();

    for (unsigned i = 0; i < k_num_elems; ++i)
        sh.push(nums[i]);

    // this notion of `num_errs` is not rigorous in any way
    unsigned num_errs = 0;
    unsigned last = 0;
    while (!sh.empty())
    {
        unsigned i = sh.pop();
        if (popped_nums[i])
        {
            cerr << "  popped number " << i << " already" << endl;
            return -1;
        }
        popped_nums[i] = true;
        if (i < last)
            ++num_errs;
        last = i;
        // cout << i << endl;
    }

    auto end = steady_clock::now();

    cout << "  error rate: " << ((double)num_errs / k_num_elems) << endl;
    cout << "  took " << duration_cast<milliseconds>(end - start).count() << " ms"
         << endl;

    return 0;
}

int main()
{
    for (unsigned i = 0; i < 20; ++i)
        if (run_test_with_corruption(i, 1 << 18))
            return -1;
    return 0;
}
