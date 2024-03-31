// Merge Sort
// by vezzolter
// March 31, 2024
//
// This C++ project demonstrates the simplified implementation of a merge sort algorithm. 
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include "MergeSort.h"


void printArray(int arr[], int size) {
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
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Sort Elements
	std::cout << "\nSorting the elements of it...\n";
	mergeSort(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}