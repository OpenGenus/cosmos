#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int info;
        Node* lc;
        Node* rc;
        Node (int info) {
            this->info = info;
            lc = NULL;
            rc = NULL;
        }
};

class BT {
    public:
        Node* root;
        BT() {
            root = NULL;
        }
        void zigzag_traversal();
};

void BT :: zigzag_traversal() {
    stack<Node*> st1, st2;
    st2.push (root);
    while (!st1.empty() || !st2.empty()) {
        while (!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            if (curr->rc)
                st2.push (curr->rc);
            if (curr->lc)
                st2.push (curr->lc);
            cout << curr->info << " ";
        }
        while (!st2.empty()) {
            Node* curr = st2.top();
            st2.pop();
            if (curr->lc)
                st1.push (curr->lc);
            if (curr->rc)
                st1.push (curr->rc);
            cout << curr->info << " ";
        }
    }
}

int main() {
    BT bt;
    bt.root = new Node (1);
    bt.root->lc = new Node (2);
    bt.root->rc = new Node (3);
    bt.root->lc->lc = new Node (4);
    bt.root->lc->rc = new Node (5);
    bt.root->rc->lc = new Node (6);
    bt.root->rc->rc = new Node (7);
    bt.zigzag_traversal();
    return 0;
}
