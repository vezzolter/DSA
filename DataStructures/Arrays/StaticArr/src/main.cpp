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

	// Create the array with 10 elements
	StaticArr myArr(10);

	// Display the array
	std::cout << "Initial array:\t";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Fill the array with numbers (0-10)
	for (int i = 0; i < 10; i++)
		myArr[i] = i + 1;

	// Display the array
	std::cout << "Filled array:\t";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Showcase of the capacity
	if (!myArr.empty())
	{
		std::cout << "\nAs long as, the array has " << myArr.size() << " elements, we can name:\n";


		// Showcase of the element access
		std::cout << " - first element:\t" << myArr.front() << std::endl;
		std::cout << " - next element:\t" << myArr[1] << std::endl;
		std::cout << " - last element:\t" << myArr.back() << std::endl;
	}

	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}