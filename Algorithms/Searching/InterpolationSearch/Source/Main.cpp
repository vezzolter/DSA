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
	int arr[] = { 1, 1, 4, 7, 9, 11, 14, 17, 19, 19, 22, 25, 27, 30 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Specify the target 
	std::cout << "\nSpecify the target: ";
	int target = 0;
	std::cin >> target;

	// Search the value
	std::cout << "\nSearching the index of an element '" << target << "'..." << std::endl;
	int index = interpolationSearch(arr, size, target);
	if (index != -1)
		std::cout << "Element '" << target << "' is found at index '" << index << "'.\n";
	else
		std::cout << "Element '" << target << "' is not found.\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}