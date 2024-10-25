// Title:   Bucket Sort Algorithm
// Authors: by vezzolter
// Date:    August 3, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include <vector>
#include "BucketSort.h"


void printArray(const std::vector<int>& arr) {
	std::cout << "Elements:\t";
	for (const int& element : arr) { std::cout << element << " "; }	
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Bucket Sort' console application!\n";

	// Create initial array
	std::cout << "\nCreating the initial array...\n";
	std::vector<int> arr = { 7, 2, 0, 0, 3, 1, 9, 1 };
	printArray(arr);

	// Sort elements
	std::cout << "\nSorting the elements of it...\n";
	bucketSort(arr);
	printArray(arr);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}