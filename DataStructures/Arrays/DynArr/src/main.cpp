// Simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024
//
// This C++ project demonstrates the implementation of the
// simplified version of abstract data type called dynamic array.

#include <iostream>
#include "DynamicArray.h"

int main()
{
	// Greetings
	std::cout << "Welcome to the 'Dynamic Array' console application!\n\n";

	// Showcase default constructor
	DynArr arr_1;

	// Fill the array with numbers (0-10)
	for (int i = 0; i < 10; i++)
		arr_1.insert(i, i+1);

	// Display the array
	std::cout << "Array #1: ";
	for (int i = 0; i < arr_1.size(); i++)
		std::cout << arr_1[i] << " ";
	std::cout << std::endl;

	// Showcase of the element access
	std::cout << "First elements is: " << arr_1.front() << std::endl;
	std::cout << "Second elements is: " << arr_1[1] << std::endl;
	std::cout << "Last elements is: " << arr_1.back() << std::endl;
	std::cout << std::endl;

	// Showcase of the capacity
	if (!arr_1.empty())
	{
		std::cout << "As long as array is not empty (it has " << arr_1.size() << " elements).\n";
		arr_1.resize(15);
		std::cout << "We can resize it to " << arr_1.size() << " elements.\n\n";
	}

	std::cout << "Additionally, we can copy initial array and shorten them:\n";
	// Showcase copy constructor
	DynArr arr_2(arr_1);

	// Shorten an array #2 to 7 elements
	for (int i = arr_2.size() - 1; i >= 7; --i)
		arr_2.remove(i);

	// Display the array #2
	std::cout << "Array #2: ";
	for (int i = 0; i < arr_2.size(); i++)
		std::cout << arr_2[i] << " ";
	std::cout << std::endl;

	// Showcase copy assignment
	DynArr arr_3;
	arr_3 = arr_1;

	// Shorten an array #3 to 3 elements
	for (int i = arr_3.size() - 1; i >= 3; --i)
		arr_3.remove(i);

	// Display the array
	std::cout << "Array #3: ";
	for (int i = 0; i < arr_3.size(); i++)
		std::cout << arr_3[i] << " ";
	std::cout << std::endl;


	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}