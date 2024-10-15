#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet;

    // Inserting elements
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(15);
    mySet.insert(10); // Duplicate

    // Displaying elements
    cout << "Set elements: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Finding an element
    int key = 15;
    if (mySet.find(key) != mySet.end())
        cout << key << " is found in the set\n";
    else
        cout << key << " is not found\n";

    // Removing an element
    mySet.erase(10);
    cout << "After removing 10: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
