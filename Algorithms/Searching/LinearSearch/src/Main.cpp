// Linear Search Implementation
// by vezzolter
// March 9, 2024
//
// This C++ project demonstrates the implementation of linear search algorithm.

#include <iostream>
#include "LinearSearch.h"


void printArray(int arr[], int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Linear Search' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Search the value
	std::cout << "\nSearching the value...\n";
	//linearSearch(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}