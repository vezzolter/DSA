// Radix Sort
// by vezzolter
// July 15, 2024
//
// This C++ project demonstrates the simplified implementation of a radix sort algorithm. 
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include "RadixSort.h"


void printArray(const int arr[], const int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Radix Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 328, 203, 703, 911, 200, 3, 7, 11 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	// Sort Elements
	std::cout << "\nSorting the elements of it...\n";
	radixSort(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}