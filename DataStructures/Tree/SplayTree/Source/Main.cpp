// Title:   Splay Tree Container
// Authors: by vezzolter
// Date:    April 15, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "SplayTree.h"


void printTree(const SplayTree& tree) {
	for (auto it = tree.cbegin(); it != tree.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\t\tWelcome to the 'Splay Tree' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> Splay Tree t1 (25,11,46,7,17,30,88,9,26,37, find(26)):\t";
	SplayTree t1;
	// fill in t1
	printTree(t1);
	SplayTree t2(t1);
	std::cout << " -> Splay Tree t2(t1):\t\t\t\t";
	printTree(t2);
	SplayTree t3 = t1;
	std::cout << " -> Splay Tree t3 = t1:\t\t\t\t";
	printTree(t3);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}