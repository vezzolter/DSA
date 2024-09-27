// Source file Factorial
// by vezzolter
// November 13, 2023


#include "Factorial.h"


int factorial(int n) {
	if (n == 0 || n == 1) { return 1; } // Base case
	return n * factorial(n - 1); // Recursive case
}