#ifndef ARRAYSTACH_H
#define ARRAYSTACK_H

#include <string>
#include <sstream>

#include "../istack.h"

template<typename T>
class ArrayStack : public IStack<T> {
    private:
        int capacity;
        int top;
        T **elements;
        void expandArray();
    public:
        ArrayStack(int capacity = 10);
        ArrayStack(const ArrayStack& stack);
        ~ArrayStack();
        ArrayStack& operator=(const ArrayStack& right);
        void push(const T& element);
        T pop();
        T peek() const;
        bool isEmpty() const;
        std::string toString() const;
};

template<typename T>
void ArrayStack<T>::expandArray() {
    if (this->capacity <= this->top) {
        T ** temp = this->elements;
        this->capacity = this->capacity * 2;
        this->elements = new T*[this->capacity];
        for (int i = 0; i < this->top; i++) {
            this->elements[i] = temp[i];
        }
        for (int i = this->top; i < this->capacity; i++) {
            this->elements[i] = nullptr;
        }
        delete [] temp;
        temp = nullptr;
    }
}

template<typename T>
ArrayStack<T>::ArrayStack(int capacity) {
    this->capacity = capacity;
    this->top = 0;
    this->elements = new T*[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->elements[i] = nullptr;
    }
}

template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack& stack) {
    this->top = stack.top;
    this->capacity = stack.capacity;

    if (stack.elements != nullptr) {
        this->elements = new T*[this->capacity];
        for (int i = 0; i < this->top; i++) {
            this->elements[i] = new T(*stack.elements[i]);
        }
        for (int i = this->top; i < this->capacity; i++) {
            this->elements[i] = nullptr;
        }
    }
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    for (int i = 0; i < this->top; i++) {
        delete this->elements[i];
    }
    delete [] this->elements;
}

template<typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& right) {
    if (this == &right) {
        throw "Self-assigning at operator= ";
    }
    this->top = right.top;
    this->capacity = right.capacity;
    for (int i = 0; i < this->top; i++) {
        delete this->elements[i];
    }
    delete [] this->elements;
    if (right.elements != nullptr) {
        this->elements = new T*[this->capacity];
        for (int i = 0; i < this->top; i++) {
            this->elements[i] = new T(*right.elements[i]);
        }
        for (int i = this->top; i < this->capacity; i++) {
            this->elements[i] = nullptr;
        }
    }

    return *this;
}

template<typename T>
void ArrayStack<T>::push(const T& element) {
    this->expandArray();
    this->elements[this->top] = new T(element);
    this->top++;
}

template<typename T>
T ArrayStack<T>::pop() {
    if (this->isEmpty()) {
        throw  "The stack is empty.";       
    } 
    T temp = *this->elements[this->top - 1];
    delete this->elements[this->top - 1];
    this->elements[this->top - 1] = nullptr;
    this->top--;
    return temp;
    
}

template<typename T>
T ArrayStack<T>::peek() const {
    if (this->isEmpty()) {
        throw  "The stack is empty.";        
    }
    return *this->elements[this->top - 1];
}

template<typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->elements[0] == nullptr;
}

template<typename T>
std::string ArrayStack<T>::toString() const {
    std::stringstream stream;
    if (!this->isEmpty()) {
        stream << "The stack looks like; " << std::endl;
        for (int i = 0; i < this->top; i++) {
            stream << i << " : " << '[' << *this->elements[i] << ']' << std::endl;
        }
    } else {
        stream << "The stack is empty" << std::endl;
    }
    return stream.str();
}
#endif

