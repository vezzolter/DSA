// Title:   String Container
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Str.h"


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
	std::cout << " -> s1.insert(s1.end(), 'x'): \t\t";
	s1.insert(s1.end(), 'x');
	printString(s1);
	std::cout << " -> s1.erase(--s1.end()): \t\t";
	s1.erase(--s1.end());
	printString(s1);
	std::cout << " -> s1.pushBack('x'): \t\t\t";
	s1.pushBack('x');
	printString(s1);
	std::cout << " -> s1.popBack(): \t\t\t";
	s1.popBack();
	printString(s1);
	std::cout << " -> s1.assign(9, 'x'): \t\t\t";
	s1.assign(9, 'x');
	printString(s1);
	std::cout << " -> s1.assign(s2.begin(), s2.end()):    ";
	s1.assign(s2.begin(), s2.end());
	printString(s1);
	std::cout << " -> s1.clear(): \t\t\t";
	s1.clear();
	printString(s1);
	std::cout << " -> s1.resize(5): \t\t\t";
	s1.resize(5);
	printString(s1);
	std::cout << " -> s1.resize(10, 'x'): \t\t";
	s1.resize(10, 'x');
	printString(s1);
	std::cout << " -> s1.swap(s2): \t\t\t";
	s1.swap(s2);
	printString(s1);
	std::cout << "   - s2:\t\t\t\t";
	printString(s2);
	std::cout << "   - s3:\t\t\t\t";
	printString(s3);
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}