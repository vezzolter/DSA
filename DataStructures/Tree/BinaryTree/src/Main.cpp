// Simplified ADT: Binary Tree
// by vezzolter
// April 20, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called Binary Tree.

#include <iostream>
#include "BinaryTree.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Tree' console application!\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}