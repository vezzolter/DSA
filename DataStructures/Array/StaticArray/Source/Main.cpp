// Static Array
// by vezzolter
// January 29, 2024
//
// This C++ project demonstrates the simplified implementation of a static array container. 
// It aims to illustrate basic array operations and memory handling in a fixed-size context.


#include <iostream>
#include "StaticArray.h"


// Not a const version
void printArray(SA& arr) {
	for (auto it = arr.begin(); it != arr.end(); ++it) { std::cout << *it << " "; }
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> default constructor (arr1):\t";
	SA arr1;
	printArray(arr1);
	std::cout << "   - manually updated (arr1):\t";
	for (int i = 0; i < 9; ++i) { arr1[i] = i + 1; }
	printArray(arr1);
	std::cout << " -> copy constructor (arr2):\t";
	SA arr2(arr1);
	printArray(arr2);
	std::cout << " -> copy operator= (arr3):\t";
	SA arr3 = arr1;
	printArray(arr3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> arr1.operator[3]:\t" << arr1[3] << std::endl;
	std::cout << " -> arr1.front():\t" << arr1.front() << std::endl;
	std::cout << " -> arr1.back(): \t" << arr1.back() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> arr1.empty():\t" << arr1.empty() << std::endl;
	std::cout << " -> arr1.size(): \t" << arr1.size() << std::endl;
	std::cout << std::endl;

	// Operations
	std::cout << "Operations:\n";
	std::cout << " -> arr2.assign(5), arr2:\t";
	arr2.assign(5);
	printArray(arr2);
	std::cout << " -> arr3.assign(7), arr3:\t";
	arr3.assign(7);
	printArray(arr3);
	std::cout << " -> arr2.swap(arr3):\n";
	arr2.swap(arr3);
	std::cout << "   - arr2 after swap:   \t";
	printArray(arr2);
	std::cout << "   - arr3 after swap:   \t";
	printArray(arr3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}