// Factorial (Recursive)
// by vezzolter
// November 13, 2023
//
// This C++ project demonstrates the simplified implementation of an algorithm
// for computation of factorials using the recursive problem-solving approach.


#include <iostream>
#include "Factorial.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Factorial (Recursive)' console application!\n";

	// Specify the number 
	std::cout << "\nSpecify the number (0-12): ";
	int n = 0;
	std::cin >> n;

	// Compute and display result
	std::cout << "The factorial of " << n << " equals to " << factorial(n) << ".\n";
	
	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}