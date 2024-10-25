// Title:   Factorial Algorithm (Recursive)
// Authors: by vezzolter
// Date:    November 13, 2023
// ----------------------------------------------------------------------------


#include <iostream>
#include "Factorial.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Factorial' console application!\n";

	// Specify the number 
	std::cout << "\nSpecify the number (0-12): ";
	int n = 0;
	std::cin >> n;

	// Compute and display result
	std::cout << "The factorial of it: " << factorial(n) << ".\n";
	
	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}