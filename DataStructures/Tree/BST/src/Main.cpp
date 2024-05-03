// Simplified ADT: Binary Search Tree
// by vezzolter
// April 29, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called Binary Search Tree

#include <iostream>
#include "BST.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Search Tree' console application!\n";

	// Create initial tree #1
	// Note: there is no balancing
	std::cout << "\nCreating & filling initial tree #1...\n";
	std::cout << "Using: 8, 4, 13, 2, 6, 10, 17, 0, 3, 7, 9, 11, 14\n";
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
	std::cout << "Success: BST has been created!\n";

	// Visualization is from markdown file
	//                  8
	//           /             \
	//         4                13
	//      /    \            /     \
	//     2      6         10        17
	//   /   \     \       /  \      /
	//  0     3     7     9   11   14

    // Show capacity
	std::cout << "\nShowing capacity methods...\n";
	std::cout << "Is it empty:\t" << (tree1.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Tree size:\t" << tree1.size() << std::endl;
	std::cout << "Height of '8':\t" << tree1.height(8) << std::endl;
	std::cout << "Depth of '8':\t" << tree1.depth(8) << std::endl;

	// Show stats
    std::cout << "\nShowing element access methods...\n";
	std::cout << "Is '14' present:\t" << (tree1.search(14) ? "Yes" : "No") << std::endl;
	std::cout << "Maximum element:\t" << tree1.maximum() << std::endl;
	std::cout << "Minimum element:\t" << tree1.minimum() << std::endl;
	std::cout << "Predecessor of '8':\t" << tree1.predecessor(8) << std::endl;
	std::cout << "Successor of '8':\t" << tree1.successor(8) << std::endl;
	
	// Show copy mechanics

	// Show removal

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	return 0;
}