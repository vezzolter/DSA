// Title:   Static Array Container
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "StaticArray.h"


void printArray(const SA& arr) {
	for (auto it = arr.cbegin(); it != arr.cend(); ++it) { 
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> SA a1:\t\t\t\t";
	SA a1;
	for (int i = 0; i < 10; ++i) { a1[i] = i; }
	printArray(a1);
	std::cout << " -> SA a2(a1):\t\t\t\t";
	SA a2(a1);
	printArray(a2);
	std::cout << " -> SA a3 = a1:\t\t\t\t";
	SA a3 = a1;																																																																																																									
	printArray(a3);
	std::cout << std::endl;

	// Helper Iterators
	SA::iterator it = a1.begin();
	SA::iterator last = it;
	for (; it != a1.end(); ++it) { last = it; }

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
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << " -> a3.fill(3):\t\t\t\t";
	a3.fill(3);
	printArray(a3);
	std::cout << " -> a2.fill(a3.begin(), a3.end()):\t";
	a2.fill(a3.begin(), a3.end());
	printArray(a2);
	std::cout << " -> a1.swap(a2):\t\t\t";
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