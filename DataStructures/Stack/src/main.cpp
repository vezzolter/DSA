// Simplified ADT: Stack
// by vezzolter
// March 2, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called Stack.

#include <iostream>
#include "Stack.h"



// via copy of stack
void printStack(const Stack<int>& stack) {
	std::cout << "Elements:\t";
	Stack<int> tempStack = stack; 
	while (!tempStack.empty()) {
		std::cout << tempStack.peek() << " ";
		tempStack.pop();
	}
	std::cout << std::endl;

}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Stack' console application!\n";

	// Create initial stack
	std::cout << "\nCreating & filling initial stack #1...\n";
	Stack<int> stack1;
	stack1.push(7);
	stack1.push(1);
	stack1.push(1);
	stack1.push(9);

	// Show stack #1
	std::cout << "Is it empty:\t" << stack1.empty() << std::endl;
	printStack(stack1);
	std::cout << "Top element:\t" << stack1.peek() << std::endl;

	// Modify stack #1
	std::cout << "\nChange top element '9' to '0'...\n";
	stack1.peek() = 0;
	printStack(stack1);

	// Insert into stack #1
	std::cout << "\nAdd element '3' to the stack..\n";
	stack1.push(3);
	printStack(stack1);

	// Deep copy functionality
	std::cout << "\nCreate a stack copies and compare...\n";
	Stack<int> stack2(stack1);
	Stack<int> stack3 = stack1;
	printStack(stack1);
	printStack(stack2);
	printStack(stack3);

	// Remove functionality
	std::cout << "\nFrom stack #1 remove two top-most elements: '3' and '0'...\n";
	stack1.pop();
	stack1.pop();
	printStack(stack1);
	printStack(stack2);
	printStack(stack3);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}