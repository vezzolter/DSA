// Simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called dynamic array.

#include <iostream>
#include "DynamicArray.h"


void printArray(const DA<int>& arr) {
	std::cout << "Elements:\t";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Dynamic Array' console application!\n";

	// Create initial array #1
	std::cout << "\nCreating & filling initial array #1...\n";
	DA<int> arr1;
	for (int i = 0; i < 10; i++)
		arr1.pushBack(i);

	// Show array #1
	std::cout << "Is it empty:\t" << arr1.empty() << std::endl;
	printArray(arr1);

	// Modify array #1
	std::cout << "\nChange first ('1') and last ('10') element to '0'...\n";
	arr1[0] = arr1[arr1.size() - 1] = 0;
	printArray(arr1);

	// Deep copy functionality
	std::cout << "\nCreate an array copies and compare...\n";
	DA<int> arr2(arr1);
	DA<int> arr3 = arr1;
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Remove functionality
	std::cout << "\nShorten an array #2 to 7 elements, and #3 to 3 elements...\n";
	for (int i = arr2.size() - 1; i >= 7; --i)
		arr2.remove(i);
	for (int i = arr3.size() - 1; i >= 3; --i)
		arr3.remove(i);
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Clear
	std::cout << "\nClear array #2 and #3...\n";
	arr2.clear();
	arr3.clear();
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);
	std::cout << "Are they empty: ";
	std::cout << arr1.empty();
	std::cout << arr2.empty();
	std::cout << arr3.empty();
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}