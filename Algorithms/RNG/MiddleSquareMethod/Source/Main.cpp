// Title:   Middle-Square Method Algorithm
// Authors: by vezzolter
// Date:    March 21, 2024
// ----------------------------------------------------------------------------


#include <iostream>
#include "MiddleSquareMethod.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Middle-Square Method' console application!\n\n";

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
	std::cout << "\nGenerating " << n << " random numbers between "  << minVal << " and " << maxVal << ":\n";
	for (int i = 0; i < n; ++i) {
		int randomNumber = minVal + (middleSquareMethod() % (maxVal - minVal + 1));
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