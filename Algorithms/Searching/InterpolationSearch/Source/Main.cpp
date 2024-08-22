// Interpolation Search
// by vezzolter
// August 22, 2024
//
// This C++ project demonstrates the simplified implementation of a interpolation search algorithm
// illustrated with an example using a small static array of integers as the collection.


#include <iostream>
#include <iomanip>
#include "InterpolationSearch.h"


void printArray(int arr[], int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << std::setw(3) << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Indices:\t";
	for (int i = 0; i < size; i++)
		std::cout << std::setw(3) << i << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Interpolation Search' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 0, 2, 2, 3, 4, 6, 7, 9, 10, 12, 13, 14, 15, 19, 19 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Specify the target 
	std::cout << "\nSpecify the target: ";
	int target = 0;
	std::cin >> target;

	// Search the value
	std::cout << "\nSearching the index of an element '" << target << "'..." << std::endl;
	int index = interpolationSearch(arr, target);
	if (index != -1)
		std::cout << "Element '" << target << "' found at index '" << index << "'.\n";
	else
		std::cout << "Element '" << target << "' not found.\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}