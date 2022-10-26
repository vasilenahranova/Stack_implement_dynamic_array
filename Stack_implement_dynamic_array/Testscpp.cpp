#include<iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"Stack.h"
#include"Doctest.h"

TEST_CASE("Just after we create a stack it is empty") {
    RStack<int> stack1;
    CHECK(stack1.isEmpty()==1);
}

TEST_CASE("After pushing elements, it is no longer empty") {
    RStack<int> stack1;
    stack1.push(10);
    CHECK(stack1.isEmpty()==0);
}
TEST_CASE("Testing the pop funtion") {
    RStack<int> stack1;
    stack1.push(10);
    stack1.push(13);
    CHECK(stack1.top() == 13);
    stack1.pop();
    CHECK(stack1.top() == 10);
}