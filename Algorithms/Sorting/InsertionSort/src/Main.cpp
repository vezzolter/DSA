// Insertion Sort Implementation
// by vezzolter
// February 18, 2024
//
// This C++ project demonstrates the implementation of insertion sort algorithm.

#include <iostream>
#include "InsertionSort.h"


void printArray(int arr[], int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Insertion Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating initial array...\n";
	int arr[] = { 4, 3, 5, 1, 2, 5 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Sort Elements
	std::cout << "\nSorting generated array...\n";
	insertionSort(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
