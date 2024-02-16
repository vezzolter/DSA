// Simplified ADT: Static Array
// by vezzolter
// January 29, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called static array.

#include <iostream>
#include "StaticArray.h"

void printArray(const SA<int, 100>& arr) {
	std::cout << "Elements:\t";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n";

	// Create initial array #1
	std::cout << "\nCreating & filling initial array #1...\n";
	SA<int, 100> arr1(9);
	for (int i = 0; i < 9; i++)
		arr1[i] = i + 1;
	
	// Show array #1
	std::cout << "Is it empty:\t" << arr1.empty() << std::endl;
	printArray(arr1);

	// Access elements
	std::cout << " - first:\t" << arr1.front() << std::endl;
	std::cout << " - middle:\t" << arr1[arr1.size() / 2] << std::endl;
	std::cout << " - last:\t" << arr1.back() << std::endl;

	// Modify array #1
	std::cout << "\nChange first ('1') and last ('9') element to '0'...\n";
	arr1[0] = arr1[arr1.size() - 1] = 0;
	printArray(arr1);

	// Copy functionality
	std::cout << "\nCreate an array copies and compare...\n";
	SA<int, 100> arr2(arr1);
	SA<int, 100> arr3 = arr1;
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}