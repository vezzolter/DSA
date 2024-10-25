// Title:   Binary Search Algorithm
// Authors: by vezzolter
// Date:    March 17, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include "BinarySearch.h"


void printArray(int arr[], int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++) {
		std::cout << std::setw(3) << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Indices:\t";
	for (int i = 0; i < size; i++) {
		std::cout << std::setw(3) << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Binary Search' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 0, 2, 2, 3, 4, 6, 7, 9, 10, 12, 13, 14, 15, 19, 19 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Specify the target 
	std::cout << "\nSpecify the target: ";
	int t = 0;
	std::cin >> t;

	// Search for the value
	std::cout << "\nSearching the element '" << t << "'..." << std::endl;
	int i = binarySearch(arr, 0, size - 1, t);
	if (i != -1) {
		std::cout << "Element '" << t << "' found at index '" << i << "'.\n";
	} else {
		std::cout << "Element '" << t << "' not found.\n";
	}

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}