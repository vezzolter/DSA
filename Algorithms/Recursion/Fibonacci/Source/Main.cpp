// Title:   Fibonacci Sequence Algorithm (Recursive)
// Authors: by vezzolter
// Date:    January 24, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Fibonacci.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Fibonacci Sequence' console application!\n";

	// Specify the number
	std::cout << "\nSpecify the sequence element (0-45): "; 
	int n = 0;
	std::cin >> n;

	// Compute and display result
	std::cout << "The Fibonacci value for it: " << fibonacci(n) << ".\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}