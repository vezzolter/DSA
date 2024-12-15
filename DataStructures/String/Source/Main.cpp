// Title:   String Container
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Str.h"


void printString(const Str& str) {
	//for (auto x : str) { std::cout << x << " "; }
	for (auto it = str.cbegin(); it != str.cend(); ++it) {
		std::cout << *it << " ";
	}
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
	std::cout << std::endl;

	// Capacity
	std::cout << "Capacity:\n";
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