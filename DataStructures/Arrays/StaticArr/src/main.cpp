// Simplified ADT: Static Array
// by vezzolter
// January 29, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called static array.

#include <iostream>
#include "StaticArray.h"


int main()
{
	// Greetings
	std::cout << "Welcome to the 'Static Array' console application!\n\n";

	// Create the array with 10 uninitialized elements
	StaticArr myArr(10);

	// Fill the array with numbers (0-10)
	for (int i = 0; i < 10; i++)
		myArr[i] = i + 1;

	// Display the array
	std::cout << "Array: ";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Showcase of the capacity
	if (myArr.isEmpty()) { std::cout << "The array is empty. It has " << myArr.size() << " elements.\n"; }
	else { std::cout << "The array is not empty. It has " << myArr.size() << " elements.\n"; }

	// Showcase of the element access
	std::cout << "First elements is: " << myArr.front() << std::endl;
	std::cout << "Second elements is: " << myArr[1] << std::endl;
	std::cout << "Last elements is: " << myArr.back() << std::endl;

	// Showcase of the operations
	myArr.fill(1);
	std::cout << "Filling the array with 1: ";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}