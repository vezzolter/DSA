// Title:   Singly Linked List Container
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "SinglyLinkedList.h"


void printList(const SLL& list) {
	//for (auto x : list) { std::cout << x << " "; }
	for (auto it = list.cbegin(); it != list.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Singly Linked List' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> SLL l1:\t\t\t\t";
	SLL l1;
	for (int i = 9; i >= 0; --i) { l1.pushFront(i); }
	printList(l1);
	std::cout << " -> SLL l2(l1):\t\t\t\t";
	SLL l2(l1);
	printList(l2);
	std::cout << " -> SLL l3 = l1:\t\t\t";
	SLL l3 = l1;
	printList(l3);
	std::cout << std::endl;

	// Helper Iterators
	SLL::iterator it = l1.begin();
	SLL::iterator last = it;
	for (; it != l1.end(); ++it) { last = it; }

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> l1.front():\t\t\t\t" << l1.front() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> l1.empty():\t\t\t\t" << l1.empty() << std::endl;
	std::cout << " -> l1.size(): \t\t\t\t" << l1.size() << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> l1.insertAfter(itrTo9, 3):  \t";
	l1.insertAfter(last, 3);
	printList(l1);
	std::cout << " -> l1.eraseAfter(itrTo9): \t\t";
	l1.eraseAfter(last);
	printList(l1);
	std::cout << " -> l1.pushFront(3): \t\t\t";
	l1.pushFront(3);
	printList(l1);
	std::cout << " -> l1.popFront(): \t\t\t";
	l1.popFront();
	printList(l1);
	std::cout << " -> l1.reverse(): \t\t\t";
	l1.reverse();
	printList(l1);
	std::cout << " -> l1.assign(5, 3): \t\t\t";
	l1.assign(5, 3);
	printList(l1);
	std::cout << " -> l1.assign(l2.begin(), l2.end()):  \t";
	l1.assign(l2.begin(), l3.end());
	printList(l1);
	std::cout << " -> l1.clear(): \t\t\t";
	l1.clear();
	printList(l1);
	std::cout << " -> l1.resize(5): \t\t\t";
	l1.resize(5);
	printList(l1);
	std::cout << " -> l1.resize(10, 3): \t\t\t";
	l1.resize(10, 3);
	printList(l1);
	std::cout << " -> l1.swap(l2): \t\t\t";
	l1.swap(l2);
	printList(l1);
	std::cout << "   - l2:\t\t\t\t";
	printList(l2);
	std::cout << "   - l3:\t\t\t\t";
	printList(l3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}