#include <vector>
#include <fstream>
#include <queue>
using namespace std;

const int MAXN = 1000005;

char word[MAXN];
int n;
struct trie_node
{
    int nr;
    trie_node *children[26];
    trie_node *fail;
    vector<trie_node* >out;

    trie_node()
    {
        nr = 0;
        for (int i = 0; i < 26; i++)
            children[i] = 0;
        fail = 0;
        out.clear();
    }

}*root = new trie_node;

trie_node *fr[MAXN];

queue<trie_node* >coada;

trie_node* trie_insert(trie_node *&node, char *p)
{
    if (!*p)
        return node;

    if (!node->children[*p - 'a'])
        node->children[*p - 'a'] = new trie_node;

    return trie_insert(node->children[*p - 'a'], p + 1);
}

void traversal(trie_node *t)
{
    for (size_t i = 0; i < t->out.size(); i++)
    {
        traversal(t->out[i]);
        t->nr += t->out[i]->nr;
    }
}

int main()
{
    ifstream in("ahocorasick.in");
    ofstream out("ahocorasick.out");

    in >> word >> n;

    for (int i = 1; i <= n; i++)
    {
        char s[100000];
        in >> s;
        fr[i] = trie_insert(root, s);
    }

    coada.push(root);

    while (!coada.empty())
    {
        trie_node *nod = coada.front();
        coada.pop();
        for (int i = 0; i < 26; i++)
        {

            if (!nod->children[i])
                continue;

            trie_node *f = nod->fail;
            while (f && !f->children[i])
                f = f->fail;

            if (!f)
            {
                nod->children[i]->fail = root;
                root->out.push_back(nod->children[i]);
            }
            else
            {
                nod->children[i]->fail = f->children[i];
                f->children[i]->out.push_back(nod->children[i]);
            }

            coada.push(nod->children[i]);
        }
    }

    trie_node *t = root;

    for (char *p = word; *p; p++)
    {
        int ch = *p - 'a';
        while (t && !t->children[ch])
            t = t->fail;

        if (!t)
            t = root;
        else
            t = t->children[ch];

        t->nr++;
    }

    traversal(root);

    for (int i = 1; i <= n; i++)
        out << fr[i]->nr << '\n';

    return 0;
}
