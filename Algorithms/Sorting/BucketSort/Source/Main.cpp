// Bucket Sort
// by vezzolter
// August 03, 2024
//
// This C++ project demonstrates the simplified implementation of a Bucket Sort algorithm. 
// It illustrates the concept via utilizing a small array of integers as the collection.


#include <iostream>
#include <vector>

#include "BucketSort.h"


void printArray(const std::vector<int>& arr) {
	std::cout << "Elements:\t";
	for (const int& element : arr)
		std::cout << element << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Bucket Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	std::vector<int> arr = { 7, 2, 0, 0, 3, 1, 9, 1 };
	printArray(arr);

	// Sort Elements
	std::cout << "\nSorting the elements of it...\n";
	bucketSort(arr);
	printArray(arr);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}