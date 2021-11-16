#include <iostream>
#include "stack1.hpp"

int main() {
    Stack<int> x;
    x.push(10);
    x.push(11);
    Stack<int> z(x);

    return 0;
}
