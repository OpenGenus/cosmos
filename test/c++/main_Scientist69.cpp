#include "Tree.h"
#include <iostream>

using namespace std;
int main()
{

    //creating tree with "5" as root
    Tree<int> tree(5);
    tree.insert(2);
    tree.insert(88);
    tree.inorder();
    cout << "does tree contain 2?: ";
    cout << tree.find(2) << endl;
    cout << "does tree contain 3?: ";
    cout << tree.find(3) << endl;

    Tree<int> copytree(tree);
    cout << "copied original tree..." << endl;
    copytree.preorder();
    cout << "after deletion of 2:\n";
    copytree.Delete(2);
    copytree.postorder();


    return 0;
}
