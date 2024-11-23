// Title:   Dynamic Array Container
// Authors: by vezzolter
// Date:    January 31, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "DynamicArray.h"


void printArray(const DA& arr) {
	for (auto it = arr.cbegin(); it != arr.cend(); ++it) { 
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Dynamic Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> DA a1:\t\t\t\t";
	DA a1;
	for (int i = 0; i < 10; ++i) { a1.pushBack(i); } // 5 allocations
	printArray(a1);
	std::cout << " -> DA a2(a1):\t\t\t\t";
	DA a2(a1);
	printArray(a2);
	std::cout << " -> DA a3 = a1:\t\t\t\t";
	DA a3 = a1;
	printArray(a3);
	std::cout << std::endl;

	// Helper Iterators
	DA::iterator it = a1.begin();
	//DA::iterator last = it;
	//for (; it != a1.end(); ++it) { last = it; }
	//for (int i = 0; i < 6; ++i) { last++; }

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> a1.operator[3]:\t\t\t" << a1[3] << std::endl;
	std::cout << " -> a1.front():\t\t\t\t" << a1.front() << std::endl;
	std::cout << " -> a1.back(): \t\t\t\t" << a1.back() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> a1.empty():\t\t\t\t" << a1.empty() << std::endl;
	std::cout << " -> a1.size(): \t\t\t\t" << a1.size() << std::endl;
	std::cout << " -> a1.capacity(): \t\t\t" << a1.capacity() << std::endl;
	std::cout << " -> a1.reserve(20): \t\t\t\t" << std::endl;
	a1.reserve(20);
	std::cout << "   - a1.capacity(): \t\t\t" << a1.capacity() << std::endl;
	std::cout << " -> a1.shrinkToFit() \t\t\t\t" << std::endl;
	a1.shrinkToFit();
	std::cout << "   - a1.capacity(): \t\t\t" << a1.capacity() << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> a1.insert(unidentified, 3): \t\t\t";
	a1.insert(it, 3);
	printArray(a1);
	//std::cout << " -> a1.erase(--itrTo9): \t\t\t";
	//a1.erase(last);
	//printArray(a1);
	std::cout << " -> a1.pushBack(3): \t\t\t";
	a1.pushBack(3);
	printArray(a1);
	std::cout << " -> a1.popBack(): \t\t\t";
	a1.popBack();
	printArray(a1);
	std::cout << " -> a1.assign(5, 3): \t\t\t";
	a1.assign(5, 3);
	printArray(a1);
	std::cout << " -> a1.assign(a2.begin(), a2.end()):    ";
	a1.assign(a2.begin(), a2.end());
	printArray(a1);
	std::cout << " -> a1.clear(): \t\t\t";
	a1.clear();
	printArray(a1);
	std::cout << " -> a1.resize(5): \t\t\t";
	a1.resize(5);
	printArray(a1);
	std::cout << " -> a1.resize(10, 3): \t\t\t";
	a1.resize(10, 3);
	printArray(a1);
	std::cout << " -> a1.swap(arr2): \t\t\t";
	a1.swap(a2);
	printArray(a1);
	std::cout << "   - a2:\t\t\t\t";
	printArray(a2);
	std::cout << "   - a3:\t\t\t\t";
	printArray(a3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}