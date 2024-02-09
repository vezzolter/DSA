// Simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called singly linked list.

#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	// Greetings
	std::cout << "Welcome to the 'Singly Linked List' console application!\n\n";

	SLL<int> list1;
	list1.push_front(9);
	list1.push_front(1);
	list1.push_front(1);
	list1.push_front(7);

	std::cout << "Is empty:\t" << list1.empty() << std::endl;

	std::cout << "Elements:\t";
	for (int i = 0; i < list1.size(); i++) {
		std::cout << list1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\nChanging first element via front() ";
	list1.front() = 5;
	std::cout << "to: " << list1[0] << std::endl;

	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}