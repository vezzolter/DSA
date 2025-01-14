// Title:   Binary Search Tree Container
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "BST.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Search Tree' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> BST t1:\t\t\t\t";
	BST t1;
	std::cout << std::endl;
	std::cout << " -> BST t2(t1):\t\t\t\t";
	BST t2(t1);
	std::cout << std::endl;
	std::cout << " -> DLL t3 = t1:\t\t\t";
	BST t3 = t1;
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}