// LCG (Linear Congruential Generator)
// by vezzolter
// March 21, 2024
//
// This C++ project demonstrates the simplified implementation of a 
// random number generation using the PRNG named Linear Congruential Generator.


#include <iostream>
#include "LCG.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'LCG' console application!\n\n";

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
		int randomNumber = lcg();
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