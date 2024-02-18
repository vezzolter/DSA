// Insertion Sort Implementation
// by vezzolter
// February 18, 2024
//
// This C++ project demonstrates the implementation of insertion sort algorithm.

#include <iostream>
#include "InsertionSort.h"


int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Insertion Sort' console application!\n";

	// Create initial array
	std::cout << "\nGenerating initial array...\n";
	insertionSort();

	// Sort Elements
	std::cout << "\nSorting it...\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
