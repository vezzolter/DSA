// Title:   AVL Tree Container
// Authors: by vezzolter
// Date:    February 17, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "AVL.h"


void printTree(const AVL& tree) {
	for (auto it = tree.cbegin(); it != tree.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'AVL Tree' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> AVL t1 (25,11,46,7,17,30,88,9,26,37):\t";
	AVL t1;
	t1.insert(25); // level 0
	t1.insert(11); // level 1
	t1.insert(46);
	t1.insert(7);  // level 2
	t1.insert(17);
	t1.insert(30);
	t1.insert(88);
	t1.insert(9); // level 3
	t1.insert(26);
	t1.insert(37);
	printTree(t1);
	std::cout << " -> AVL t2(t1):\t\t\t\t\t";
	AVL t2(t1);
	printTree(t2);
	std::cout << " -> AVL t3 = t1:\t\t\t\t";
	AVL t3 = t1;
	printTree(t3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> *(t1.find(25)):\t\t\t\t" << *(t1.find(25)) << std::endl;
	std::cout << " -> *(t1.predecessor(25)):\t\t\t" << *(t1.predecessor(25)) << std::endl;
	std::cout << " -> *(t1.successor(25)):\t\t\t" << *(t1.successor(25)) << std::endl;
	std::cout << " -> *(t1.predecessor(t1.find(25)):\t\t" << *(t1.predecessor(t1.find(25))) << std::endl;
	std::cout << " -> *(t1.successor(t1.find(25))):\t\t" << *(t1.successor(t1.find(25))) << std::endl;
	std::cout << " -> t1.minimum():\t\t\t\t" << t1.minimum() << std::endl;
	std::cout << " -> t1.maximum():\t\t\t\t" << t1.maximum() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> t1.empty():\t\t\t\t\t" << t1.empty() << std::endl;
	std::cout << " -> t1.size(): \t\t\t\t\t" << t1.size() << std::endl;
	std::cout << " -> t1.height(): \t\t\t\t" << t1.height() << std::endl;
	std::cout << "   - t1.height(*(t1.find(25)): \t\t\t" << t1.height(*(t1.find(25))) << std::endl;
	std::cout << "   - t1.height(25): \t\t\t\t" << t1.height(25) << std::endl;
	std::cout << "   - t1.height(11): \t\t\t\t" << t1.height(11) << std::endl;
	std::cout << "   - t1.height(7): \t\t\t\t" << t1.height(7) << std::endl;
	std::cout << "   - t1.height(9): \t\t\t\t" << t1.height(9) << std::endl;
	std::cout << " -> t1.depth(): \t\t\t\t" << t1.depth() << std::endl;
	std::cout << "   - t1.depth(*(t1.find(25)): \t\t\t" << t1.depth(*(t1.find(25))) << std::endl;
	std::cout << "   - t1.depth(25): \t\t\t\t" << t1.depth(25) << std::endl;
	std::cout << "   - t1.depth(11): \t\t\t\t" << t1.depth(11) << std::endl;
	std::cout << "   - t1.depth(7): \t\t\t\t" << t1.depth(7) << std::endl;
	std::cout << "   - t1.depth(17): \t\t\t\t" << t1.depth(17) << std::endl;
	std::cout << "   - t1.depth(9): \t\t\t\t" << t1.depth(9) << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> t1.insert(8):  \t\t\t\t";
	t1.insert(8);
	printTree(t1);
	std::cout << "   - t1.depth(25): \t\t\t\t" << t1.depth(25) << std::endl;
	std::cout << "   - t1.depth(11): \t\t\t\t" << t1.depth(11) << std::endl;
	std::cout << "   - t1.depth(8):\t\t\t\t" << t1.depth(8) << std::endl;
	std::cout << "   - t1.depth(17):\t\t\t\t" << t1.depth(17) << std::endl;
	std::cout << "   - t1.depth(7):\t\t\t\t" << t1.depth(7) << std::endl;
	std::cout << "   - t1.depth(9):\t\t\t\t" << t1.depth(9) << std::endl;
	std::cout << " -> t1.remove(17): \t\t\t\t";
	t1.remove(17);
	printTree(t1);
	std::cout << "   - t1.depth(17):\t\t\t\t" << t1.depth(17) << std::endl;
	std::cout << "   - t1.depth(25):\t\t\t\t" << t1.depth(25) << std::endl;
	std::cout << "   - t1.depth(8):\t\t\t\t" << t1.depth(8) << std::endl;
	std::cout << "   - t1.depth(7):\t\t\t\t" << t1.depth(7) << std::endl;
	std::cout << "   - t1.depth(11):\t\t\t\t" << t1.depth(11) << std::endl;
	std::cout << "   - t1.depth(9):\t\t\t\t" << t1.depth(9) << std::endl; 
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