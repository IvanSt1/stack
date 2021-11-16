
#include <iostream>
#include "../stack2.hpp"
#include "gtest/gtest.h"
TEST(Simple, TEst){
    EXPECT_TRUE(true);
}
TEST(stack1, construcktor){
    Stack<int> x;
    EXPECT_ANY_THROW(x.head());
    Stack<double> y;
    EXPECT_ANY_THROW(y.head());
    Stack<char> z;
    EXPECT_ANY_THROW(z.head());
}
TEST(stack1, push){
    Stack<int> x;
    x.push(1);
    EXPECT_EQ(x.head(),1);
    x.push(2);
    EXPECT_EQ(x.head(),2);
}

TEST(stack1, pop){
    Stack<int> x;
    x.push(1);
    x.push(2);
    EXPECT_EQ(x.head(),2);
    x.pop();
    EXPECT_EQ(x.head(),1);
}
TEST(stack1, copy){
    Stack<int> x;
    Stack<int> y(x);
    x.push(1);
    EXPECT_EQ(x.head(),1);
    x.push(2);
    EXPECT_EQ(x.head(),2);
}
