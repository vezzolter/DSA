// Source file for recursive implementation of the fibonacci sequence as function.
// by vezzolter
// January 24, 2024

#include "fibonacci.h"

// Takes the number of an element within specified range and returns its Fibonacci Number.
// The range limit is dictated by the size of data type in order to prevent overflow.
// Note: to prioritize simplicity and highlight algorithm itself, 'int' is picked as data type.
int fibonacci(int n)
{
	if (n <= 1) { return n; } // Base case
	else { return fibonacci(n - 1) + fibonacci(n - 2); } // Recursive case

}