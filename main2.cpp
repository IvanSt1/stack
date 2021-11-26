#include <iostream>
#include "stack2.hpp"

int main() {
    Stack<int> x;
    x.push(1);

    Stack<int>z(x);
    return 0;
}
