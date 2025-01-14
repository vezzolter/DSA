// Title:   Binary Search Tree Container
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "BST.h"


void printTree(const BST& tree) {
	for (auto it = tree.cbegin(); it != tree.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Search Tree' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> BST t1:\t\t\t\t";
	BST t1;
	t1.insert(8); // level 0
	t1.insert(4); // level 1
	t1.insert(13);
	t1.insert(2); // level 2
	t1.insert(6);
	t1.insert(10);
	t1.insert(17);
	t1.insert(0); // level 3
	t1.insert(3);
	t1.insert(7);
	t1.insert(9);
	t1.insert(11);
	t1.insert(14);
	printTree(t1);
	std::cout << " -> BST t2(t1):\t\t\t\t";
	BST t2(t1);
	printTree(t2);
	std::cout << " -> BST t3 = t1:\t\t\t";
	BST t3 = t1;
	printTree(t3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}