// Middle-Square Method Simplified Implementation
// by vezzolter
// March 21, 2024
//
// This C++ project demonstrates the simplified implementation of a 
// random number generation using the PRNG named Middle-Square Method.

#include <iostream>
#include "MiddleSquareMethod.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Middle-Square Method' console application!\n\n";

	//// Preliminaries for testing
	//int numbers = 100;
	//int digits = 5;
	//int seed = 12345;

	// Prompt user for input
	std::cout << "Specify the amount of numbers to generate: ";
	int numbers = 0;
	std::cin >> numbers;
	std::cout << "Specify the amount of digits in numbers: ";
	int digits = 0;
	std::cin >> digits;
	std::cout << "Specify the seed for generation: ";
	int seed = 0;
	std::cin >> seed;

	// Generate random numbers
	std::cout << "\nGenerating " << numbers << " random " << digits << "-digit numbers...\n";
	for (int i = 0; i < numbers; ++i) {
		int randomNumber = middleSquareMethod(seed, digits);
		std::cout << " " << i + 1 << ":\t" << randomNumber << std::endl;
		seed = randomNumber; // Step 4: Use extracted digits as the new seed value.
	}
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}