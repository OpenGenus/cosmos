#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v) : key(k), value(v) {
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp; // map the key to the node in the linked list
    Node *head;
    Node *tail;

    LRUCache(int c) : capacity(c) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    void addNode(Node *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node *node) {
        removeNode(node);
        addNode(node);
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node *node = mp[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node *node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (mp.size() == capacity) {
                mp.erase(tail->prev->key);
                removeNode(tail->prev);
            }
            Node *node = new Node(key, value);
            addNode(node);
            mp[key] = node;
        }
    }
};
