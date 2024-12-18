// Title:   String Container
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Str.h"

#include <string>


void printString(const Str& str) {
	//for (auto x : str) { std::cout << x << " "; }
	for (auto it = str.cbegin(); it != str.cend(); ++it) { std::cout << *it << " "; }
	std::cout << std::endl;
}

int main() {
	// Greet
	std::cout << "\tWelcome to the 'String Container' console application!\n\n";

	// Constructors
	std::cout << "Constructors:\n";
	std::cout << " -> Str s1(const char*):\t\t";
	const char* test = "Hello!";
	Str s1(test);
	printString(s1);
	std::cout << " -> Str s2(s1):\t\t\t\t";
	Str s2(s1);
	printString(s2);
	std::cout << " -> Str s3 = s1:\t\t\t";
	Str s3 = s1;
	printString(s3);
	std::cout << std::endl;

	// Element Access
	std::cout << "Element Access:\n";
	std::cout << " -> s1.operator[1]:\t\t\t" << s1[1] << std::endl;
	std::cout << " -> s1.front():\t\t\t\t" << s1.front() << std::endl;
	std::cout << " -> s1.back(): \t\t\t\t" << s1.back() << std::endl;
	std::cout << " -> s1.data(): \t\t\t\t" << s1.data() << std::endl;
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
	std::cout << " -> s1.empty():\t\t\t\t" << s1.empty() << std::endl;
	std::cout << " -> s1.size(): \t\t\t\t" << s1.size() << std::endl;
	std::cout << " -> s1.capacity(): \t\t\t" << s1.capacity() << std::endl;
	std::cout << " -> s1.reserve(20): \t\t\t\t" << std::endl;
	s1.reserve(20);
	std::cout << "   - s1.capacity(): \t\t\t" << s1.capacity() << std::endl;
	std::cout << " -> s1.shrinkToFit() \t\t\t\t" << std::endl;
	s1.shrinkToFit();
	std::cout << "   - s1.capacity(): \t\t\t" << s1.capacity() << std::endl;
	std::cout << std::endl;

	// Modifiers
	std::cout << "Modifiers:\n";
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}