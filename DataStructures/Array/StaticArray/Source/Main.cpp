// Static Array
// by vezzolter
// January 29, 2024
//
// This C++ project demonstrates the simplified implementation of a static array container. 
// It aims to illustrate basic array operations and memory handling in a fixed-size context.


#include <iostream>
#include "StaticArray.h"


void printArray(const SA& arr) {
	std::cout << "Elements:\t";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n";

	// Constructors
	SA arr1(9);
	for (int i = 0; i < 9; i++) { arr1[i] = i + 1; }

	// Element Access
	std::cout << "Element Access:\n";
	//std::cout << "at():\t" << arr1.at() << std::endl;
	std::cout << " - operator[3]:\t" << arr1[3] << std::endl;
	std::cout << " - front():\t" << arr1.front() << std::endl;
	std::cout << " - back():\t" << arr1.back() << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " - empty():\t" << arr1.empty() << std::endl;
	std::cout << " - size():\t" << arr1.size() << std::endl;

	// Operations
	//std::cout << "Operations:\n";
	//std::cout << " - assign():\t" << arr1.assign() << std::endl;
	//std::cout << " - swap():\t" << arr1.swap() << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}