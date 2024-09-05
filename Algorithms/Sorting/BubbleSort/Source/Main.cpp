// Bubble Sort
// by vezzolter
// February 25, 2024
//
// This C++ project demonstrates the implementation of bubble sort algorithm.
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include "BubbleSort.h"


void printArray(int arr[], int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Bubble Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[1]);
	printArray(arr, size);

	// Sort Elements
	std::cout << "\nSorting the elements of it...\n";
	bubbleSort(arr, size);
	printArray(arr, size);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
