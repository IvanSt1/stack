//
// Created by ivan on 12.11.2021.
//

#ifndef STACK_STACK2_HPP
#define STACK_STACK2_HPP

#include "typeinfo"
struct forma{
    int x;
    int y;
    forma(){
        x=0;
        y=0;
    }
    forma(int x1, int y1){
        x=x1;
        y=y1;
    }
};

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
    Stack(Stack<T> &OtherStack); // копирования
    Stack( Stack<T> &&OtherStack); // перемещения
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
    T x( value...);
    elem *new_el = new elem;
    new_el->data = x;
    new_el->next = first;
    first = new_el;
}

template<typename T> // копирования
Stack<T>::Stack( Stack<T> &otherStack) {
    first= nullptr;
    elem* x,*cur;
    elem* new_el;
    x=otherStack.first;
    while (x!= nullptr) {
        new_el=new elem;
        new_el->data=x->data;
        if(first== nullptr){
            first=new_el;
        }
        else{
            cur=first;
            while(cur->next!= nullptr){
                cur=cur->next;
            }
            cur->next=new_el;
        }
        x=x->next;
    }
}

template<typename T>// перемещения
Stack<T>::Stack( Stack<T> &&OtherStack) {
    first=OtherStack.first();
    OtherStack.first= nullptr;
}

#endif //STACK_STACK2_HPP
