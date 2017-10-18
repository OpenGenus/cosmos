#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

/*
 Part of Cosmos by OpenGenus Foundation
*/

/*
    hash_table synopsis

class hash_table {
public:
    // Initialize your data structure here.
    hash_table() :container({}) {}

    // Inserts a value to the set. Returns true if the set did not already contain the specified
       element.
    bool insert(int val);

    // Removes a value from the set. Returns true if the set contained the specified element.
    bool remove(int val);

    // Get a random element from the set.
    int getRandom();

    void display();

private:
    map<size_t, int> container;

    size_t getKey(int val);
};
*/

class hash_table {
public:
    /** Initialize your data structure here. */
    hash_table() :container({}) {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified
       element. */
    bool insert(int val) {
        size_t seat = getKey(val);
        if (container.find(seat) != container.end()) {
            return false;
        } else {
            container.insert(make_pair(seat, val));
        }

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        size_t seat = getKey(val);
        if (container.find(seat) == container.end()) {
            return false;
        } else {
            container.erase(seat);
        }

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (!container.empty()) {
            ptrdiff_t times = rand() % container.size();
            auto it = container.begin();
            while (--times >= 0)
                ++it;

            return it->second;
        }

        return 0;
    }

    void display() {
        auto it = container.begin();
        while (it != container.end())
            cout << it++->second << endl;
    }

private:
    map<size_t, int> container;

    size_t getKey(int val) {
        return (size_t)hash<string> {} (to_string(val));
    }
};

int main() {
    hash_table *ht = new hash_table();
    if (!ht->insert(3))  // return true
        cout << "error";
    if (ht->insert(3))  // return false
        cout << "error";
    if (!ht->insert(4))  // return true
        cout << "error";
    if (!ht->insert(5))  // return true
        cout << "error";
    if (ht->remove(2))  // return false
        cout << "error";
    if (!ht->remove(3))  // return false
        cout << "error";
    ht->display();

    return 0;
}
