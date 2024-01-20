// Source file for recursive implementation of the factorial function.
// by vezzolter
// November 13, 2023

#include "factorial.h"

// Takes non-negative number within specified range and returns its factorial
// The range limit is dictated by the size of data type in order to prevent overflow.
// e.g. int var can't contain the factorial of 13, the number is too big.
// Note: to prioritize simplicity and highlight algorithm itself, 'int' is picked as data type.
int factorial(int n)
{
	if (n == 0) { return 1; } // Base case
	else { return (n * factorial(n - 1)); }; // Recursive case
}