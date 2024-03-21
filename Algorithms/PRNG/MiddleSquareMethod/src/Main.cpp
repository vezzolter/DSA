// Middle-Square Method Implementation
// by vezzolter
// March 21, 2024
//
// This C++ project demonstrates the simplified implementation of a Middle-Square Method PRNG.

#include <iostream>
#include "MiddleSquareMethod.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Middle-Square Method' console application!\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}