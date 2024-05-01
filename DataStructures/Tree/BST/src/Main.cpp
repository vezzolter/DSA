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
	// Note: there is no balancing
	std::cout << "\nCreating & filling initial tree #1...\n";
	BST<int> tree1;
	tree1.insert(8); // level 0
	tree1.insert(4); // level 1
	tree1.insert(13);
	tree1.insert(2); // level 2
	tree1.insert(6);
	tree1.insert(10);
	tree1.insert(17);
	tree1.insert(0); // level 3
	tree1.insert(3);
	tree1.insert(7);
	tree1.insert(9);
	tree1.insert(11);
	tree1.insert(14);

	// Visualization is from markdown file
	//                  8
	//           /             \
	//         4                13
	//      /    \            /     \
	//     2      6         10        17
	//   /   \     \       /  \      /
	//  0     3     7     9   11   14

	// Show stats
    std::cout << "\nShowing statistics of the tree #1...\n";
    std::cout << "Predecessor of '8' is " << tree1.predecessor(8) << std::endl;

	//// Show stats
	//std::cout << "\nShowing statistics of the tree #1...\n";
	//std::cout << "Maximum: " << tree1.maximum() << std::endl;
	//std::cout << "Minimum: " << tree1.minimum() << std::endl;

	// Show tree #1
	//std::cout << "Is it empty:\t" << tree1.empty() << std::endl;
	//printTree(tree1);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}