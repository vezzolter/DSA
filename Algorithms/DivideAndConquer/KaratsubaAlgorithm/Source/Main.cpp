// Karatsuba Algorithm
// by vezzolter
// September 16, 2024
//
// This C++ project illustrates the concept of Divide-and-Conquer 
// through a simplified implementation of the Karatsuba algorithm.



#include <iostream>
#include "KaratsubaAlgorithm.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Karatsuba Algorithm' console application!\n\n";

	// Demonstrate
	karatsuba();

	// Exit
	std::cout << "Thanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}