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
	std::cout << " -> SplayTree t1:\t\t\t\t";
	SplayTree t1;
	t1.insert(25);
	t1.insert(11);
	t1.insert(46);
	t1.insert(7);
	t1.insert(17);
	t1.insert(30);
	t1.insert(88);
	t1.insert(9);
	t1.insert(26);
	t1.insert(37);
	t1.find(26);
	printTree(t1);
	SplayTree t2(t1);
	std::cout << " -> SplayTree t2(t1):\t\t\t\t";
	printTree(t2);
	SplayTree t3 = t1;
	std::cout << " -> SplayTree t3 = t1:\t\t\t\t";
	printTree(t3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> *(t1.find(26)):\t\t\t\t" << *(t1.find(26)) << std::endl;
	std::cout << " -> *(t1.predecessor(26)):\t\t\t" << *(t1.predecessor(26)) << std::endl;
	std::cout << " -> *(t1.successor(26)):\t\t\t" << *(t1.successor(26)) << std::endl;
	auto itTo26 = t1.find(26);
	std::cout << " -> *(t1.predecessor(itTo26):\t\t\t" << *(t1.predecessor(itTo26)) << std::endl;
	std::cout << " -> *(t1.successor(itTo26)):\t\t\t" << *(t1.successor(itTo26)) << std::endl;
	std::cout << " -> *(t1.minimum()):\t\t\t\t" << *(t1.minimum()) << std::endl;
	std::cout << " -> *(t1.maximum()):\t\t\t\t" << *(t1.maximum()) << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity (on t2 so you don't have to follow t1 changes):\n";
	std::cout << " -> t2.empty():\t\t\t\t\t" << t2.empty() << std::endl;
	std::cout << " -> t2.size(): \t\t\t\t\t" << t2.size() << std::endl;
	std::cout << " -> t2.height(): \t\t\t\t" << t2.height() << std::endl;
	itTo26 = t2.find(26);
	std::cout << "   - t2.height(itTo26): \t\t\t" << t2.height(itTo26) << std::endl;
	std::cout << "   - t2.height(26): \t\t\t\t" << t2.height(26) << std::endl;
	std::cout << "   - t2.height(37): \t\t\t\t" << t2.height(37) << std::endl;
	std::cout << "   - t2.height(46): \t\t\t\t" << t2.height(46) << std::endl;
	std::cout << "   - t2.height(88): \t\t\t\t" << t2.height(88) << std::endl;
	std::cout << " -> t2.depth(): \t\t\t\t" << t2.depth() << std::endl;
	std::cout << "   - t2.depth(itTo26): \t\t\t\t" << t2.depth(itTo26) << std::endl;
	std::cout << "   - t2.depth(26): \t\t\t\t" << t2.depth(26) << std::endl;
	std::cout << "   - t2.depth(37): \t\t\t\t" << t2.depth(37) << std::endl;
	std::cout << "   - t2.depth(46): \t\t\t\t" << t2.depth(46) << std::endl;
	std::cout << "   - t2.depth(88): \t\t\t\t" << t2.depth(88) << std::endl;
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}