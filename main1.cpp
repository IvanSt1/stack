#include <iostream>
#include "stack1.hpp"

int main() {
    Stack<int> x;
    x.push(10);
    x.push(11);
    int y = x.head();
    std::cout << y;
    x.pop();
    y = x.head();
    std::cout <<" "<< y;
    return 0;
}
