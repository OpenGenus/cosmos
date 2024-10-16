
#include <iostream>

#include "../istack.h"
#include "arraystack.h"

int main()
{
    int s;
    IStack<int> *stack = new ArrayStack<int>();

    try {
        stack->peek();
    } catch (char const *e)
    {
        std::cout << e << std::endl << std::endl;
    }

    stack->push(20);
    std::cout << "Added 20" << std::endl;

    IStack<int> *stack2 = stack;
    std::cout << "1 " << std::endl;
    std::cout << stack->toString() << std::endl;
    std::cout << "2 " << std::endl;
    std::cout << stack2->toString() << std::endl;

    stack->push(30);
    std::cout << "Added 30" << std::endl;

    std::cout << std::endl << std::endl << stack->toString() << std::endl << std::endl;

    s = stack->peek();
    std::cout << "First element is now: " << s << std::endl;
    std::cout << "removed: " << stack->pop() << std::endl;

    s = stack->peek();
    std::cout << "First element is now: " << s << std::endl;

    delete stack;

    return 0;
}
