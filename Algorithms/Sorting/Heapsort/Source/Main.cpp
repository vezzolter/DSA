// Title:   Heapsort Algorithm
// Authors: by vezzolter
// Date:    June 1, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Heapsort.h"


void printArray(const int* arr, const int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++) { std::cout << arr[i] << " "; }
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Heapsort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 1, 7, 3, 2, 9, 0 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	// Sort elements
	std::cout << "\nSorting the elements of it...\n";
	heapsort(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}