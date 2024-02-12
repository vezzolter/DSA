// Simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called singly linked list.

#include <iostream>
#include "SinglyLinkedList.h"

void printList(const SLL<int>& list) {
	std::cout << "Elements:\t";
	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Greetings
	std::cout << "Welcome to the 'Singly Linked List' console application!\n\n";

	// Create initial list
	std::cout << "Creating & filling initial list #1...\n";
	SLL<int> list1;
	list1.pushFront(9);
	list1.pushFront(1);
	list1.pushFront(1);
	list1.pushFront(7);

	// Show it
	std::cout << "Is it empty:\t" << list1.empty() << std::endl;
	printList(list1);

	// Modify it
	std::cout << "\nChange first element ('7') to '5'...\n";
	list1.front() = 5;
	printList(list1);

	// Insert to it
	std::cout << "\nInsert element '3' before '9'...\n";
	list1.insertAfter(list1.size()-2, 3);
	printList(list1);

	// Deep copy mechanics
	std::cout << "\nCreate a list copies and compare...\n";
	SLL<int> list2(list1);
	SLL<int> list3 = list1;
	printList(list1);
	printList(list2);
	printList(list3);

	// Remove from first
	std::cout << "\nFrom list #1 remove first ('5') and last ('9') elements...\n";
	list1.popFront();
	list1.eraseAfter(list1.size() - 2);
	printList(list1);
	printList(list2);
	printList(list3);

	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}