// Title:   Linear Search Algorithm
// Authors: by vezzolter
// Date:    March 9, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "LinearSearch.h"


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
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Linear Search' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);
	
	// Specify the target 
	std::cout << "\nSpecify the target: ";
	int t = 0;
	std::cin >> t;

	// Search for the value
	std::cout << "\nSearching the element '" << t << "'..." << std::endl;
	int i = linearSearch(arr, size, t);
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