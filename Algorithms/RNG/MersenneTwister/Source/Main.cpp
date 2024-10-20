// Mersenne Twister
// by vezzolter
// September 7, 2024
//
// This C++ project demonstrates the simplified implementation of a 
// random number generation using the PRNG named Mersenne Twister


#include <iostream>
#include "MersenneTwister.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Mersenne Twister' console application!\n\n";

	// Prompt user for input
	std::cout << "Specify the amount of numbers to generate: ";
	int numbers = 0;
	std::cin >> numbers;
	std::cout << "Specify the minimum value: ";
	int minVal = 0;
	std::cin >> minVal;
	std::cout << "Specify the maximum value: ";
	int maxVal = 0;
	std::cin >> maxVal;

	// Generate random numbers within the user-defined range
	MersenneTwister mt(1234);
	std::cout << "\nGenerating " << numbers << " random numbers between " << minVal << " and " << maxVal << "...\n";
	for (int i = 0; i < numbers; i++) {
		uint32_t randomNumber = minVal + (mt.generate() % (maxVal - minVal + 1));
		std::cout << " " << i + 1 << ":\t" << randomNumber << std::endl;
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