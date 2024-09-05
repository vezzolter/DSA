// Merge Sort
// by vezzolter
// March 31, 2024
//
// This C++ project demonstrates the simplified implementation of a Merge Sort algorithm. 
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include "MergeSort.h"


void printArray(const int* arr, const int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Merge Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 7, 2, 0, 3, 1, 9, 1 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	// Sort Elements
	std::cout << "\nSorting the elements of it...\n";
	mergeSort(arr, 0, size - 1);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}