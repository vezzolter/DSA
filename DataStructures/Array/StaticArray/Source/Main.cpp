// Title:   Static Array Container
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "StaticArray.h"


// Utilizes non-const array, since there is no const iterator
void printArray(SA& arr) {
	for (auto it = arr.begin(); it != arr.end(); ++it) { 
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> SA arr1:\t\t";
	SA arr1;
	for (int i = 0; i < 10; ++i) { arr1[i] = i; }
	printArray(arr1);
	std::cout << " -> SA arr2(arr1):\t";
	SA arr2(arr1);
	printArray(arr2);
	std::cout << " -> SA arr3 = arr1:\t";
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
	std::cout << " -> arr1.assign(5):\t";
	arr1.assign(5);
	printArray(arr1);
	std::cout << " -> arr1.swap(arr2):\t";
	arr1.swap(arr2);
	printArray(arr1);
	std::cout << "   - arr2:\t\t";
	printArray(arr2);
	std::cout << "   - arr3:\t\t";
	printArray(arr3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}