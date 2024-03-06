// Simplified ADT: Linear Queue
// by vezzolter
// March 2, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of ADT linear queue based on linked list.

#include <iostream>
#include "LinearQueue.h"


// via copy of queue
void printQueue(const LQ<int>& q) {
	LQ<int> tempQueue(q);
	std::cout << "Elements:\t";
	while (!tempQueue.empty()) {
		std::cout << tempQueue.front() << " ";
		tempQueue.pop();
	}
	std::cout << std::endl;
	
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Linear Queue' console application!\n";

	// Create initial queue
	std::cout << "\nCreating & filling initial queue #1...\n";
	LQ<int> q1;
	q1.push(7);
	q1.push(1);
	q1.push(1);
	q1.push(9);

	// Show queue #1
	std::cout << "Is it empty:\t" << q1.empty() << std::endl;
	printQueue(q1);

	// Modify queue #1
	std::cout << "\nChange first ('7') and last ('9') element to '0'...\n";
	q1.front() = 0;
	q1.rear() = 0;
	printQueue(q1);

	// Insert into queue #1
	std::cout << "\nAdd element '3' to the end...\n";
	q1.push(3);
	printQueue(q1);

	// Deep copy functionality
	std::cout << "\nCreate a queue copies and compare...\n";
	LQ<int> q2(q1);
	LQ<int> q3 = q1;
	printQueue(q1);
	printQueue(q2);
	printQueue(q3);

	// Remove functionality
	std::cout << "\nFrom queue #1 remove first two ('0' and '1') elements...\n";
	q1.pop();
	q1.pop();
	printQueue(q1);
	printQueue(q2);
	printQueue(q3);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}