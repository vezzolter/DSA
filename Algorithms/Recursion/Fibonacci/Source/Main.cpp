// Fibonacci Sequence (Recursive)
// by vezzolter
// January 24, 2024
//
// This C++ project demonstrates the simplified implementation of an algorithm
// for computation of fibonacci sequence using the recursive problem-solving approach.


#include <iostream>
#include "Fibonacci.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Fibonacci Sequence (Recursive)' console application!\n";

	// Specify the number
	std::cout << "\nSpecify the element (0-45): "; 
	int n = 0;
	std::cin >> n;

	// Compute and display result
	std::cout << "The Fibonacci value for element '" << n << "' is " << fibonacci(n) << ".\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}