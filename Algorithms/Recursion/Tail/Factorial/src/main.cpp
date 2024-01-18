// Tail-Recursive Factorial
// by vezzolter
// November 13, 2023
//
// This C++ project demonstrates the implementation of the
// factorial function using tail recursion.

#include "factorialTail.h"
#include <iostream>


// Asks user to enter a non-negative number within specified range and validates the input.
// The range limit is dictated by the size of data type in order to prevent overflow.
// e.g. int var can't contain the factorial of 13, the number is too big.
// Note: to prioritize simplicity and highlight algorithm itself, 'int' is picked as data type.
int getUserInput()
{
	int n = 0;

	while (true)
	{
		std::cout << "Enter your number between 0 and 12: ";
		std::cin >> n;

		if (std::cin.fail() || n < 0 || n > 12)
		{
			std::cin.clear(); // ensure that stream is in a good state
			std::cin.ignore(32767, '\n'); // clear from any remaining chars
			std::cout << "Error: invalid input. Please try again.\n\n"; // inform
		}
		else { break; }
	}

	return n;
}

int main()
{
	// Greetings
	std::cout << "Welcome to the 'Tail-Recursive Factorial' console application!\n\n";

	// Input
	int n = 0;
	n = getUserInput();

	// Result
	std::cout << "The factorial of " << n << " equals to " << factorialTail(n) << ".\n";
	
	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}