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
	std::cout << "Capacity:\n";
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

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> t2.insert(8):  \t\t\t\t";
	t2.insert(8);
	printTree(t2);
	std::cout << "   - t2.depth(8): \t\t\t\t" << t2.depth(8) << std::endl;  // new root after splay
	std::cout << "   - t2.depth(9): \t\t\t\t" << t2.depth(9) << std::endl;  // parent of inserted node
	std::cout << "   - t2.depth(26):\t\t\t\t" << t2.depth(26) << std::endl; // previous root
	std::cout << "   - t2.depth(11):\t\t\t\t" << t2.depth(11) << std::endl; // deep subtree node
	std::cout << "   - t2.depth(17):\t\t\t\t" << t2.depth(17) << std::endl; // part of splaying path
	std::cout << "   - t2.depth(7):\t\t\t\t" << t2.depth(7) << std::endl;   // static node
	std::cout << " -> t3.remove(37): \t\t\t\t";
	t3.remove(37);
	printTree(t3);
	std::cout << "   - t3.depth(37):\t\t\t\t" << t3.depth(37) << std::endl; // removed
	std::cout << "   - t3.depth(30):\t\t\t\t" << t3.depth(30) << std::endl; // new root
	std::cout << "   - t3.depth(26):\t\t\t\t" << t3.depth(26) << std::endl; // child of deleted node
	std::cout << "   - t3.depth(46):\t\t\t\t" << t3.depth(46) << std::endl; // reattached to new root
	std::cout << "   - t3.depth(9):\t\t\t\t" << t3.depth(9) << std::endl;   // checks stability of left structure
	std::cout << "   - t3.depth(17):\t\t\t\t" << t3.depth(17) << std::endl; // confirms middle subtree preserved
	std::cout << " -> t1.clear(): \t\t\t\t\t";
	t1.clear();
	printTree(t1);
	std::cout << " -> t1.swap(t2): \t\t\t\t";
	t1.swap(t2);
	printTree(t1);
	std::cout << "   - t2:\t\t\t\t\t";
	printTree(t2);
	std::cout << "   - t3:\t\t\t\t\t";
	printTree(t3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}