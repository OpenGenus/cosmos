#ifndef ISTACK_H
#define ISTACK_H

#include <string>
#include <sstream>

template <typename T>
class IStack {
    public:
        virtual ~IStack() {};
        /**
         * Add an element to stack
         */
        virtual void push(const T& element) = 0;
        /**
         * Remove an element from stack
         */ 
        virtual T pop() = 0;
        /**
         * Retuns the fist element in the stack
         */
        virtual T peek() const = 0;
        /**
         * Returns if the stack is empty
         */ 
        virtual bool isEmpty() const = 0;
        /**
         * Gets a string-representation of the stack
         */
        virtual std::string toString() const = 0;
};
 
#endif