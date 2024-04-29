// Simplified ADT: Binary Search Tree
// by vezzolter
// April 29, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called Binary Search Tree

#include <iostream>
#include "BST.h"


void printList(const BST<int>& tree) {
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Search Tree' console application!\n";

	// Create initial tree 
	std::cout << "\nCreating & filling initial tree #1...\n";
	BST<int> tree1;
	tree1.insert(7);
	tree1.insert(2);
	tree1.insert(0);
	tree1.insert(3);
	tree1.insert(1);
	tree1.insert(9);
	tree1.insert(1);

	// Show tree #1
	std::cout << "Is it empty:\t" << tree1.empty() << std::endl;
	//printTree(tree1);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}