#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef struct node node;

class BinaryTrie
{
public:
    struct node
    {
        node *ar[2];
        ll elts;
        ll duplicates;
        ll index;
    };
    node *root;

    BinaryTrie()
    {
        root = init();
    }

    node *init()
    {
        node *ob = new node;
        ob->ar[0] = NULL;
        ob->ar[1] = NULL;
        ob->elts = 0;
        ob->duplicates = 0;
        ob->index = 0;
        return ob;
    }

    bool insert(node *n, ll base, ll val)
    {
        if (base == -1)
        {
            n->elts++;
            if (n->elts > 1)
            {
                n->duplicates++;
                return true;
            }
            return false;
        }
        ll bit = (val >> base) & 1;
        n->index = base;
        n->elts++;
        if (n->ar[bit] == NULL)
        {
            n->ar[bit] = init();
        }

        if (insert(n->ar[bit], base - 1, val))
        {
            n->duplicates++;
            return true;
        }
        return false;
    }

    bool empty(node *n)
    {
        if ((n->ar[0] == NULL || n->ar[0]->elts == 0) && (n->ar[1] == NULL || n->ar[1]->elts == 0))
        {
            return true;
        }
        return false;
    }

    bool del(node *n, ll base, ll val)
    {
        n->elts--;
        if (base == -1)
        {
            if (n->duplicates)
            {
                n->duplicates--;
                return true;
            }
            return false;
        }
        ll bit = (val >> base) & 1;
        if (del(n->ar[bit], base - 1, val))
        {
            n->duplicates--;
            return true;
        }
        return false;
    }

    void del_dup(node *n, ll base, ll val)
    {
        if (base == -1 || n == NULL)
        {
            return;
        }
        else
        {
            ll bit = (val >> base) & 1;
            if (n->ar[bit]->elts == 0)
            {
                delete n->ar[bit];
                n->ar[bit] = NULL;
            }
            else
            {
                del_dup(n->ar[bit], base - 1, val);
            }
        }
    }

    ll search(node *n, ll base, ll val)
    {
        if (base == -1 || n == NULL)
        {
            return 0;
        }
        ll bit = (val >> base) & 1;
        ll ans = 0;
        if (n->ar[bit] != NULL && (n->ar[bit]->elts - n->ar[bit]->duplicates) == (1 << base))
        {
            bit = !bit;
            ans = (1 << base);
        }
        ans = ans | search(n->ar[bit], base - 1, val);
        return ans;
    }
};

int main()
{
    BinaryTrie ob;
    cout << "Enter number of queries to enter" << endl;
    ll q;
    cin >> q;
    while (q--)
    {
        cout << "Enter 1-Insert 2-Delete 3-search smallest number >= input that is absent in the trie" << endl;
        ll c;
        cin >> c;
        if (c == 1)
        {
            ll x;
            cin >> x;
            ob.insert(ob.root, 30, x);
        }
        else if (c == 2)
        {
            ll x;
            cin >> x;
            ob.del(ob.root, 30, x);
            ob.del_dup(ob.root, 30, x);
        }
        else if (c == 3)
        {
            ll x;
            cin >> x;
            cout << ob.search(ob.root, 30, x) << endl;
        }
    }
}
