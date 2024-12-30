// Title:   Stack Container (Array-Based)
// Authors: by vezzolter
// Date:    March 2, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Stack.h"


// Creates a copy of stack
void printStack(Stack stack) {
	for (; !stack.empty(); ) {
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Stack (Array)' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> Stack s1(0, 9, 1, 3, 0, 2, 7):\t";
	Stack s1;
	s1.push(0);
	s1.push(9);
	s1.push(1);
	s1.push(3);
	s1.push(0);
	s1.push(2);
	s1.push(7);
	printStack(s1);
	std::cout << " -> Stack s2(s1):\t\t\t";
	Stack s2(s1);
	printStack(s2);
	std::cout << " -> Stack s3 = s1:\t\t\t";
	Stack s3 = s1;
	printStack(s3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> s1.top:\t\t\t\t" << s1.top() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> s1.empty():\t\t\t\t" << s1.empty() << std::endl;
	std::cout << " -> s1.size(): \t\t\t\t" << s1.size() << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> s1.push(3): \t\t\t";
	s1.push(3);
	printStack(s1);
	std::cout << " -> s1.push(3): \t\t\t";
	s1.push(3);
	printStack(s1);
	std::cout << " -> s1.pop(): \t\t\t\t";
	s1.pop();
	printStack(s1);
	std::cout << " -> s1.swap(s2): \t\t\t";
	s1.swap(s2);
	printStack(s1);
	std::cout << "   - s2:\t\t\t\t";
	printStack(s2);
	std::cout << "   - s3:\t\t\t\t";
	printStack(s3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}