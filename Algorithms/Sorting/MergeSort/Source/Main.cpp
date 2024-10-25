// Title:   Merge Sort Algorithm
// Authors: by vezzolter
// Date:    March 31, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "MergeSort.h"


void printArray(const int* arr, const int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++) { std::cout << arr[i] << " "; }
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Merge Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 7, 2, 0, 3, 1, 9, 1 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	// Sort elements
	std::cout << "\nSorting the elements of it...\n";
	mergeSort(arr, 0, size - 1);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}