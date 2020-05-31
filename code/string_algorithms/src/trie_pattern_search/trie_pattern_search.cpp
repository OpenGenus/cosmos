#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#define alphas 26
using namespace std;

typedef struct Node
{
    Node *child[alphas];
    int leaf;
}trieNode;

trieNode* getNode()
{
    trieNode *t = new trieNode;
    if (t)
    {
        for (int i = 0; i < alphas; i++)
            t->child[i] = NULL;
        t->leaf = 0;
    }
    return t;
}

void insert(trieNode *root, string s)
{
    trieNode *head = root;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (head->child[s[i] - 'a'] == NULL)
            head->child[s[i] - 'a'] = getNode();
        head = head->child[s[i] - 'a'];
    }
    head->leaf = 1;
}

void walk(trieNode *root)
{
    trieNode *head = root;
    for (int i = 0; i < alphas; i++)
        if (head->child[i] != NULL)
        {
            cout << char(i + 'a') << " ";
            walk(head->child[i]);
        }
}

bool noChildren(trieNode *root)
{
    trieNode *head = root;
    for (int i = 0; i < 26; i++)
        if (head->child[i])
            return false;
    return true;
}

bool notLeaf(trieNode *root)
{
    if (root->leaf == 1)
        return false;
    return true;
}

bool deletes(trieNode *root, string s, int l, int len)
{
    if (root)
    {
        if (l == len)
        {
            root->leaf = 0;
            if (noChildren(root))
                return true;
            return false;
        }
        else
        {
            int index = s[l] - 'a';
            if (deletes(root->child[index], s, l + 1, len))
            {
                free(root->child[index]);
                root->child[index] = NULL;
                return notLeaf(root) && noChildren(root);
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> str;
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        str.push_back(s);
    }

    trieNode *root = getNode();
    for (int i = 0; i < n; i++)
        insert(root, str[i]);
    walk(root);
    cout << endl;
    cin >> s;
    deletes(root, s, 0, n);
    walk(root);
    return 0;
}
