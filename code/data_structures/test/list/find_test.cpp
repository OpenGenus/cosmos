#include <assert.h>
#include "./../../src/list/singly_linked_list/operations/find/find.cpp"

//Part of Cosmos by OpenGenus Foundation
int main()
{
    // Create linked list
    LinkedList list;
    // Push in elements
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    push(&list, 5);
    push(&list, 6);
    // Find elements
    assert(find(&list, 1) == 1);
    assert(find(&list, 3) == 1);
    assert(find(&list, 6) == 1);
    assert(find(&list, 10) == 0);
    assert(find(&list, 0) == 0);
    std::cout << "Testing Complete" << "\n";
}
