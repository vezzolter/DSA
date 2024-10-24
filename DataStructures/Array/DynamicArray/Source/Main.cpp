// Title:   Dynamic Array Container
// Authors: by vezzolter
// Date:    January 31, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "DynamicArray.h"


// Utilizes non-const array, since there is no const iterator
void printArray(DA& arr) {
	for (auto it = arr.begin(); it != arr.end(); ++it) { 
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Dynamic Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> DA arr1:\t\t";
	DA arr1;
	for (int i = 0; i < 10; ++i) { arr1.pushBack(i); } // 5 allocations
	printArray(arr1);
	std::cout << " -> DA arr2(arr1):\t";
	DA arr2(arr1);
	printArray(arr2);
	std::cout << " -> DA arr3 = arr1:\t";
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
	std::cout << " -> arr1.reserve(20): \t" << std::endl;
	arr1.reserve(20);
	std::cout << "   - arr1.capacity(): \t" << arr1.capacity() << std::endl;
	std::cout << " -> arr1.shrinkToFit() \t" << std::endl;
	arr1.shrinkToFit();
	std::cout << "   - arr1.capacity(): \t" << arr1.capacity() << std::endl;
	std::cout << std::endl;

	// Operations
	std::cout << "Operations:\n";
	std::cout << " -> arr1.insert(10, 3): ";
	arr1.insert(10, 3);
	printArray(arr1);
	std::cout << " -> arr1.pushBack(3): \t";
	arr1.pushBack(3);
	printArray(arr1);
	std::cout << " -> arr1.popBack(): \t";
	arr1.popBack();
	printArray(arr1);
	std::cout << " -> arr1.erase(10): \t";
	arr1.erase(10);
	printArray(arr1);
	std::cout << " -> arr1.assign(5): \t";
	arr1.assign(5);
	printArray(arr1);
	std::cout << " -> arr1.clear(): \t";
	arr1.clear();
	printArray(arr1);
	std::cout << " -> arr1.resize(10): \t";
	arr1.resize(10);
	printArray(arr1);
	std::cout << " -> arr1.swap(arr2): \t";
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