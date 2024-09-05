// Heapsort
// by vezzolter
// June 1, 2024
//
// This C++ project demonstrates the simplified implementation of a Heapsort algorithm. 
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include "Heapsort.h"


void printArray(const int* arr, const int size) {
	std::cout << "Elements:\t";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
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
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}