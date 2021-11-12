//
// Created by ivan on 12.11.2021.
//

#ifndef STACK_STACK2_HPP
#define STACK_STACK2_HPP

#include "typeinfo"

template<typename T>
class Stack {
private:
    struct elem {
        T data;
        elem *next;
    };
    elem *first;
public:
    Stack();

    void push(T &&value);

    template<typename ... Args>
    void push_emplace(Args &&... value);

    void pop();

    const T &head() const;

    ~Stack();
};

template<typename T>
Stack<T>::Stack() {
    first = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
    while (first != nullptr) {
        elem *x = first;
        first = first->next;
        delete x;
    }
}

template<typename T>
void Stack<T>::push(T &&value) {
    elem *new_el = new elem;
    new_el->data = value;
    new_el->next = first;
    first = new_el;
}


template<typename T>
void Stack<T>::pop() {
    if (first != nullptr) {
        elem *x = first;
        first = first->next;
        delete x;
    }
}

template<typename T>
const T &Stack<T>::head() const {
    if (first != nullptr) {
        return first->data;
    } else {
         throw std::logic_error("No elements");
    }
}

template<typename T>
template<typename... Args>
void Stack<T>::push_emplace(Args &&... value) {
    T n;

}

#endif //STACK_STACK2_HPP
