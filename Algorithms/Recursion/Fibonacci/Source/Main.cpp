// Title:   Fibonacci Sequence Algorithm (Recursive)
// Authors: by vezzolter
// Date:    January 24, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "Fibonacci.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Fibonacci Sequence' console application!\n";

	// Prompt the user for input
	std::cout << "\nEnter the sequence index (0-45): "; 
	int n = 0;
	std::cin >> n;

	// Compute and display the result
	std::cout << "The Fibonacci value for it:\t " << fibonacci(n) << "\n";

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}