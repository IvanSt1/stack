//
// Created by ivan on 12.11.2021.
//

#ifndef STACK_STACK1_HPP
#define STACK_STACK1_HPP
template <typename T>
class Stack {
private:
    struct elem{
        T data;
        elem* next;
    };
    elem *first;
public:
    Stack();
    Stack( const Stack<T> &OtherStack); // копирования
    Stack( const Stack<T> &&OtherStack); // перемещения
    void push(T &&value);
    void push(const T& value);
    void pop();
    const T& head() const;
    ~Stack();
};

template<typename T>
Stack<T>::Stack() {
    first=nullptr;
}
template<typename T>
Stack<T>::~Stack() {
    while (first!= nullptr){
        elem* x=first;
        first=first->next;
        delete x;
    }
}
template<typename T>
void Stack<T>::push(T &&value) {
    elem* new_el= new elem;
    new_el->data=value;
    new_el->next=first;
    first=new_el;
}

template<typename T>
void Stack<T>::push(const T &value) {
    elem* new_el= new elem;
    new_el->data=value;
    new_el->next=first;
    first=new_el;
}

template<typename T>
void Stack<T>::pop() {
    if (first!= nullptr){
        elem* x=first;
        first=first->next;
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

template<typename T> // копирования
Stack<T>::Stack(const Stack<T> &otherStack) {
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
Stack<T>::Stack(const Stack<T> &&OtherStack) {
    first=OtherStack.first();
    OtherStack.first= nullptr;
}

#endif //STACK_STACK1_HPP
