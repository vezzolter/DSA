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
	std::cout << " -> BST t1 (8,3,13,2,6,10,17,0,3,7,9,11,14):\t";
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
	std::cout << " -> BST t2(t1):\t\t\t\t\t";
	BST t2(t1);
	printTree(t2);
	std::cout << " -> BST t3 = t1:\t\t\t\t";
	BST t3 = t1;
	printTree(t3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> *(t1.find(11)):\t\t\t\t" << *(t1.find(11)) << std::endl;
	std::cout << " -> *(t1.predecessor(11)):\t\t\t" << *(t1.predecessor(11)) << std::endl;
	std::cout << " -> *(t1.successor(11)):\t\t\t" << *(t1.successor(11)) << std::endl;
	std::cout << " -> *(t1.predecessor(t1.find(11)):\t\t" << *(t1.predecessor(t1.find(11))) << std::endl;
	std::cout << " -> *(t1.successor(t1.find(11))):\t\t" << *(t1.successor(t1.find(11))) << std::endl;
	std::cout << " -> t1.minimum():\t\t\t\t" << t1.minimum() << std::endl;
	std::cout << " -> t1.maximum():\t\t\t\t" << t1.maximum() << std::endl;
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}