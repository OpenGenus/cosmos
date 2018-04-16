#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
const int lb = -1e9, rb = 1e9;
struct node
{
    int val;
    node *l, *r;
    node()
    {
        val = 0;
        l = r = nullptr;
    }
    node(int x)
    {
        val = x;
        l = r = nullptr;
    }
    node(node* vl, node* vr)
    {
        l = vl;
        r = vr;
        if (l)
            val += l->val;
        if (r)
            val += r->val;
    }
};
vector<node*> tr;
int cnt(node* v)
{
    return v ? v->val : 0;
}
node* add_impl(node* v, int tl, int tr, int x)
{
    if (tl == tr)
        return new node(cnt(v) + 1);
    else
    {
        int tm = (tl + tr) / 2;
        if (x <= tm)
            return new node(add_impl(v ? v->l : v, tl, tm, x), v ? v->r : v);
        else
            return new node(v ? v->l : v,
                            add_impl(v ? v->r : v, tm + 1, tr, x));
    }
}
void add(int x)
{
    node* v = tr.back();
    tr.push_back(add_impl(v, lb, rb, x));
}
int order_of_key_impl(node* v, int tl, int tr, int l, int r)
{
    if (!v)
        return 0;
    if (l == tl && r == tr)
        return v->val;
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return order_of_key_impl(v->l, tl, tm, l, r);
    else
        return order_of_key_impl(v->l, tl, tm, l, tm) +
               order_of_key_impl(v->r, tm + 1, tr, tm + 1, r);
}
int order_of_key(int l, int r, int x)
{
    int ans = order_of_key_impl(tr[r], lb, rb, lb, x - 1) -
              order_of_key_impl(tr[l - 1], lb, rb, lb, x - 1) + 1;
    return ans;
}
int find_by_order_impl(node* l, node* r, int tl, int tr, int x)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (cnt(r ? r->l : r) - cnt(l ? l->l : l) >= x)
        return find_by_order_impl(l ? l->l : l, r ? r->l : r, tl, tm, x);
    else
        return find_by_order_impl(l ? l->r : l, r ? r->r : r, tm + 1, tr,
                                  x - (cnt(r ? r->l : r) - cnt(l ? l->l : l)));
}
int find_by_order(int l, int r, int x)
{
    assert(r - l + 1 >= x && x > 0);
    return find_by_order_impl(tr[l - 1], tr[r], lb, rb, x);
}
int main()
{
    tr.push_back(nullptr);
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        add(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t;          // type of question: 1 - order of key, 2 - find by order
        cin >> t;
        int l, r, x;          // 1 <= l <= r <= n
        cin >> l >> r >> x;
        if (t == 1)
            cout << order_of_key(l, r, x) << endl;
        else
            cout << find_by_order(l, r, x) << endl;
    }
}
