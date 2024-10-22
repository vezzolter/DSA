// Dynamic Array
// by vezzolter
// January 31, 2024
//
// This C++ project demonstrates the simplified implementation of a dynamic array container. 
// It aims to illustrate basic array operations and memory handling in a runtime context


#include <iostream>
#include "DynamicArray.h"


void printArray(const DA& arr) {
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Dynamic Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> default constructor (arr1):\t";
	DA arr1;
	for (int i = 1; i < 10; ++i) { arr1.pushBack(i); }
	printArray(arr1);
	std::cout << " -> copy constructor (arr2):\t";
	DA arr2(arr1);
	printArray(arr2);
	std::cout << " -> copy operator= (arr3):\t";
	DA arr3 = arr1;
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
	std::cout << " -> arr1.capacity(): \t" << arr1.capacity() << std::endl;
	//std::cout << " -> arr1.reserve(): \t" << arr1.reserve() << std::endl;
	//std::cout << " -> arr1.shrinkToFit(): \t" << arr1.shrinkToFit() << std::endl;
	std::cout << std::endl;

	// Operations
	std::cout << "Operations:\n";
	//std::cout << " -> arr1.insert(): \t" << arr1.insert() << std::endl;
	//std::cout << " -> arr1.pushBack(): \t" << arr1.pushBack() << std::endl;
	//std::cout << " -> arr1.popBack(): \t" << arr1.popBack() << std::endl;
	//std::cout << " -> arr1.erase(): \t" << arr1.erase() << std::endl;
	//std::cout << " -> arr1.clear(): \t" << arr1.clear() << std::endl;
	//std::cout << " -> arr1.assign():\t" << arr1.assign() << std::endl;
	//std::cout << " -> arr1.swap(): \t" << arr1.swap() << std::endl;
	//std::cout << " -> arr1.resize(): \t" << arr1.resize() << std::endl;
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}