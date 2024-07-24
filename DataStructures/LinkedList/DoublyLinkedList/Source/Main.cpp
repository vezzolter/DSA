// Simplified ADT: Doubly Linked List
// by vezzolter
// February 13, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called doubly linked list.

#include <iostream>
#include "DoublyLinkedList.h"


void printList(const DLL<int>& list) {
	std::cout << "Elements:\t";
	for (int i = 0; i < list.size(); i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Doubly Linked List' console application!\n";

	// Create initial list
	std::cout << "\nCreating & filling initial list #1...\n";
	DLL<int> list1;
	list1.pushFront(7);
	list1.pushBack(1);
	list1.pushBack(1);
	list1.pushBack(9);

	// Show list #1
	std::cout << "Is it empty:\t" << list1.empty() << std::endl;
	printList(list1);

	// Modify list #1
	std::cout << "\nChange first ('7') and last ('9') element to '0'...\n";
	list1.front() = 0;
	list1.back() = 0;
	printList(list1);

	// Insert into list #1
	std::cout << "\nInsert element '3' in the middle...\n";
	list1.insert((list1.size() / 2), 3);
    printList(list1);

	// Deep copy functionality
	std::cout << "\nCreate a list copies and compare...\n";
	DLL<int> list2(list1);
	DLL<int> list3 = list1;
	printList(list1);
	printList(list2);
	printList(list3);

	// Remove functionality
	std::cout << "\nFrom list #1 remove middle ('3'), first ('0') and last ('0') elements...\n";
	list1.erase(list1.size() / 2);
	list1.popFront();
	list1.popBack();
	printList(list1);
	printList(list2);
	printList(list3);

	// Clear
	std::cout << "\nClear list #2 and #3...\n";
	list2.clear();
	list3.clear();
	printList(list1);
	printList(list2);
	printList(list3);
	std::cout << "Are they empty: ";
	std::cout << list1.empty();
	std::cout << list2.empty();
	std::cout << list3.empty();
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}