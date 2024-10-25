// Title:   Karatsuba Algorithm (Base of 10)
// Authors: by vezzolter
// Date:    September 16, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "KaratsubaAlgorithm.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Karatsuba Algorithm' console application!\n\n";

	// Specify numbers
	std::cout << "Number #1 to multiply: ";
	unsigned long long a = 0;
	std::cin >> a;
	std::cout << "Number #2 to multiply: ";
	unsigned long long b = 0;
	std::cin >> b;

	// Demonstrate
	std::cout << "Result: " << karatsuba(a, b) << std::endl << std::endl;

	// Exit
	std::cout << "Thanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}