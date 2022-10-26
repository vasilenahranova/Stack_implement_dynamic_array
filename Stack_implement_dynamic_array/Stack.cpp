#include<iostream>
#include "Stack.h"

int main() {
	RStack<int> myStack;
	myStack.pop();
	if (myStack.isEmpty())
		std::cout << "The stack is empty!"<<std::endl;
	else
		std::cout << "The stack is not empty!"<<std::endl;
	myStack.push(2);
	if (myStack.isEmpty())
		std::cout << "The stack is empty!"<<std::endl;
	else
		std::cout << "The stack is not empty!"<<std::endl;
	std::cout << myStack.top() << std::endl;
	myStack.pop();
	if (myStack.isEmpty())
		std::cout << "The stack is empty!" << std::endl;
	else
		std::cout << "The stack is not empty!" << std::endl;
	myStack.top();
}