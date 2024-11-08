// Title:   Singly Linked List Container
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "SinglyLinkedList.h"


void printList(SLL& list) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Singly Linked List' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> SLL list1:\t\t";
	SLL list1;
	for (int i = 9; i >= 0; --i) { list1.pushFront(i); }
	printList(list1);
	std::cout << " -> SLL list2(list1):\t";
	SLL list2(list1);
	printList(list2);
	std::cout << " -> SLL list3 = list1:\t";
	SLL list3 = list1;
	printList(list3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> list1.front():\t" << list1.front() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> list1.empty():\t" << list1.empty() << std::endl;
	std::cout << " -> list1.size(): \t" << list1.size() << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> list1.insertAfter(9, 3): \t";
	list1.insertAfter(9, 3);
	printList(list1);
	std::cout << " -> list1.eraseAfter(9): \t";
	list1.eraseAfter(9);
	printList(list1);
	std::cout << " -> list1.pushFront(3): \t";
	list1.pushFront(3);
	printList(list1);
	std::cout << " -> list1.popFront(): \t\t";
	list1.popFront();
	printList(list1);
	std::cout << " -> list1.assign(9, 3): \t";
	list1.assign(9, 3);
	printList(list1);
	std::cout << " -> list1.clear(): \t\t";
	list1.clear();
	printList(list1);
	std::cout << " -> list1.resize(9, 5): \t";
	list1.resize(9, 5);
	printList(list1);
	std::cout << " -> list1.swap(arr2): \t\t";
	list1.swap(list2);
	printList(list1);
	std::cout << "   - list2:\t\t\t";
	printList(list2);
	std::cout << "   - list3:\t\t\t";
	printList(list3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}