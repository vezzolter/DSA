// Static Array
// by vezzolter
// January 29, 2024
//
// This C++ project demonstrates the simplified implementation of a static array container. 
// It aims to illustrate basic array operations and memory handling in a fixed-size context.


#include <iostream>
#include <array>
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
	SA arr1;
	for (int i = 0; i < 9; ++i) { arr1[i] = i + 1; }
	std::cout << "Constructors:\n";
	std::cout << " - default:\t";
	printArray(arr1);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " - operator[3]:\t" << arr1[3] << std::endl;
	std::cout << " - front():\t" << arr1.front() << std::endl;
	std::cout << " - back():\t" << arr1.back() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " - empty():\t" << arr1.empty() << std::endl;
	std::cout << " - size():\t" << arr1.size() << std::endl;
	std::cout << std::endl;

	// Operations
	//std::cout << "Operations:\n";
	//std::cout << " - assign():\t" << arr1.assign() << std::endl;
	//std::cout << " - swap():\t" << arr1.swap() << std::endl;
	//std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}