#include "singly_linked_list.h"

int main()
{
    Linkedlist<int> link;
    for (int i = 10; i > 0; --i)
        link.rearAdd(i);
    link.print();
    std::cout << link.size() << std::endl;
    Linkedlist<int> link1(link);
    link1 = link1;
    link1.print();
    link1.deletePos(100);
    link1.modify(5, 100);
    link1.insert(3, 50);
    std::cout << link1.size() << std::endl;
    link1.print();

    link1.removeKthNodeFromEnd(3);
    std::cout<<"After deleting 3rd node from the end\n";
    link1.print();

    link1.sort();
    link1.print();
    link1.destroy();
    std::cout << link1.size() << std::endl;
    return 0;
}
