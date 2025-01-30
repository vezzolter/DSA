// Title:   Euclidean Algorithm (Recursive)
// Authors: by vezzolter
// Date:    January 28, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "EuclideanAlgorithm.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Euclidean Algorithm (Recursive)' console application!\n";

	// Enter the numbers
	std::cout << "\nEnter the first number (a): \t\t";
	int a = 0;
	std::cin >> a;
	std::cout << "Enter the second number (b): \t\t";
	int b = 0;
	std::cin >> b;

	// Compute and display the result
	std::cout << "The GCD of " << a << " and " << b << " is: \t\t" << euclidean(a, b) << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}