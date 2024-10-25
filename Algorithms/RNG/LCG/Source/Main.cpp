// Title:   LCG Algorithm (Linear Congruential Generator)
// Authors: by vezzolter
// Date:    August 28, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "LCG.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'LCG' console application!\n\n";

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
	std::cout << "\nGenerating " << numbers << " random numbers between "
		<< minVal << " and " << maxVal << "...\n";
	for (int i = 0; i < numbers; i++) {
		int randomNumber = minVal + (lcg() % (maxVal - minVal + 1));
		std::cout << " " << i + 1 << ":\t" << randomNumber << std::endl;
	}	
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}