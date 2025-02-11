// Title:   Xorshift32 Algorithm
// Authors: by vezzolter
// Date:    February 3, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "Xorshift32.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Xorshift32' console application!\n\n";

	// Prompt the user for input
	std::cout << "Enter the number of random numbers: ";
	int n = 0;
	std::cin >> n;
	std::cout << "Enter the minimum value:\t    ";
	int minVal = 0;
	std::cin >> minVal;
	std::cout << "Enter the maximum value:\t    ";
	int maxVal = 0;
	std::cin >> maxVal;

	// Generate random numbers within the user-defined range
	Xorshift32 prng(1234);
	std::cout << "\nGenerating " << n << " random numbers between " << minVal << " and " << maxVal << ":\n";
	for (int i = 0; i < n; ++i) {
		uint32_t randomNumber = minVal + (prng.generate() % (maxVal - minVal + 1));
		std::cout << " " << i + 1 << ":\t" << randomNumber << std::endl;
	}
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}