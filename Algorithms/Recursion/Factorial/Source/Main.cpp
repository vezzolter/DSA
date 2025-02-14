// Title:   Factorial Algorithm (Recursive)
// Authors: by vezzolter
// Date:    November 13, 2023
// ----------------------------------------------------------------------------


#include <iostream>
#include "Factorial.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Factorial' console application!\n";

	// Prompt the user for input
	std::cout << "\nEnter the number (0-12):\t";
	int n = 0;
	std::cin >> n;

	// Compute and display the result
	std::cout << "The factorial of it:\t\t" << factorial(n) << "\n";
	
	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}